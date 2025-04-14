#include "hspch.hh"
#include "linux_msdialg.hh"

namespace hsfw {

	linux_message_dialog::linux_message_dialog(const dialog_spec& spec)
		: m_spec(spec) {
	}

	dialog_result linux_message_dialog::init_and_wait() const {
		return dialog_result::creat_fail;
	}

	bool linux_message_dialog::is_platform_supported() const {
		return false;
	}

	void linux_message_dialog::set_spec(const dialog_spec& spec) {
		m_spec = spec;
	}

	void linux_message_dialog::set_caption(std::string_view caption) {
		m_spec.caption = caption;
	}

	void linux_message_dialog::set_content(std::string_view content) {
		m_spec.content = content;
	}

	void linux_message_dialog::set_buttonset(dialog_buttonset buttonset) {
		m_spec.buttonset = buttonset;
	}

	void linux_message_dialog::set_icon(dialog_icon icon) {
		m_spec.icon = icon;
	}

	void linux_message_dialog::set_default_button_index(int default_button_index) {
		m_spec.default_button_index = default_button_index;
	}

}
