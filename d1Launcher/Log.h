#pragma once

#include "SpdLog/spdlog.h"

#include "SDL2/SDL.h"

class Log
{
public:
	Log() = default;

	static void logInit();

	template<typename T> 
	static void validateObject(T tp_object);

	static inline const std::shared_ptr<spdlog::logger> coreLogger() { return Log::m_coreLogger; }
	static inline const std::shared_ptr<spdlog::logger> clientLogger() { return Log::m_clientLogger; }

	static inline const bool logInitialised() { return Log::m_logInitialised; }


private:
	static std::shared_ptr<spdlog::logger> m_coreLogger;
	static std::shared_ptr<spdlog::logger> m_clientLogger;

	static bool m_logInitialised;
};

template<typename T>
void Log::validateObject(T tp_object)
{
	if (tp_object == nullptr)
	{
		m_coreLogger->error("Error: {0}", SDL_GetError());
	}
}


// Core log macros to deal with errors/warnings/info on the engine side
#define LN_CORE_CRITICAL(...)   Log::coreLogger()->critical(__VA_ARGS__)
#define LN_CORE_ERROR(...)   Log::coreLogger()->error(__VA_ARGS__)
#define LN_CORE_WARN(...)    Log::coreLogger()->warn(__VA_ARGS__)
#define LN_CORE_INFO(...)    Log::coreLogger()->info(__VA_ARGS__)
#define LN_CORE_TRACE(...)   Log::coreLogger()->trace(__VA_ARGS__)

// Client log macros to deal with errors/warnings/info on the game side

#define LN_CLIENT_CRITICAL(...) Log::clientLogger()->critical(__VA_ARGS__)
#define LN_CLIENT_ERROR(...) Log::clientLogger()->error(__VA_ARGS__)
#define LN_CLIENT_WARN(...)  Log::clientLogger()->warn(__VA_ARGS__)
#define LN_CLIENT_INFO(...)  Log::clientLogger()->info(__VA_ARGS__)
#define LN_CLIENT_TRACE(...) Log::clientLogger()->trace(__VA_ARGS__)