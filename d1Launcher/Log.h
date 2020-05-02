#pragma once

#include "SpdLog/spdlog.h"

class Log
{
public:
	Log() = default;

	static void logInit();

	static inline const std::shared_ptr<spdlog::logger> coreLogger() { return Log::m_coreLogger; }
	static inline const std::shared_ptr<spdlog::logger> clientLogger() { return Log::m_clientLogger; }

	static inline const bool logInitialised() { return Log::m_logInitialised; }


private:
	static std::shared_ptr<spdlog::logger> m_coreLogger;
	static std::shared_ptr<spdlog::logger> m_clientLogger;

	static bool m_logInitialised;
};

// Core log macros to deal with errors/warnings/info on the engine side
#define TH_CORE_CRITICAL(...)   Log::coreLogger()->critical(__VA_ARGS__)
#define TH_CORE_ERROR(...)   Log::coreLogger()->error(__VA_ARGS__)
#define TH_CORE_WARN(...)    Log::coreLogger()->warn(__VA_ARGS__)
#define TH_CORE_INFO(...)    Log::coreLogger()->info(__VA_ARGS__)
#define TH_CORE_TRACE(...)   Log::coreLogger()->trace(__VA_ARGS__)

// Client log macros to deal with errors/warnings/info on the game side

#define TH_CLIENT_CRITICAL(...) Log::clientLogger()->critical(__VA_ARGS__)
#define TH_CLIENT_ERROR(...) Log::clientLogger()->error(__VA_ARGS__)
#define TH_CLIENT_WARN(...)  Log::clientLogger()->warn(__VA_ARGS__)
#define TH_CLIENT_INFO(...)  Log::clientLogger()->info(__VA_ARGS__)
#define TH_CLIENT_TRACE(...) Log::clientLogger()->trace(__VA_ARGS__)