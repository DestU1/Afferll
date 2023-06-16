#pragma once
#include "AfrlPch.h"
#include "Afferll/Events/Event.h"


namespace Afferll
{
	class KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(uint8_t keyCode);
		virtual ~KeyPressEvent();

		static constexpr EventType GetType() { return EventType::KeyPress; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard |
				(uint64_t)EventGroup::Press    |
				(uint64_t)EventGroup::Input
			);
		}

		uint8_t GetKeyCode();

	private:
		uint8_t m_KeyCode;
	};


	class KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(uint8_t keyCode);
		virtual ~KeyReleaseEvent();

		static constexpr EventType GetType() { return EventType::KeyRelease; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard |
				(uint64_t)EventGroup::Release  |
				(uint64_t)EventGroup::Input
			);
		}

		uint8_t GetKeyCode();

	private:
		uint8_t m_KeyCode;
	};


	class KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(uint8_t keyCode);
		virtual ~KeyRepeatEvent();

		static constexpr EventType GetType() { return EventType::KeyRepeat; }
		static constexpr EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard
			);
		}

		uint8_t GetKeyCode();

	private:
		uint8_t m_KeyCode;
	};
}