#include "AfrlPch.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	std::string AFRL_API ToString(MouseButton _Val)
	{
		switch (_Val)
		{
			case MouseButton::Left:
				return std::string("Left Mouse");
			case MouseButton::Right:
				return std::string("Right Mouse");
			case MouseButton::Middle:
				return std::string("Middle Mouse");
			case MouseButton::XButton1:
				return std::string("XButton1");
			case MouseButton::XButton2:
				return std::string("XButton2");

			default:
				return std::string("Unknown Mouse Button");
		}
	}
	std::string AFRL_API ToString(KeyCode _Val)
	{
		static const char* strings[] = {
			"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
			"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
			"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
			"Up Arrow", "Down Arrow", "Left Arrow", "Right Arrow",
			"Num Pad Multiply", "Num Pad Plus", "Num Pad Minus", "Num Pad Period", "Num Pad Divide", "Num Pad Enter", "Num Lock",
			"Num Pad 0", "Num Pad 1", "Num Pad 2", "Num Pad 3", "Num Pad 4", "Num Pad 5", "Num Pad 6", "Num Pad 7", "Num Pad 8", "Num Pad 9",
			"Grave Accent", "Minus", "Plus", "Left Bracket", "Right Bracket", "Back Slash", "Semi Colon", "Apostrophe", "Comma", "Period", "Slash",
			"Escape", "Back Scape", "Enter", "Right Shift", "Right Control", "Applications", "Right Menu", "Right Alt", "Space", "Left Alt", "Left Menu", "Left Control", "Left Shift", "Caps Lock", "Tab",
			"Print Screen", "Scroll Lock", "Pause", "Insert", "Home", "Page Up", "Delete", "End", "Page Down"
		};

		if (0 <= (int)_Val && (int)_Val <= 103)
			return std::string(strings[(int)_Val]);
		else
			return std::string("Unknown Key Code");
	}
}