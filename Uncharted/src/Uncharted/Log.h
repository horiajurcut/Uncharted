#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Uncharted
{

	class UNCHARTED_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define UNCHARTED_CORE_TRACE(...)    ::Uncharted::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UNCHARTED_CORE_INFO(...)     ::Uncharted::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UNCHARTED_CORE_WARN(...)     ::Uncharted::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UNCHARTED_CORE_ERROR(...)    ::Uncharted::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UNCHARTED_CORE_FATAL(...)    ::Uncharted::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define UNCHARTED_TRACE(...)         ::Uncharted::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UNCHARTED_INFO(...)          ::Uncharted::Log::GetClientLogger()->info(__VA_ARGS__)
#define UNCHARTED_WARN(...)          ::Uncharted::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UNCHARTED_ERROR(...)         ::Uncharted::Log::GetClientLogger()->error(__VA_ARGS__)
#define UNCHARTED_FATAL(...)         ::Uncharted::Log::GetClientLogger()->fatal(__VA_ARGS__)
