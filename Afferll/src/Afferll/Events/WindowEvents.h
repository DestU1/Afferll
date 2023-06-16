#pragma once
#include "AfrlPch.h"
#include "Afferll/Events/Event.h"


namespace Afferll
{
	class WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(uint64_t top, uint64_t left);
		virtual ~WindowMoveEvent();

		static constexpr EventType GetType() { return EventType::WindowMove; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}

		uint64_t GetTop();
		uint64_t GetLeft();

	private:
		uint64_t m_Top, m_Left;
	};


	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent();
		virtual ~WindowFocusEvent();

		static constexpr EventType GetType() { return EventType::WindowFocus; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};


	class WindowFocusLossEvent : public Event
	{
	public:
		WindowFocusLossEvent();
		virtual ~WindowFocusLossEvent();

		static constexpr EventType GetType() { return EventType::WindowFocusLoss; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};


	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint64_t width, uint64_t height);
		virtual ~WindowResizeEvent();

		static constexpr EventType GetType() { return EventType::WindowResize; }
		static constexpr EventGroup GetGroups()
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


	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent();
		virtual ~WindowCloseEvent();

		static constexpr EventType GetType() { return EventType::WindowClose; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Window
			);
		}
	};
}