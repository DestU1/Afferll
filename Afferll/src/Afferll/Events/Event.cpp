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
}