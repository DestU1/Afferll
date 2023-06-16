#pragma once
#include "AfrlPch.h"
#include "Afferll/Events/Event.h"


namespace Afferll
{
	enum class MouseButton
	{
		Left     = 0,
		Right    = 1,
		Middle   = 2,
		XButton1 = 3,
		XButton2 = 4
	};


	class MousePressEvent : public Event
	{
	public:
		MousePressEvent(MouseButton mouseButton);
		virtual ~MousePressEvent();

		static constexpr EventType GetType() { return EventType::MousePress; }
		static constexpr EventGroup GetGroups() 
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


	class MouseReleaseEvent : public Event
	{
	public:
		MouseReleaseEvent(MouseButton mouseButton);
		virtual ~MouseReleaseEvent();

		static constexpr EventType GetType() { return EventType::MouseRelease; }
		static constexpr EventGroup GetGroups()
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


	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(uint64_t xPos, uint64_t yPos);
		virtual ~MouseMoveEvent();

		static constexpr EventType GetType() { return EventType::MouseMove; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse
			);
		}

		uint64_t GetX();
		uint64_t GetY();

	private:
		uint64_t m_Xpos, m_Ypos;
	};


	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(uint64_t xOffset, uint64_t yOffset);
		virtual ~MouseScrollEvent();

		static constexpr EventType GetType() { return EventType::MouseScroll; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Mouse
			);
		}

		uint64_t GetXOffset();
		uint64_t GetYlOffset();

	private:
		uint64_t m_XOffset, m_YOffset;
	};
}