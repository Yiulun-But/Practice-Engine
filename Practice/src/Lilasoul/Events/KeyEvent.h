#pragma once

#include "Event.h"
#include "lspch.h"

// #include <sstream>

namespace Lilasoul {

    class LILASOUL_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; };

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) {};

        int m_KeyCode; 
    };

    class LILASOUL_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {};

        inline int GetRepeatCount() const { return m_RepeatCount; };

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        };

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class LILASOUL_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {};

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        };

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class LILASOUL_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode) {};

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        };

        EVENT_CLASS_TYPE(KeyTyped)
    };
}