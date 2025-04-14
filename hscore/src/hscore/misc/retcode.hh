#ifndef HSCORE_MISC_RETCODE_HH
#define HSCORE_MISC_RETCODE_HH

#include <string>

namespace hsfw {

	typedef int retcode_t;
	enum : retcode_t {
		RET_SUCCESSFUL_EXECUTION = 0,
		RET_UNSPECIFIED_ERROR    = 1,
		RET_FATAL_LOG_RECORDED   = 2,
		RET_ASSERTION_FAILED     = 3,
		RET_GPU_NOT_SUPPORTED    = 4
	};
	const char* retcode_to_string(retcode_t retcode);
	const char* retcode_descriptor(retcode_t retcode);

	std::string get_retcode_infotext(retcode_t retcode);
	void log_retcode_infotext(retcode_t retcode);
	void rtexit(retcode_t retcode, bool log = true);
		
}

#endif // HSCORE_MISC_RETCODE_HH
