#pragma once
#include "Afferll/Events/Event.h"


namespace Afferll
{
	class AFRL_API WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(int64_t left, int64_t top);
		virtual ~WindowMoveEvent();

		virtual EventType GetType() { return EventType::WindowMove; }
		static EventType GetStaticType() { return EventType::WindowMove; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}

		int64_t GetTop();
		int64_t GetLeft();

	private:
		int64_t m_Top, m_Left;
	};


	class AFRL_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent();
		virtual ~WindowFocusEvent();

		virtual EventType GetType() { return EventType::WindowFocus; }
		static EventType GetStaticType() { return EventType::WindowFocus; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};


	class AFRL_API WindowFocusLossEvent : public Event
	{
	public:
		WindowFocusLossEvent();
		virtual ~WindowFocusLossEvent();

		virtual EventType GetType() { return EventType::WindowFocusLoss; }
		static EventType GetStaticType() { return EventType::WindowFocusLoss; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};


	class AFRL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint64_t width, uint64_t height);
		virtual ~WindowResizeEvent();

		virtual EventType GetType() { return EventType::WindowResize; }
		static EventType GetStaticType() { return EventType::WindowResize; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}

		uint64_t GetWidth();
		uint64_t GetHeight();

	private:
		uint64_t m_Width, m_Height;
	};


	class AFRL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent();
		virtual ~WindowCloseEvent();

		virtual EventType GetType() { return EventType::WindowClose; }
		static EventType GetStaticType() { return EventType::WindowClose; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};
}