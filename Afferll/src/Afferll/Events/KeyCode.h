#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	enum class AFRL_API MouseButton
	{
		Invalid = -1,

		Left     = 0,
		Right    = 1,
		Middle   = 2,
		XButton1 = 3,
		XButton2 = 4
	};
	enum class AFRL_API KeyCode
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

		F1  = 36,
		F2  = 37,
		F3  = 38,
		F4  = 39,
		F5  = 40,
		F6  = 41,
		F7  = 42,
		F8  = 43,
		F9  = 44,
		F10 = 45,
		F11 = 46,
		F12 = 47,

		UpArrow    = 48,
		DownArrow  = 49,
		LeftArrow  = 50,
		RightArrow = 51,

		NumPadMultiply = 52,
		NumPadPlus     = 53,
		NumPadMinus    = 54,
		NumPadPeriod   = 55,
		NumPadDivide   = 56,
		NumPadEnter    = 57,
		NumLock        = 58,
		NumPad0        = 59,
		NumPad1        = 60,
		NumPad2        = 61,
		NumPad3        = 62,
		NumPad4        = 63,
		NumPad5        = 64,
		NumPad6        = 65,
		NumPad7        = 66,
		NumPad8        = 67,
		NumPad9        = 68,

		GraveAccent  = 69,
		Minus        = 70,
		Plus         = 71,
		LeftBracket  = 72,
		RightBracket = 73,
		BackSlash    = 74,
		SemiColon    = 75,
		Apostrophe   = 76,
		Comma        = 77,
		Period       = 78,
		Slash        = 79,

		Escape       = 80,
		BackScape    = 81,
		Enter        = 82,
		RightShift   = 83,
		RightControl = 84,
		Applications = 85,
		RightSuper   = 86,
		RightAlt     = 87,
		Space        = 88,
		LeftAlt      = 89,
		LeftSuper    = 90,
		LeftControl  = 91,
		LeftShift    = 92,
		CapsLock     = 93,
		Tab          = 94,

		PrintScreen = 95,
		ScrollLock  = 96,
		Pause       = 97,
		Insert      = 98,
		Home        = 99,
		PageUp      = 100,
		Delete      = 101,
		End         = 102,
		PageDown    = 103
	};


	std::string AFRL_API ToString(MouseButton _Val);
	std::string AFRL_API ToString(KeyCode _Val);
}