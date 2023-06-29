#include "AfrlPch.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	std::string AFRL_API ToString(MouseButton _Val)
	{
		static const std::unordered_map<MouseButton, std::string> buttonMap({
			{ MouseButton::Invalid,  std::string("Unknown Mouse Button") },
			{ MouseButton::Left,     std::string("Left Mouse")           },
			{ MouseButton::Right,    std::string("Right Mouse")          },
			{ MouseButton::Middle,   std::string("Middle Mouse")         },
			{ MouseButton::XButton1, std::string("XButton1")             },
			{ MouseButton::XButton2, std::string("XButton2")             }
		});
		
		return buttonMap.contains(_Val) ? buttonMap.at(_Val) : buttonMap.at(MouseButton::Invalid);
	}
	std::string AFRL_API ToString(KeyCode _Val)
	{
		static const std::unordered_map<KeyCode, std::string> keyMap({
			{ KeyCode::Invalid, std::string("Unknown Key Code") },
			{ KeyCode::D0,      std::string("0")                },
			{ KeyCode::D1,      std::string("1")                },
			{ KeyCode::D2,      std::string("2")                },
			{ KeyCode::D3,      std::string("3")                },
			{ KeyCode::D4,      std::string("4")                },
			{ KeyCode::D5,      std::string("5")                },
			{ KeyCode::D6,      std::string("6")                },
			{ KeyCode::D7,      std::string("7")                },
			{ KeyCode::D8,      std::string("8")                },
			{ KeyCode::D9,      std::string("9")                },

			{ KeyCode::A, std::string("A") },
			{ KeyCode::B, std::string("B") },
			{ KeyCode::C, std::string("C") },
			{ KeyCode::D, std::string("D") },
			{ KeyCode::E, std::string("E") },
			{ KeyCode::F, std::string("F") },
			{ KeyCode::G, std::string("G") },
			{ KeyCode::H, std::string("H") },
			{ KeyCode::I, std::string("I") },
			{ KeyCode::J, std::string("J") },
			{ KeyCode::K, std::string("K") },
			{ KeyCode::L, std::string("L") },
			{ KeyCode::M, std::string("M") },
			{ KeyCode::N, std::string("N") },
			{ KeyCode::O, std::string("O") },
			{ KeyCode::P, std::string("P") },
			{ KeyCode::Q, std::string("Q") },
			{ KeyCode::R, std::string("R") },
			{ KeyCode::S, std::string("S") },
			{ KeyCode::T, std::string("T") },
			{ KeyCode::U, std::string("U") },
			{ KeyCode::V, std::string("V") },
			{ KeyCode::W, std::string("W") },
			{ KeyCode::X, std::string("X") },
			{ KeyCode::Y, std::string("Y") },
			{ KeyCode::Z, std::string("Z") },

			{ KeyCode::F1,  std::string("F1")  },
			{ KeyCode::F2,  std::string("F2")  },
			{ KeyCode::F3,  std::string("F3")  },
			{ KeyCode::F4,  std::string("F4")  },
			{ KeyCode::F5,  std::string("F5")  },
			{ KeyCode::F6,  std::string("F6")  },
			{ KeyCode::F7,  std::string("F7")  },
			{ KeyCode::F8,  std::string("F8")  },
			{ KeyCode::F9,  std::string("F9")  },
			{ KeyCode::F10, std::string("F10") },
			{ KeyCode::F11, std::string("F11") },
			{ KeyCode::F12, std::string("F12") },

			{ KeyCode::UpArrow,    std::string("Up Arrow")  },
			{ KeyCode::DownArrow,  std::string("Down Arrow") },
			{ KeyCode::LeftArrow,  std::string("Left Arrow") },
			{ KeyCode::RightArrow, std::string("Right Arrow") },

			{ KeyCode::NumPadMultiply, std::string("Num Pad Multiply") },
			{ KeyCode::NumPadPlus,     std::string("Num Pad Plus")     },
			{ KeyCode::NumPadMinus,    std::string("Num Pad Minus")    },
			{ KeyCode::NumPadPeriod,   std::string("Num Pad Period")   },
			{ KeyCode::NumPadDivide,   std::string("Num Pad Divide")   },
			{ KeyCode::NumPadEnter,    std::string("Num Pad Enter")    },
			{ KeyCode::NumLock,        std::string("Num Lock")         },
			{ KeyCode::NumPad0,        std::string("Num Pad 0")        },
			{ KeyCode::NumPad1,        std::string("Num Pad 1")        },
			{ KeyCode::NumPad2,        std::string("Num Pad 2")        },
			{ KeyCode::NumPad3,        std::string("Num Pad 3")        },
			{ KeyCode::NumPad4,        std::string("Num Pad 4")        },
			{ KeyCode::NumPad5,        std::string("Num Pad 5")        },
			{ KeyCode::NumPad6,        std::string("Num Pad 6")        },
			{ KeyCode::NumPad7,        std::string("Num Pad 7")        },
			{ KeyCode::NumPad8,        std::string("Num Pad 8")        },
			{ KeyCode::NumPad9,        std::string("Num Pad 9")        },

			{ KeyCode::GraveAccent,  std::string("Grave Accent")  },
			{ KeyCode::Minus,        std::string("Minus")         },
			{ KeyCode::Plus,         std::string("Plus")          },
			{ KeyCode::LeftBracket,  std::string("Left Bracket")  },
			{ KeyCode::RightBracket, std::string("Right Bracket") },
			{ KeyCode::BackSlash,    std::string("Back Slash")    },
			{ KeyCode::SemiColon,    std::string("Semi Colon")    },
			{ KeyCode::Apostrophe,   std::string("Apostrophe")    },
			{ KeyCode::Comma,        std::string("Comma")         },
			{ KeyCode::Period,       std::string("Period")        },
			{ KeyCode::Slash,        std::string("Slash")         },

			{ KeyCode::Escape,       std::string("Escape")        },
			{ KeyCode::BackScape,    std::string("Back Scape")    },
			{ KeyCode::Enter,        std::string("Enter")         },
			{ KeyCode::RightShift,   std::string("Right Shift")   },
			{ KeyCode::RightControl, std::string("Right Control") },
			{ KeyCode::Applications, std::string("Applications")  },
			{ KeyCode::RightSuper,   std::string("Right Super")   },
			{ KeyCode::RightAlt,     std::string("Right Alt")     },
			{ KeyCode::Space,        std::string("Space")         },
			{ KeyCode::LeftAlt,      std::string("Left Alt")      },
			{ KeyCode::LeftSuper,    std::string("Left Super")    },
			{ KeyCode::LeftControl,  std::string("Left Control")  },
			{ KeyCode::LeftShift,    std::string("Left Shift")    },
			{ KeyCode::CapsLock,     std::string("Caps Lock")	  },
			{ KeyCode::Tab,          std::string("Tab")			  },

			{ KeyCode::PrintScreen, std::string("Print Screen") },
			{ KeyCode::ScrollLock,  std::string("Scroll Lock ") },
			{ KeyCode::Pause,       std::string("Pause")        },
			{ KeyCode::Insert,      std::string("Insert")       },
			{ KeyCode::Home,        std::string("Home")         },
			{ KeyCode::PageUp,      std::string("Page Up")      },
			{ KeyCode::Delete,      std::string("Delete")       },
			{ KeyCode::End,         std::string("End")          },
			{ KeyCode::PageDown,    std::string("Page Down")    }
		});

		return keyMap.contains(_Val) ? keyMap.at(_Val) : keyMap.at(KeyCode::Invalid);
	}
}