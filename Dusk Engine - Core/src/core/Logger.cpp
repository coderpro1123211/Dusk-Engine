#include "Logger.h"
#include <iostream>
#include <regex>
#include <vector>
#include <stdarg.h>

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

void Dusk::Core::Logger::Log(char * msg, char * func, int severity, va_list argptr)
{
	//std::cmatch cm;    // same as std::match_results<const char*> cm;
	//std::regex_match(func, cm, std::regex("\\w+\\s*::\\s*\\w+\\s*\\(.+\\)", std::regex_constants::ECMAScript));


	//std::cout << cm.length() << std::endl;
	//std::cout << cm.str() << std::endl;

	char dest[1024 * 16];
	memset(&dest, 0, 1024 * 16);
	vsnprintf(dest, 1024*16, msg, argptr);

	vector<string> v = split(func, "::");

#ifdef LOG_VERBOSE
	cout << "[" << v[v.size()-2] << v[v.size()-1] << "]: " << dest << endl;
#else
	cout << "[" << v[v.size() - 2] << "]: " << dest << endl;
#endif // LOG_VERBOSE

}

void Dusk::Core::Logger::InternalLog(char * msg, char * func, ...)
{
	va_list argptr;
	va_start(argptr, func);
	Log(msg, func, 0, argptr);
	va_end(argptr);
}

void Dusk::Core::Logger::InternalLogWarning(char * msg, char * func, ...)
{
	va_list argptr;
	va_start(argptr, func);
	Log(msg, func, 1, argptr);
	va_end(argptr);
}

void Dusk::Core::Logger::InternalLogError(char * msg, char * func, ...)
{
	va_list argptr;
	va_start(argptr, func);
	Log(msg, func, 2, argptr);
	va_end(argptr);
}

void Dusk::Core::Logger::InternalLogFatal(char * msg, char * func, ...)
{
	va_list argptr;
	va_start(argptr, msg);
	Log(msg, func, 3, argptr);
	va_end(argptr);
}
