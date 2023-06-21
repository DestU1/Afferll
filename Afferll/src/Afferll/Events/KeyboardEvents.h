#pragma once
#include "Afferll/Events/Event.h"
#include "KeyCode.h"


namespace Afferll
{
	class AFRL_API KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(KeyCode keyCode);
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

		KeyCode GetKeyCode();

	private:
		KeyCode m_KeyCode;
	};


	class AFRL_API KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(KeyCode keyCode);
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

		KeyCode GetKeyCode();

	private:
		KeyCode m_KeyCode;
	};


	class AFRL_API KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(KeyCode keyCode);
		virtual ~KeyRepeatEvent();

		virtual EventType GetType() { return EventType::KeyRepeat; }
		static EventType GetStaticType() { return EventType::KeyRepeat; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard
			);
		}

		KeyCode GetKeyCode();

	private:
		KeyCode m_KeyCode;
	};


	class AFRL_API KeyTypeEvent : public Event
	{
	public:
		KeyTypeEvent(char _char);
		virtual ~KeyTypeEvent();

		virtual EventType GetType() { return EventType::KeyType; }
		static EventType GetStaticType() { return EventType::KeyType; }
		static EventGroup GetGroups()
		{
			return (EventGroup)(
				(uint64_t)EventGroup::Keyboard
			);
		}

		char GetChar();

	private:
		char m_Char;
	};
}