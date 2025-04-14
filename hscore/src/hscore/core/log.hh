#ifndef HSCORE_CORE_LOG_HH
#define HSCORE_CORE_LOG_HH

#include "hscore/misc/msdialg.hh"
#include "hscore/misc/retcode.hh"

#define FMT_UNICODE 0
#define SPDLOG_LEVEL_NAMES { "trace", "debug", "info", "warn", "err", "fatal", "off" } 
#define SPDLOG_SHORT_LEVEL_NAMES { "T", "D", "I", "W", "E", "F", "O" } 
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

namespace hsfw::log {

	extern std::shared_ptr<spdlog::logger> core_logger, editor_logger, runtime_logger;

	void init();
	void devel_post_fatal_log(retcode_t retcode = RET_FATAL_LOG_RECORDED);

	template <typename... Args>
	static void runtime_error_log(bool fatal, retcode_t retcode, const std::string& logger_name, std::string_view fmt, Args&&... args)
	{
		dialog_spec spec = {
			fatal ? "Fatal error!" : "Runtime error!",
			fatal ? (fmt::format("{}\n\n{}\n\n{}", fmt::vformat(fmt, fmt::make_format_args(args...)), fmt::format("The application will be aborted due to that.\nLogged by: {}", logger_name), get_retcode_infotext(retcode)))
				  : (fmt::format("{}\n\n{}", fmt::vformat(fmt, fmt::make_format_args(args...)), fmt::format("Logged by: {}", logger_name))),
			dialog_buttonset::ok,
			dialog_icon::err
		};

		std::unique_ptr<message_dialog> dialog = message_dialog::create(spec);
		dialog->init_and_wait();

		if (fatal) {
			rtexit(retcode);
		}
	}

}

#define HS_LOGGER_TRACE(logger, ...) logger->trace(__VA_ARGS__)
#define HS_LOGGER_INFO(logger, ...)  logger->info(__VA_ARGS__)
#define HS_LOGGER_WARN(logger, ...)  logger->warn(__VA_ARGS__)

#ifdef HS_DEVEL
	#define HS_LOGGER_ERROR(logger, ...) logger->error(__VA_ARGS__)
	#define HS_LOGGER_FATAL(logger, retcode, ...) { logger->critical(__VA_ARGS__); ::hsfw::log::devel_post_fatal_log(retcode); }
#else
	#define HS_LOGGER_ERROR(logger, ...) { logger->error(__VA_ARGS__); ::hsfw::log::runtime_error_log(false, -1, logger->name(), __VA_ARGS__); }
	#define HS_LOGGER_FATAL(logger, retcode, ...) { logger->critical(__VA_ARGS__); ::hsfw::log::runtime_error_log(true, retcode, logger->name(), __VA_ARGS__); }
#endif

#define HS_CORE_TRACE(...)                HS_LOGGER_TRACE(::hsfw::log::core_logger, __VA_ARGS__)
#define HS_CORE_INFO(...)                 HS_LOGGER_INFO (::hsfw::log::core_logger, __VA_ARGS__)
#define HS_CORE_WARN(...)                 HS_LOGGER_WARN (::hsfw::log::core_logger, __VA_ARGS__)
#define HS_CORE_ERROR(...)                HS_LOGGER_ERROR(::hsfw::log::core_logger, __VA_ARGS__)
#define HS_CORE_FATAL_RC(retcode, ...)    HS_LOGGER_FATAL(::hsfw::log::core_logger, retcode, __VA_ARGS__)
#define HS_CORE_FATAL(...)                HS_LOGGER_FATAL(::hsfw::log::core_logger, ::hsfw::RET_FATAL_LOG_RECORDED, __VA_ARGS__)

#define HS_EDITOR_TRACE(...)              HS_LOGGER_TRACE(::hsfw::log::editor_logger, __VA_ARGS__)
#define HS_EDITOR_INFO(...)               HS_LOGGER_INFO (::hsfw::log::editor_logger, __VA_ARGS__)
#define HS_EDITOR_WARN(...)               HS_LOGGER_WARN (::hsfw::log::editor_logger, __VA_ARGS__)
#define HS_EDITOR_ERROR(...)              HS_LOGGER_ERROR(::hsfw::log::editor_logger, __VA_ARGS__)
#define HS_EDITOR_FATAL_RC(retcode, ...)  HS_LOGGER_FATAL(::hsfw::log::editor_logger, retcode, __VA_ARGS__)
#define HS_EDITOR_FATAL(...)              HS_LOGGER_FATAL(::hsfw::log::editor_logger, ::hsfw::RET_FATAL_LOG_RECORDED, __VA_ARGS__)

#define HS_RUNTIME_TRACE(...)             HS_LOGGER_TRACE(::hsfw::log::runtime_logger, __VA_ARGS__)
#define HS_RUNTIME_INFO(...)              HS_LOGGER_INFO (::hsfw::log::runtime_logger, __VA_ARGS__)
#define HS_RUNTIME_WARN(...)              HS_LOGGER_WARN (::hsfw::log::runtime_logger, __VA_ARGS__)
#define HS_RUNTIME_ERROR(...)             HS_LOGGER_ERROR(::hsfw::log::runtime_logger, __VA_ARGS__)
#define HS_RUNTIME_FATAL_RC(retcode, ...) HS_LOGGER_FATAL(::hsfw::log::runtime_logger, retcode, __VA_ARGS__)
#define HS_RUNTIME_FATAL(...)             HS_LOGGER_FATAL(::hsfw::log::runtime_logger, ::hsfw::RET_FATAL_LOG_RECORDED, __VA_ARGS__)

#endif // HSCORE_CORE_LOG_HH
