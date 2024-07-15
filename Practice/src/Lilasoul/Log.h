#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Lilasoul {

	class LILASOUL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LS_CORE_TRACE(...)  ::Lilasoul::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LS_CORE_INFO(...)   ::Lilasoul::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LS_CORE_WARN(...)   ::Lilasoul::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LS_CORE_ERROR(...)  ::Lilasoul::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LS_CORE_FATAL(...)  ::Lilasoul::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LS_TRACE(...)       ::Lilasoul::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LS_INFO(...)        ::Lilasoul::Log::GetClientLogger()->info(__VA_ARGS__)
#define LS_WARN(...)        ::Lilasoul::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LS_ERROR(...)       ::Lilasoul::Log::GetClientLogger()->error(__VA_ARGS__)
#define LS_FATAL(...)       ::Lilasoul::Log::GetClientLogger()->fatal(__VA_ARGS__)
