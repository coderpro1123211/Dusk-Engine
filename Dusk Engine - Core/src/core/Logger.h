#pragma once
#include <stdarg.h>

namespace Dusk {
	namespace Core {
		static class Logger {
			static void Log(char* msg, char* func, int severity, va_list argptr);
		public:
			static void InternalLog(char* msg, char* func, ...);
			static void InternalLogWarning(char* msg, char* func, ...);
			static void InternalLogError(char* msg, char* func, ...);
			static void InternalLogFatal(char* msg, char* func, ...);

#define LogMessage(m, ...) Dusk::Core::Logger::InternalLog(m, __FUNCTION__, __VA_ARGS__);
#define LogWarning(m, ...) Dusk::Core::Logger::InternalLogWarning(m, __FUNCTION__, __VA_ARGS__ );
#define LogError(m, ...) Dusk::Core::Logger::InternalLogError(m, __FUNCTION__, __VA_ARGS__ );
#define LogFatal(m, ...) Dusk::Core::Logger::InternalLogFatal(m, __FUNCTION__, __VA_ARGS__ );
		};
	}
}