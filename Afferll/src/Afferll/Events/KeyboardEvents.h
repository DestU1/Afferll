#pragma once
#include "Afferll/Events/Event.h"


namespace Afferll
{
	class AFRL_API KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(uint8_t keyCode);
		virtual ~KeyPressEvent();

		virtual EventType GetType() { return EventType::KeyPress; }
		static EventType GetStaticType() { return EventType::KeyPress; }
		static EventGroup GetGroups()
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


	class AFRL_API KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(uint8_t keyCode);
		virtual ~KeyReleaseEvent();

		virtual EventType GetType() { return EventType::KeyRelease; }
		static EventType GetStaticType() { return EventType::KeyRelease; }
		static EventGroup GetGroups()
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


	class AFRL_API KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(uint8_t keyCode);
		virtual ~KeyRepeatEvent();

		virtual EventType GetType() { return EventType::KeyRepeat; }
		static EventType GetStaticType() { return EventType::KeyRepeat; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard
			);
		}

		uint8_t GetKeyCode();

	private:
		uint8_t m_KeyCode;
	};


	class AFRL_API KeyTypeEvent : public Event
	{
	public:
		KeyTypeEvent(uint8_t charCode);
		virtual ~KeyTypeEvent();

		virtual EventType GetType() { return EventType::KeyType; }
		static EventType GetStaticType() { return EventType::KeyType; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard
			);
		}

		uint8_t GetCharCode();

	private:
		uint8_t m_CharCode;
	};
}