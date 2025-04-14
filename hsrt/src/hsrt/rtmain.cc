#include "hspch.hh"

namespace hsfw {

	retcode_t rtmain(int argc, char** argv) {
		log::init();
		HS_RUNTIME_INFO("Initialized logging.");

		log_retcode_infotext(RET_SUCCESSFUL_EXECUTION);
		return RET_SUCCESSFUL_EXECUTION;
	}

}

#if defined HS_DIST && defined HS_PLATFORM_WINDOWS

int WINAPI WinMain(
	_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR     lpCmdLine,
	_In_     int       nCmdShow
) {
	return hsfw::rtmain(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return hsfw::rtmain(argc, argv);
}

#endif
