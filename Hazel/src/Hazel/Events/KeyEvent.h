#pragma once

#include "Event.h"

namespace Hazel {

	class HAZEL_API KeyEvent : public Event 
	{
	public:
		inline	int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

    class HAZEL_API KeyPressedEvent : public KeyEvent{
    public:
        KeyPressedEvent(int keycode, bool repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        bool IsRepeat() const { return m_RepeatCount; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_RepeatCount << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);

    private:
        bool m_RepeatCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent {
    public:

        KeyReleasedEvent(int keycode) 
            : KeyEvent(keycode) {}

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased);
    };
}