#include "Logger.h"
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

void Dusk::Core::Logger::Log(char * msg, char * func, int severity)
{
	//std::cmatch cm;    // same as std::match_results<const char*> cm;
	//std::regex_match(func, cm, std::regex("\\w+\\s*::\\s*\\w+\\s*\\(.+\\)", std::regex_constants::ECMAScript));


	//std::cout << cm.length() << std::endl;
	//std::cout << cm.str() << std::endl;

	vector<string> v = split(func, "::");

	cout << "[" << "" << "]: " << msg << endl; //TODO: Fix this
}

void Dusk::Core::Logger::InternalLog(char * msg, char * func)
{
	Log(msg, func, 0);
}

void Dusk::Core::Logger::InternalLogWarning(char * msg, char * func)
{
	Log(msg, func, 1);
}

void Dusk::Core::Logger::InternalLogError(char * msg, char * func)
{
	Log(msg, func, 2);
}

void Dusk::Core::Logger::InternalLogFatal(char * msg, char * func)
{
	Log(msg, func, 3);
}
