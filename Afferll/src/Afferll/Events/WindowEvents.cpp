#include "AfrlPch.h"
#include "Afferll/Events/WindowEvents.h"


namespace Afferll
{
    WindowMoveEvent::WindowMoveEvent(int64_t left, int64_t top)
    	: Event(), m_Left(left), m_Top(top)
    {
    }
    WindowMoveEvent::~WindowMoveEvent()
    {
    }
    
    int64_t WindowMoveEvent::GetTop()
    {
    	return m_Top;
    }
    int64_t WindowMoveEvent::GetLeft()
    {
    	return m_Left;
    }
    
    
    WindowFocusEvent::WindowFocusEvent()
    	: Event()
    {
    }
    WindowFocusEvent::~WindowFocusEvent()
    {
    }
    
    
    WindowFocusLossEvent::WindowFocusLossEvent()
    	: Event()
    {
    }
    WindowFocusLossEvent::~WindowFocusLossEvent()
    {
    }
    
    
    WindowResizeEvent::WindowResizeEvent(uint64_t width, uint64_t height)
    	: Event(), m_Width(width), m_Height(height)
    {
    }
    WindowResizeEvent::~WindowResizeEvent()
    {
    }
    
    uint64_t WindowResizeEvent::GetWidth()
    {
    	return m_Width;
    }
    uint64_t WindowResizeEvent::GetHeight()
    {
    	return m_Height;
    }
    
    
    WindowCloseEvent::WindowCloseEvent()
    	: Event()
    {
    }
    WindowCloseEvent::~WindowCloseEvent()
    {
    }
}