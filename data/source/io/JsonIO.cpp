#include "JsonIO.h"

bool JsonIO::readSettings()
{
	std::ifstream file("data/saves/JSON/options.json");
	if (!file.is_open())
		return false;
	std::stringstream text;
	std::string errors;
	text << file.rdbuf();

	Json::Value root;
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	reader->parse(text.str().c_str(), text.str().c_str() + text.str().size(), &root, &errors);
	file.close();
	delete reader;

	variables.fullscreen = root["fullscreen"].asBool();
	variables.music = root["music"].asBool();
	variables.soundEffects = root["soundEffects"].asBool();
	variables.heavyShaders = root["heavyShaders"].asBool();
	variables.keyControls = static_cast<tristate>(root["controls"].asInt());
	return true;
}

bool JsonIO::writeSettings()
{
	std::ofstream file("data/saves/JSON/options.json");
	if (!file.is_open())
		return false;

	Json::Value root;
	root["fullscreen"] = variables.fullscreen;
	root["music"] = variables.music;
	root["soundEffects"] = variables.soundEffects;
	root["heavyShaders"] = variables.heavyShaders;
	root["controls"] = static_cast<int>(variables.keyControls);

	file << root;
	file.close();
	return true;
}