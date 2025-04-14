#include "hspch.hh"
#include "windows_msdialg.hh"

namespace hsfw {

	inline static long defbutton_to_win32_format(int i) {
		switch (i) {
		case 1: return 0x00000100L;
		case 2: return 0x00000200L;
		case 3: return 0x00000300L;
		case 0: // 1st button (0-indexing)
		default: // invalid index
			return 0x00000000L;
		}

		return 0;
	}

	windows_message_dialog::windows_message_dialog(const dialog_spec& spec)
		: m_spec(spec) {
	}

	dialog_result windows_message_dialog::init_and_wait() const {
		return (dialog_result) MessageBoxA(
			NULL, m_spec.content.c_str(), m_spec.caption.c_str(),
			(UINT)((long) m_spec.buttonset | (long) m_spec.icon | defbutton_to_win32_format(m_spec.default_button_index))
		);
	}

	bool windows_message_dialog::is_platform_supported() const {
		return true;
	}

	void windows_message_dialog::set_spec(const dialog_spec& spec) {
		m_spec = spec;
	}

	void windows_message_dialog::set_caption(std::string_view caption) {
		m_spec.caption = caption;
	}

	void windows_message_dialog::set_content(std::string_view content) {
		m_spec.content = content;
	}

	void windows_message_dialog::set_buttonset(dialog_buttonset buttonset) {
		m_spec.buttonset = buttonset;
	}

	void windows_message_dialog::set_icon(dialog_icon icon) {
		m_spec.icon = icon;
	}

	void windows_message_dialog::set_default_button_index(int default_button_index) {
		m_spec.default_button_index = default_button_index;
	}

}
