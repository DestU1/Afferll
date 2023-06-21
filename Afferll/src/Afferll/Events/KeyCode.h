#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	enum class AFRL_API MouseButton : int
	{
		Invalid = -1,

		Left = 0,
		Right = 1,
		Middle = 2,
		XButton1 = 3,
		XButton2 = 4
	};
	enum class AFRL_API KeyCode : int
	{
		Invalid = -1,

		D0 = 0,
		D1 = 1,
		D2 = 2,
		D3 = 3,
		D4 = 4,
		D5 = 5,
		D6 = 6,
		D7 = 7,
		D8 = 8,
		D9 = 9,

		A = 10,
		B = 11,
		C = 12,
		D = 13,
		E = 14,
		F = 15,
		G = 16,
		H = 17,
		I = 18,
		J = 19,
		K = 20,
		L = 21,
		M = 22,
		N = 23,
		O = 24,
		P = 25,
		Q = 26,
		R = 27,
		S = 28,
		T = 29,
		U = 30,
		V = 31,
		W = 32,
		X = 33,
		Y = 34,
		Z = 35,

		F1 = 36,
		F2 = 37,
		F3 = 38,
		F4 = 39,
		F5 = 40,
		F6 = 41,
		F7 = 42,
		F8 = 43,
		F9 = 44,
		F10 = 45,
		F11 = 46,
		F12 = 47,

		UpArrow = 48,
		DownArrow = 49,
		LeftArrow = 50,
		RightArrow = 51,

		NumPadMultiply = 52,
		NumPadPlus = 53,
		NumPadMinus = 54,
		NumPadPeriod = 55,
		NumPadDivide = 56,
		NumPadEnter = 57,
		NumLock = 58,
		NumPad0 = 59,
		NumPad1 = 60,
		NumPad2 = 61,
		NumPad3 = 62,
		NumPad4 = 63,
		NumPad5 = 64,
		NumPad6 = 65,
		NumPad7 = 66,
		NumPad8 = 67,
		NumPad9 = 68,

		GraveAccent = 69,
		Minus = 70,
		Plus = 71,
		LeftBracket = 72,
		RightBracket = 73,
		BackSlash = 74,
		SemiColon = 75,
		Apostrophe = 76,
		Comma = 77,
		Period = 78,
		Slash = 79,

		Escape = 80,
		BackScape = 81,
		Enter = 82,
		RightShift = 83,
		RightControl = 84,
		Applications = 85,
		RightMenu = 86,
		RightAlt = 87,
		Space = 88,
		LeftAlt = 89,
		LeftMenu = 90,
		LeftControl = 91,
		LeftShift = 92,
		CapsLock = 93,
		Tab = 94,

		PrintScreen = 95,
		ScrollLock = 96,
		Pause = 97,
		Insert = 98,
		Home = 99,
		PageUp = 100,
		Delete = 101,
		End = 102,
		PageDown = 103
	};


	template <>
	inline AFRL_API std::string ToString(MouseButton _Val)
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
	template <>
	inline AFRL_API std::string ToString(KeyCode _Val)
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