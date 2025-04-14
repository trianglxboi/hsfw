#include "hspch.hh"
#include "retcode.hh"

#include <spdlog/fmt/fmt.h>

namespace hsfw {

	const char* retcode_to_string(retcode_t retcode) {
		switch (retcode) {
		#define RC_CASE(x) case x: return #x;
			RC_CASE(RET_SUCCESSFUL_EXECUTION);
			RC_CASE(RET_UNSPECIFIED_ERROR);
			RC_CASE(RET_FATAL_LOG_RECORDED);
			RC_CASE(RET_ASSERTION_FAILED);
			RC_CASE(RET_GPU_NOT_SUPPORTED);
		#undef RC_CASE
		default:
			return "((UNKNOWN_NONSTD_RETCODE))";
		}

		return nullptr;
	}

	const char* retcode_descriptor(retcode_t retcode) {
		switch (retcode) {
		case RET_SUCCESSFUL_EXECUTION:
			return "The application has completed its operations successfully and has returned with no critical errors reported.";
		case RET_UNSPECIFIED_ERROR:
			return "The application has run into an internal error that is yet to be described by error reporting systems or isn't "
				   "applicable for such treatment. Referring to application log may help.";
		case RET_FATAL_LOG_RECORDED:
			return "The application has failed to ensure operational integrity and has recorded a log with the fatal severity, cannot "
				   "ensure proper system operations and the application has to quit. The application log will contain the recorded fatal log.";
		case RET_ASSERTION_FAILED:
			return "The application tried to assert that a certain condition was as expected, but the condition didn't match the criteria.";
		case RET_GPU_NOT_SUPPORTED:
			return "The selected GPU isn't compatible with the requirements of the application. Refer to logs for more information.";
		default:
			return "((UNKNOWN_NONSTD_RETCODE))";
		}

		return nullptr;
	}

	std::string get_retcode_infotext(retcode_t retcode) {
		return fmt::format(
			"Application Return Code Information:\n  Return Code Value -> {}\n  Return Code String -> {}\n  Return Code Descriptor -> {}\n",
			 retcode, retcode_to_string(retcode), retcode_descriptor(retcode));
	}

	void log_retcode_infotext(retcode_t retcode)
	{
		if (log::core_logger) {
			HS_CORE_TRACE(get_retcode_infotext(retcode));
		}
	}

	void rtexit(retcode_t retcode, bool log) {
		if (log && log::core_logger) {
			HS_CORE_WARN("The application will now immediately exit as rtexit() was called.");
			log_retcode_infotext(retcode);
		}
		std::exit(retcode);
	}

}
