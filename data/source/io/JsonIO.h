#pragma once

#include <json/json.h>
#include <fstream>
#include <sstream>
#include "../Variables.h"

class JsonIO
{
public:
	bool readSettings();
	bool writeSettings();

private:
	Variables variables;
};

