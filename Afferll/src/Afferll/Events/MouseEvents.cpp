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
    
    
    MouseMoveEvent::MouseMoveEvent(int64_t xPos, int64_t yPos)
    	: m_Xpos(xPos), m_Ypos(yPos)
    {
    }
    MouseMoveEvent::~MouseMoveEvent()
    {
    }

    int64_t MouseMoveEvent::GetXPos()
    {
    	return m_Xpos;
    }
    int64_t MouseMoveEvent::GetYPos()
    {
    	return m_Ypos;
    }
    
    
    MouseScrollEvent::MouseScrollEvent(int64_t xOffset, int64_t yOffset)
    	: m_XOffset(xOffset), m_YOffset(yOffset)
    {
    }
    MouseScrollEvent::~MouseScrollEvent()
    {
    }
    
    int64_t MouseScrollEvent::GetXOffset()
    {
    	return m_XOffset;
    }
    int64_t MouseScrollEvent::GetYOffset()
    {
    	return m_YOffset;
    }
}