#include "AfrlPch.h"
#include "Afferll/Events/Event.h"


namespace Afferll
{
    Event::Event()
        : m_Handled(false)
    {
    }
    Event::~Event()
    {
    }

    bool Event::IsInGroup(EventGroup group)
    {
        return (uint64_t)GetGroups() & (uint64_t)group;
    }
    bool Event::IsHandled()
    {
        return m_Handled;
    }

    void Event::Resolve()
    {
        m_Handled = true;
    }


    EventDispacher::EventDispacher(Event& e)
        : m_Event(e)
    {
    }
    EventDispacher::~EventDispacher()
    {
    }


    std::string AFRL_API ToString(EventType _Val)
	{
		switch (_Val)
		{
			case EventType::WindowMove:
				return std::string("Window Move");
			case EventType::WindowFocus:
				return std::string("Window Focus");
			case EventType::WindowFocusLoss:
				return std::string("Window Focus Loss");
			case EventType::WindowResize:
				return std::string("Window Resize");
			case EventType::WindowClose:
				return std::string("Window Close");
			case EventType::KeyPress:
				return std::string("Key Press");
			case EventType::KeyRelease:
				return std::string("Key Release");
			case EventType::KeyRepeat:
				return std::string("Key Repeat");
			case EventType::KeyType:
				return std::string("Key Type");
			case EventType::MousePress:
				return std::string("Mouse Press");
			case EventType::MouseRelease:
				return std::string("Mouse Release");
			case EventType::MouseScroll:
				return std::string("Mouse Scroll");
			case EventType::MouseMove:
				return std::string("Mouse Move");

			default:
				return std::string("Unknown Event Type");
		}
	}
}