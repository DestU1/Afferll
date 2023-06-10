#pragma once
#include "Base.h"

#include <string>
#include <stdio.h>
#include <exception>


namespace Afferll
{
	class Logger
	{
	public:
		enum class LogLevel
		{
			Debug,
			Info,
			Success,
			Warning,
			Error,
			Fatal
		};

	public:
		Logger(std::string prefix = "Unset", LogLevel logLevel = LogLevel::Info);
		~Logger();

		void SetLogLevel(LogLevel logLevel);
		void SetPrefix(const char* prefix);

		template <typename ...Args>
		void Massage(const char* msg, Args ...args);
		template <typename ...Args>
		void Debug(const char* msg, Args ...args);
		template <typename ...Args>
		void Info(const char* msg, Args ...args);
		template <typename ...Args>
		void Success(const char* msg, Args ...args);
		template <typename ...Args>
		void Warning(const char* msg, Args ...args);
		template <typename ...Args>
		void Error(const char* msg, Args ...args);
		template <typename ...Args>
		void Fatal(const char* msg, Args ...args);

	private:
		template <class T>
		std::string to_string(T _Val);

		template <typename ...Args>
		void Log(LogLevel logLevel, const char* msg, Args ...args);

		template <class T, typename ...Args>
		std::string Format(std::string fmt, int i, T arg, Args ...args);
		std::string Format(std::string fmt, int i);


		std::string m_Prefix;
		LogLevel m_LogLevel;
	};

	template<typename ...Args>
	inline void Logger::Massage(const char* msg, Args ...args)
	{
		Log(m_LogLevel, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Debug(const char* msg, Args ...args)
	{
		Log(LogLevel::Debug, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Info(const char* msg, Args ...args)
	{
		Log(LogLevel::Info, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Success(const char* msg, Args ...args)
	{
		Log(LogLevel::Success, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Warning(const char* msg, Args ...args)
	{
		Log(LogLevel::Warning, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Error(const char* msg, Args ...args)
	{
		Log(LogLevel::DebErrorug, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Fatal(const char* msg, Args ...args)
	{
		Log(LogLevel::Fatal, msg, args...);
	}
	
	template<class T>
	inline std::string Logger::to_string(T _Val)
	{
		return std::to_string(_Val);
	}
	template<>
	inline std::string Logger::to_string<bool>(bool _Val)
	{
		return std::string(_Val ? "True" : "False");
	}
	template<>
	inline std::string Logger::to_string<char>(char _Val)
	{
		return std::string(1, _Val);
	}
	template<>
	inline std::string Logger::to_string<const char*>(const char* _Val)
	{
		return std::string(_Val);
	}
	template<>
	inline std::string Logger::to_string<Logger::LogLevel>(LogLevel _Val)
	{
		switch (_Val)
		{
		case LogLevel::Debug:
			return std::string("Debug");

		case LogLevel::Info:
			return std::string("Info");

		case LogLevel::Success:
			return std::string("Success");

		case LogLevel::Warning:
			return std::string("Warning");

		case LogLevel::Error:
			return std::string("Error");

		case LogLevel::Fatal:
			return std::string("Fatal");

		default:
			return std::string("Unknown log level");
		}
	}

	template<typename ...Args>
	inline void Logger::Log(LogLevel logLevel, const char* msg, Args ...args)
	{
		// [hh::mm::ss] (logLevel) prefix - msg
		printf("[%s] (%s) %s - %s", "hh::mm::ss", to_string(logLevel).c_str(), m_Prefix.c_str(), Format(msg, 0, args...).c_str());
		printf("\n");
	}

	template<class T, typename ...Args>
	inline std::string Logger::Format(std::string fmt, int i, T arg, Args ...args)
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
					msg.replace(msgIndex - 1, 2, "");
					msgIndex -= 1;

					std::string argStr = to_string(arg);
					msg.insert(msgIndex, argStr);
					msgIndex += argStr.length();

					return Format(msg, msgIndex, args...);
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