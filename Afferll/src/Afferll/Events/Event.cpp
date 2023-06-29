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
		static const std::unordered_map<EventType, std::string> eventMap({
			{ EventType::Invalid,         std::string("Unknown Event Type")	},
			{ EventType::WindowMove,      std::string("Window Move")	    },
			{ EventType::WindowFocus,     std::string("Window Focus")	    },
			{ EventType::WindowFocusLoss, std::string("Window Focus Loss")  },
			{ EventType::WindowResize,    std::string("Window Resize")	    },
			{ EventType::WindowClose,     std::string("Window Close")	    },
			{ EventType::KeyPress,        std::string("Key Press")		    },
			{ EventType::KeyRelease,      std::string("Key Release")	    },
			{ EventType::KeyRepeat,       std::string("Key Repeat")		    },
			{ EventType::KeyType,         std::string("Key Type")		    },
			{ EventType::MousePress,      std::string("Mouse Press")	    },
			{ EventType::MouseRelease,    std::string("Mouse Release")	    },
			{ EventType::MouseScroll,     std::string("Mouse Scroll")	    },
			{ EventType::MouseMove,       std::string("Mouse Move")		    }
		});

		return eventMap.contains(_Val) ? eventMap.at(_Val) : eventMap.at(EventType::Invalid);
	}
}