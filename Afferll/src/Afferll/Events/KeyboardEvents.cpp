#include "AfrlPch.h"
#include "Afferll/Events/KeyboardEvents.h"


namespace Afferll
{
    KeyPressEvent::KeyPressEvent(KeyCode keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyPressEvent::~KeyPressEvent()
    {
    }
    
    KeyCode KeyPressEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }
    
    
    KeyReleaseEvent::KeyReleaseEvent(KeyCode keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyReleaseEvent::~KeyReleaseEvent()
    {
    }
    
    KeyCode KeyReleaseEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }
    
    
    KeyRepeatEvent::KeyRepeatEvent(KeyCode keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyRepeatEvent::~KeyRepeatEvent()
    {
    }

    KeyCode KeyRepeatEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }


    KeyTypeEvent::KeyTypeEvent(char _char)
        : Event(), m_Char(_char)
    {
    }
    KeyTypeEvent::~KeyTypeEvent()
    {
    }

    char KeyTypeEvent::GetChar()
    {
        return m_Char;
    }
}