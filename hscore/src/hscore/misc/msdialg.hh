#ifndef HSCORE_MISC_MSDIALG_HH
#define HSCORE_MISC_MSDIALG_HH

#include <string_view>
#include <string>
#include <memory>

namespace hsfw {

	enum class dialog_buttonset {
		abort_retry_ignore  = 0x00000002L,
		cancel_try_continue = 0x00000006L,
		help                = 0x00004000L,
		ok                  = 0x00000000L,
		ok_cancel           = 0x00000001L,
		retry_cancel        = 0x00000005L,
		yes_no              = 0x00000004L,
		yes_no_cancel       = 0x00000003L
	};

	enum class dialog_icon {
		none     = 0x00000000L,
		question = 0x00000020L,
		info     = 0x00000040L,
		warn     = 0x00000030L,
		err      = 0x00000010L
	};

	enum class dialog_result {
		creat_fail = 0,

		ok        = 1,
		cancel    = 2,
		abort     = 3,
		retry     = 4,
		ignore    = 5,
		yes       = 6,
		no        = 7,
		try_again = 10,
		continue_ = 11
	};

	struct dialog_spec {
		std::string caption = "caption not specified", content = "content not specified";
		dialog_buttonset buttonset = dialog_buttonset::ok;
		dialog_icon icon = dialog_icon::none;
		int default_button_index = 0; // in inclusive range 0-3

		dialog_spec(std::string_view caption = "caption not specified",
					std::string_view content = "content not specified",
					dialog_buttonset buttonset = dialog_buttonset::ok,
					dialog_icon icon = dialog_icon::none,
					int default_button_index = 0)
			: caption(caption), content(content), buttonset(buttonset), icon(icon), default_button_index(default_button_index) {}
	};

	class message_dialog {
	public:
		virtual ~message_dialog() = default;

		virtual dialog_result init_and_wait() const = 0;
		virtual bool is_platform_supported() const = 0;

		virtual void set_spec(const dialog_spec& spec) = 0;
		virtual void set_caption(std::string_view caption) = 0;
		virtual void set_content(std::string_view content) = 0;
		virtual void set_buttonset(dialog_buttonset buttonset) = 0;
		virtual void set_icon(dialog_icon icon) = 0;
		virtual void set_default_button_index(int default_button_index) = 0;

		virtual const dialog_spec& get_spec() const = 0;
		virtual const std::string& get_caption() const = 0;
		virtual const std::string& get_content() const = 0;
		virtual dialog_buttonset get_buttonset() const = 0;
		virtual dialog_icon get_icon() const = 0;
		virtual int get_default_button_index() const = 0;

		static std::unique_ptr<message_dialog> create(const dialog_spec& spec = {});
	};

}

#endif // HSCORE_MISC_MSDIALG_HH
