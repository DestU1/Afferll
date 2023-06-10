#include "Logger.h"


namespace Afferll
{
	Logger::Logger(std::string prefix, LogLevel logLevel)
		: m_Prefix(prefix), m_LogLevel(logLevel)
	{
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

	std::string Logger::Format(std::string fmt, int i)
	{
		std::string msg = std::string(fmt);
		bool openFound = false;
		bool closeFound = false;

		for (int msgIndex = i; fmt[i]; ++i, ++msgIndex)
		{
			if (openFound)
			{
				if (fmt[i] == '{')
				{
					msg.replace(msgIndex, 1, "");
					--msgIndex;
					openFound = false;
					continue;
				}
				else if (fmt[i] == '}')
				{
					throw std::exception("Format string place holders and argument number missmatch.");
				}
				else
				{
					throw std::exception("Invalid character.");
				}
			}

			if (closeFound)
			{
				if (fmt[i] == '}')
				{
					msg.replace(msgIndex, 1, "");
					--msgIndex;
					closeFound = false;
					continue;
				}
				else
				{
					throw std::exception("Invalid character.");
				}
			}

			openFound = fmt[i] == '{';
			closeFound = fmt[i] == '}';
		}

		return msg;
	}

	
}