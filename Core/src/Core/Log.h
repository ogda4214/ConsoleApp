#pragma once

#include "Core/BaseDefine.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Core {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CORE_TRACE(...)    ::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define APP_TRACE(...)         ::Core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APP_INFO(...)          ::Core::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_WARN(...)          ::Core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...)         ::Core::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_CRITICAL(...)      ::Core::Log::GetClientLogger()->critical(__VA_ARGS__)
