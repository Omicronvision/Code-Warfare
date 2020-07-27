#pragma once

#include <vector>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>

#include <SFML/System/Vector2.hpp>

namespace sf
{
    class Font;
    class String;
    template <class T> class Rect;
    typedef Rect<float> FloatRect;
}

namespace sfe
{
struct TextStroke
{
    sf::Color fill = sf::Color::White;
    sf::Color outline = sf::Color::Transparent;
    float thickness = 0.f;
};

struct Outline
{
    sf::Color outline = sf::Color::Transparent;
    float thickness = 0.f;
};

class RichText : public sf::Drawable, public sf::Transformable
{
public:
    class Line : public sf::Transformable, public sf::Drawable
    {
    public:
        void setCharacterColor(std::size_t pos, sf::Color color);
        void setCharacterStyle(std::size_t pos, sf::Text::Style style);
        void setCharacter(std::size_t pos, sf::Uint32 character);
        void setCharacterSize(unsigned int size);
        void setFont(const sf::Font &font);
        std::size_t getLength() const;
        sf::Color getCharacterColor(std::size_t pos) const;
        sf::Uint32 getCharacterStyle(std::size_t pos) const;
        sf::Uint32 getCharacter(std::size_t pos) const;
        const std::vector<sf::Text> &getTexts() const;
        void appendText(sf::Text text);
        sf::FloatRect getLocalBounds() const;
        sf::FloatRect getGlobalBounds() const;

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::size_t convertLinePosToLocal(std::size_t &pos) const;
        void isolateCharacter(std::size_t pos);
        void updateGeometry() const;
        void updateTextAndGeometry(sf::Text &text) const;
        mutable std::vector<sf::Text> m_texts; ///< List of texts
        mutable sf::FloatRect m_bounds;        ///< Local bounds
    };
    RichText();
    RichText(const sf::Font &font);
    RichText & operator << (const TextStroke &stroke);
    RichText & operator << (const Outline &outline);
    RichText & operator << (const sf::Color &color);
    RichText & operator << (sf::Text::Style style);
    RichText & operator << (const sf::String &string);
    void setCharacterColor(std::size_t line, std::size_t pos, sf::Color color);
    void setCharacterStyle(std::size_t line, std::size_t pos, sf::Text::Style style);
    void setCharacter(std::size_t line, std::size_t pos, sf::Uint32 character);
    void setCharacterSize(unsigned int size);
    void setFont(const sf::Font &font);
    void clear();
    sf::Color getCharacterColor(std::size_t line, std::size_t pos) const;
    sf::Uint32 getCharacterStyle(std::size_t line, std::size_t pos) const;
    sf::Uint32 getCharacter(std::size_t line, std::size_t pos) const;
    const std::vector<Line> &getLines() const;
    unsigned int getCharacterSize() const;
    const sf::Font *getFont() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    RichText(const sf::Font *font);
    sf::Text createText(const sf::String &string) const;
    void updateGeometry() const;
    mutable std::vector<Line> m_lines; ///< List of lines
    const sf::Font *m_font;            ///< Font
    unsigned int m_characterSize;      ///< Character size
    mutable sf::FloatRect m_bounds;    ///< Local bounds
    TextStroke m_currentStroke;        ///< Last used stroke
    sf::Text::Style m_currentStyle;    ///< Last style used
};

}