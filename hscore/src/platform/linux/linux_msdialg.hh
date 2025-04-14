#ifndef HSCORE_PLATFORM_LINUX_MSDIALG_HH
#define HSCORE_PLATFORM_LINUX_MSDIALG_HH

#include "hscore/misc/msdialg.hh"

namespace hsfw {

	class linux_message_dialog : public message_dialog {
	public:
		linux_message_dialog(const dialog_spec& spec = {});
		virtual ~linux_message_dialog() override = default;
		
		virtual dialog_result init_and_wait() const override;
		virtual bool is_platform_supported() const override;

		virtual void set_spec(const dialog_spec& spec) override;
		virtual void set_caption(std::string_view caption) override;
		virtual void set_content(std::string_view content) override;
		virtual void set_buttonset(dialog_buttonset buttonset) override;
		virtual void set_icon(dialog_icon icon) override;
		virtual void set_default_button_index(int default_button_index) override;

		virtual const dialog_spec& get_spec() const override { return m_spec; }
		virtual const std::string& get_caption() const override { return m_spec.caption; }
		virtual const std::string& get_content() const override { return m_spec.content; }
		virtual dialog_buttonset get_buttonset() const override { return m_spec.buttonset; }
		virtual dialog_icon get_icon() const override { return m_spec.icon;  }
		virtual int get_default_button_index() const override { return m_spec.default_button_index; }
	private:
		dialog_spec m_spec;
	};

}

#endif // HSCORE_PLATFORM_LINUX_MSDIALG_HH
