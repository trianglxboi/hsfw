#include "hspch.hh"
#include "msdialg.hh"

#include "platform/windows/windows_msdialg.hh"
#include "platform/linux/linux_msdialg.hh"

namespace hsfw {

	std::unique_ptr<message_dialog> message_dialog::create(const dialog_spec& spec) {
		return std::make_unique<HS_MAKE_PLATFORM_TYPE(message_dialog)>(spec);
	}

}
