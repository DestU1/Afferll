#pragma once
#include "Afferll/Events/Event.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	class AFRL_API MousePressEvent : public Event
	{
	public:
		MousePressEvent(MouseButton mouseButton);
		virtual ~MousePressEvent();

		virtual EventType GetType() { return EventType::MousePress; }
		static EventType GetStaticType() { return EventType::MousePress; }
		static EventGroup GetGroups() 
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse |
				(uint64_t)EventGroup::Press |
				(uint64_t)EventGroup::Input
			);
		};

		MouseButton GetMouseButton();

	private:
		MouseButton m_MouseButton;
	};


	class AFRL_API MouseReleaseEvent : public Event
	{
	public:
		MouseReleaseEvent(MouseButton mouseButton);
		virtual ~MouseReleaseEvent();

		virtual EventType GetType() { return EventType::MouseRelease; }
		static EventType GetStaticType() { return EventType::MouseRelease; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse   |
				(uint64_t)EventGroup::Release |
				(uint64_t)EventGroup::Input
			);
		}

		MouseButton GetMouseButton();

	private:
		MouseButton m_MouseButton;
	};


	class AFRL_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(int64_t xPos, int64_t yPos);
		virtual ~MouseMoveEvent();

		virtual EventType GetType() { return EventType::MouseMove; }
		static EventType GetStaticType() { return EventType::MouseMove; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse
			);
		}

		int64_t GetXPos();
		int64_t GetYPos();

	private:
		int64_t m_Xpos, m_Ypos;
	};


	class AFRL_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(int64_t xOffset, int64_t yOffset);
		virtual ~MouseScrollEvent();

		virtual EventType GetType() { return EventType::MouseScroll; }
		static EventType GetStaticType() { return EventType::MouseScroll; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse
			);
		}

		int64_t GetXOffset();
		int64_t GetYOffset();

	private:
		int64_t m_XOffset, m_YOffset;
	};
}