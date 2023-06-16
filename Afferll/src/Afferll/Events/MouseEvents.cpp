#include "AfrlPch.h"
#include "Afferll/Events/MouseEvents.h"


namespace Afferll
{
    MousePressEvent::MousePressEvent(MouseButton mouseButton)
    	: m_MouseButton(mouseButton)
    {
    }
    MousePressEvent::~MousePressEvent()
    {
    }
    
    MouseButton MousePressEvent::GetMouseButton()
    {
    	return m_MouseButton;
    }
    
    
    MouseReleaseEvent::MouseReleaseEvent(MouseButton mouseButton)
    	: m_MouseButton(mouseButton)
    {
    }
    MouseReleaseEvent::~MouseReleaseEvent()
    {
    }
    
    MouseButton MouseReleaseEvent::GetMouseButton()
    {
    	return m_MouseButton;
    }
    
    
    MouseMoveEvent::MouseMoveEvent(uint64_t xPos, uint64_t yPos)
    	: m_Xpos(xPos), m_Ypos(yPos)
    {
    }
    MouseMoveEvent::~MouseMoveEvent()
    {
    }

    uint64_t MouseMoveEvent::GetX()
    {
    	return m_Xpos;
    }
    uint64_t MouseMoveEvent::GetY()
    {
    	return m_Ypos;
    }
    
    
    MouseScrollEvent::MouseScrollEvent(uint64_t xOffset, uint64_t yOffset)
    	: m_XOffset(xOffset), m_YOffset(yOffset)
    {
    }
    MouseScrollEvent::~MouseScrollEvent()
    {
    }
    
    uint64_t MouseScrollEvent::GetXOffset()
    {
    	return m_XOffset;
    }
    uint64_t MouseScrollEvent::GetYlOffset()
    {
    	return m_YOffset;
    }
}