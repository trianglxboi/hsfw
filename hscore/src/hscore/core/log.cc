#include "hspch.hh"
#include "log.hh"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace hsfw::log {

	std::shared_ptr<spdlog::logger> core_logger, editor_logger, runtime_logger;

	void init() {
		static spdlog::sink_ptr sinks[] = {
			std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
			std::make_shared<spdlog::sinks::basic_file_sink_mt>("hsfw.log", true)
		};

		sinks[0]->set_pattern("%^[%T] %n: %v%$");
		sinks[1]->set_pattern("[%T] (%l) %n: %v");
			
		auto create_logger = [](const std::string& name) -> std::shared_ptr<spdlog::logger>
		{
			std::shared_ptr<spdlog::logger> logger = std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
			spdlog::register_logger(logger);

			logger->set_level(spdlog::level::trace);
			logger->flush_on(spdlog::level::trace);

			return logger;
		};

		core_logger    = create_logger("CORELIB");
		editor_logger  = create_logger("EDITOR");
		runtime_logger = create_logger("RUNTIME");
	}

	void devel_post_fatal_log(retcode_t retcode) {
		std::cout << "  -> The application will be aborted due to that.\n";
		rtexit(retcode);
	}

}
