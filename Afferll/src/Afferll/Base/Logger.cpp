#include "AfrlPch.h"
#include "Afferll/Base/Logger.h"


namespace Afferll
{
	Logger::LogLevel Logger::s_CurrentColor = Logger::LogLevel::Info;
	std::mutex Logger::s_LogLock;

	Logger Logger::s_EngineLogger("Engine");
	Logger Logger::s_Logger("Logger");

	Logger::Logger(std::string prefix, LogLevel logLevel)
		: m_Prefix(prefix), m_LogLevel(logLevel)
	{
		SetColor(m_LogLevel);
	}
	Logger::~Logger()
	{
	}

	void Logger::SetLogLevel(LogLevel logLevel)
	{
		m_LogLevel = logLevel;
	}
	void Logger::SetPrefix(const char* prefix)
	{
		m_Prefix = prefix;
	}
	void Logger::SetColor(LogLevel logLevel) const
	{
		s_CurrentColor = logLevel;
		printf(GetColorString(logLevel).c_str());
	}
	std::string Logger::GetColorString(LogLevel logLevel) const
	{
		s_CurrentColor = logLevel;

		// "\x1B[0m" reset color, "\x1B[38;2;{r};{g};{b}m" set color
		switch (logLevel)
		{
			case LogLevel::Debug:
				return std::string("\x1B[38;2;0;255;255m");

			case LogLevel::Info:
				return std::string("\x1B[38;2;255;255;255m");

			case LogLevel::Success:
				return std::string("\x1B[38;2;0;255;0m");

			case LogLevel::Warning:
				return std::string("\x1B[38;2;255;255;0m");

			case LogLevel::Error:
				return std::string("\x1B[38;2;255;0;0m");

			case LogLevel::Fatal:
				return std::string("\x1B[38;2;150;0;0m");

			default:
				return std::string("\x1B[38;2;255;255;255m");
		}
	}

	std::string Logger::Format(std::string& fmt, uint64_t i) const
	{
		bool placeHolderFound = false;

		for (; fmt[i]; ++i)
		{
			if (placeHolderFound)
			{
				if (fmt[i] == fmt[i - 1])
				{
					// str: *{{ -> {*{ -> {* -> *{ -> {*, same with '}'
					fmt.replace(i, 1, "");
					--i;
					placeHolderFound = false;
					continue;
				}

				else if (fmt[i] == '}') // str: *{} -> {*}
					throw std::exception("Format string place-holder count and argument number missmatch.");

				else // str: *{ with no matching '{' or '}', and vice versa with '}'
					throw std::exception("Invalid character.");
			}

			placeHolderFound = fmt[i] == '{' || fmt[i] == '}';
		}
		if (placeHolderFound) // Place holder at end of string
			throw std::exception("Invalid character.");

		return fmt;
	}


	std::string AFRL_API ToString(Logger::LogLevel _Val)
	{
		switch (_Val)
		{
		case Logger::LogLevel::Debug:
			return std::string("Debug");
		case Logger::LogLevel::Info:
			return std::string("Info");
		case Logger::LogLevel::Success:
			return std::string("Success");
		case Logger::LogLevel::Warning:
			return std::string("Warning");
		case Logger::LogLevel::Error:
			return std::string("Error");
		case Logger::LogLevel::Fatal:
			return std::string("Fatal");

		default:
			return std::string("Unknown log level");
		}
	}
}