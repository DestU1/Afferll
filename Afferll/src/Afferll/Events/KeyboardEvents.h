#pragma once
#include "Afferll/Events/Event.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	///////////////////////////////////////////////////////////
	// KeyPressEvent //////////////////////////////////////////
	///////////////////////////////////////////////////////////

	class AFRL_API KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(KeyCode keyCode);
		virtual ~KeyPressEvent() override;

		virtual EventType GetType() override { return EventType::KeyPress; }
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


	///////////////////////////////////////////////////////////
	// KeyReleaseEvent ////////////////////////////////////////
	///////////////////////////////////////////////////////////

	class AFRL_API KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(KeyCode keyCode);
		virtual ~KeyReleaseEvent() override;

		virtual EventType GetType() override { return EventType::KeyRelease; }
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


	///////////////////////////////////////////////////////////
	// KeyRepeatEvent /////////////////////////////////////////
	///////////////////////////////////////////////////////////

	class AFRL_API KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(KeyCode keyCode);
		virtual ~KeyRepeatEvent() override;

		virtual EventType GetType() override { return EventType::KeyRepeat; }
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


	///////////////////////////////////////////////////////////
	// KeyTypeEvent ///////////////////////////////////////////
	///////////////////////////////////////////////////////////

	class AFRL_API KeyTypeEvent : public Event
	{
	public:
		KeyTypeEvent(char _char);
		virtual ~KeyTypeEvent() override;

		virtual EventType GetType() override { return EventType::KeyType; }
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