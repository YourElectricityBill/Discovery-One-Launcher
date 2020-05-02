#include "Log.h"

#include "SpdLog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::m_coreLogger;
std::shared_ptr<spdlog::logger> Log::m_clientLogger;
bool Log::m_logInitialised;

void Log::logInit()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	m_coreLogger = spdlog::stdout_color_mt("LAUNCHER");
	m_coreLogger->set_level(spdlog::level::trace);
	m_clientLogger = spdlog::stdout_color_mt("CLIENT");
	m_clientLogger->set_level(spdlog::level::trace);

	Log::m_logInitialised = true;
}
