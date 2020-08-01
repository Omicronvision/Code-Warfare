#include "Game.h"

Game::Game():
window(sf::VideoMode(1280, 720), "Code Warfare"),
b_paused(false)
{
	srand((dt::UInt32)time(NULL));
	//window settings
	window.setFramerateLimit(180);
}

void Game::run()
{
	while(window.isOpen())
	{
		processEvents();
		if (!b_paused)
			update();
		render();
	}
}

void Game::update()
{
	fpsclock.update();
	fpsclock.setPosition(view.view.getCenter().x - view.view.getSize().x / 2,
		view.view.getCenter().y - view.view.getSize().y / 2);
	switch(scenes.currentScene)
	{
	case Scenes::mainMenu:
		mainMenuScene.update();
		break;

	case Scenes::optionsMenu:
		optionsMenuScene.update();
		break;

	case Scenes::toolsMenu:
		toolsMenuScene.update();
		break;

	case Scenes::soloMenu:
		soloMenuScene.update();
		break;

	case Scenes::editorMenu:
		view.moveView();
		view.view.setCenter(view.crosshair.getPosition());
		editorScene.update(view.view.getCenter().x - view.view.getSize().x / 2,
			view.view.getCenter().y - view.view.getSize().y / 2);
		break;

	case Scenes::customMenu:
		break;

	case Scenes::map:
		view.moveView();
		view.view.setCenter(view.crosshair.getPosition());
		mapScene.update(view.view.getCenter().x - view.view.getSize().x / 2,
			view.view.getCenter().y - view.view.getSize().y / 2, window.getSize().x, window.getSize().y);
		break;
	}
	window.setView(view.view);
}

void Game::render()
{
	window.clear();
	switch (scenes.currentScene)
	{
	case Scenes::mainMenu:
		mainMenuScene.draw(window);
		break;

	case Scenes::optionsMenu:
		optionsMenuScene.draw(window);
		break;

	case Scenes::toolsMenu:
		toolsMenuScene.draw(window);
		break;

	case Scenes::soloMenu:
		soloMenuScene.draw(window);
		break;

	case Scenes::editorMenu:
		editorScene.draw(window);
		break;

	case Scenes::customMenu:
		break;

	case Scenes::map:
		mapScene.draw(window, b_paused);
		break;
	}
	if (fader.getOpacity() != 0)
		fader.draw(window);
	fpsclock.draw(window);
	window.display();
}

void Game::processEvents()
{
	sf::Event event;
	std::string mapFileName;
	Int32 nextScene = 0;
	bool changeScene = false;
	bool newMap = false;
	// get mouse position on window (integer)
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	// get mouse position on window (float)
	sf::Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	// get mouse coordinates (float)
	sf::Vector2f mousePositionC = window.mapPixelToCoords(mousePosition);
	while(window.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::MouseButtonPressed:
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				switch(scenes.currentScene)
				{
				case Scenes::mainMenu:
					mainMenuScene.click(mousePositionF, nextScene, window);
					break;
				case Scenes::toolsMenu:
					toolsMenuScene.click(mousePositionF, nextScene, window);
					break;
				case Scenes::optionsMenu:
					optionsMenuScene.click(mousePositionF, nextScene, window);
					break;
				case Scenes::soloMenu:
					soloMenuScene.click(mousePositionF, nextScene, window, mapFileName, newMap);
					break;
				case Scenes::map:
					mapScene.click(mousePositionF, mousePositionC, nextScene, window, b_paused);
					break;
				case Scenes::editorMenu:
					editorScene.click(mousePositionF, mousePositionC, nextScene, window);
					break;
				}
			} else if(event.mouseButton.button == sf::Mouse::Right)
			{

			}
			break;

		case sf::Event::MouseMoved:
			switch(scenes.currentScene)
			{
			case Scenes::mainMenu:
				mainMenuScene.mouseMoved(mousePositionF);
				break;
			case Scenes::toolsMenu:
				toolsMenuScene.mouseMoved(mousePositionF);
				break;
			case Scenes::optionsMenu:
				optionsMenuScene.mouseMoved(mousePositionF);
				break;
			case Scenes::soloMenu:
				soloMenuScene.mouseMoved(mousePositionF);
				break;
			case Scenes::map:
				mapScene.mouseMoved(mousePositionF, mousePositionC, b_paused, window.getSize().x, window.getSize().y);
				break;
			case Scenes::editorMenu:
				editorScene.mouseMoved(mousePositionF, mousePositionC);
				break;
			}
			break;

		case sf::Event::KeyPressed:
			switch(scenes.currentScene)
			{
			case Scenes::mainMenu:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			case Scenes::map:
				if (event.key.code == sf::Keyboard::Escape)
					b_paused = !b_paused;
				if (b_paused)
					mapScene.mapRes.waveSystem.pauseWaveChrono();
				else
					mapScene.mapRes.waveSystem.startWaveChrono();
				break;
			}
			break;

		case sf::Event::Resized:
			mainMenuScene.mainMenuRenderer.setPosition(event.size.width, event.size.height);
			toolsMenuScene.toolsMenuRenderer.setPosition(event.size.width, event.size.height);
			optionsMenuScene.optionsMenuRenderer.setPosition(event.size.width, event.size.height);
			soloMenuScene.soloMenuRenderer.setPosition(event.size.width, event.size.height);
			mapScene.mapRenderer.setPosition(view.view.getCenter().x - view.view.getSize().x / 2,
				view.view.getCenter().y - view.view.getSize().y / 2, event.size.width, event.size.height);
			view.resetView(window, event);
			break;

		
		case sf::Event::MouseWheelScrolled:
			switch(scenes.currentScene)
			{
			case Scenes::editorMenu:
				if (event.mouseWheelScroll.delta > 0)
					view.zoomView({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, (1.f / 1.1f));
				else if (event.mouseWheelScroll.delta < 0)
					view.zoomView({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, 1.1f);
				break;
			}
			break;
		
		}
	}

	changeScene = nextScene != 0;

	if (changeScene)
	{
		view.view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
		transitionOn();
		scenes.currentScene = static_cast<Scenes::Scene>(nextScene);
		if (newMap)
		{
			mapScene.mapRes.resetGame();
			mapScene.loadTileMap(mapFileName);
			mapScene.mapRes.waveSystem.startWaveChrono();
		}
		transitionOff();
	}
}

void Game::transitionOn()
{
	while (fader.getOpacity() != 255)
	{
		fader.fadeIn(fadingChrono.getTime());
		render();
	}
}

void Game::transitionOff()
{
	update();
	while (fader.getOpacity() != 0)
	{
		fader.fadeOut(fadingChrono.getTime());
		render();
	}
}