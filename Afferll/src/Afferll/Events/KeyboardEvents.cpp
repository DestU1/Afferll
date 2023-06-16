#include "AfrlPch.h"
#include "Afferll/Events/KeyboardEvents.h"


namespace Afferll
{
    KeyPressEvent::KeyPressEvent(uint8_t keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyPressEvent::~KeyPressEvent()
    {
    }
    
    uint8_t KeyPressEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }
    
    
    KeyReleaseEvent::KeyReleaseEvent(uint8_t keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyReleaseEvent::~KeyReleaseEvent()
    {
    }
    
    uint8_t KeyReleaseEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }
    
    
    KeyRepeatEvent::KeyRepeatEvent(uint8_t keyCode)
    	: Event(), m_KeyCode(keyCode)
    {
    }
    KeyRepeatEvent::~KeyRepeatEvent()
    {
    }

    uint8_t KeyRepeatEvent::GetKeyCode()
    {
    	return m_KeyCode;
    }
}