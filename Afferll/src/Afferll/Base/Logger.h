#pragma once
#include "Afferll/Base/Base.h"
#include "Afferll/ToString.h"


namespace Afferll
{
	class AFRL_API Logger
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
		void Massage(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Debug(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Info(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Success(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Warning(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Error(const char* msg, Args ...args) const;
		template <typename ...Args>
		void Fatal(const char* msg, Args ...args) const;


		static Logger s_EngineLogger;
		static Logger s_Logger;

	private:
		void SetColor(LogLevel logLevel) const;
		std::string GetColorString(LogLevel logLevel) const;

		template <typename ...Args>
		void Log(LogLevel logLevel, const char* msg, Args ...args) const;

		template <class T, typename ...Args>
		std::string Format(std::string& fmt, uint64_t i, T arg, Args ...args) const;
		std::string Format(std::string& fmt, uint64_t i) const;


		std::string m_Prefix;
		LogLevel m_LogLevel;

		static LogLevel s_CurrentColor;
		static std::mutex s_LogLock;
	};


	template<>
	inline AFRL_API std::string ToString<Logger::LogLevel>(Logger::LogLevel _Val)
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


	template<typename ...Args>
	inline void Logger::Massage(const char* msg, Args ...args) const
	{
		Log(m_LogLevel, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Debug(const char* msg, Args ...args) const
	{
		Log(LogLevel::Debug, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Info(const char* msg, Args ...args) const
	{
		Log(LogLevel::Info, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Success(const char* msg, Args ...args) const
	{
		Log(LogLevel::Success, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Warning(const char* msg, Args ...args) const
	{
		Log(LogLevel::Warning, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Error(const char* msg, Args ...args) const
	{
		Log(LogLevel::Error, msg, args...);
	}
	template<typename ...Args>
	inline void Logger::Fatal(const char* msg, Args ...args) const
	{
		Log(LogLevel::Fatal, msg, args...);
	}

	template<typename ...Args>
	inline void Logger::Log(LogLevel logLevel, const char* msg, Args ...args) const
	{
		// TODO: acquire lock just before printing to hold it for as little as possible
		std::lock_guard<std::mutex> lock(s_LogLock);

		char time[9];
		std::time_t now = std::time(0);
		std::strftime(time, sizeof(time), "%H:%M:%S", localtime(&now));

		std::string strMsg = std::string(msg); // required for some reason
		printf("%s[%s] %s (%s) - %s\n",
			((s_CurrentColor != logLevel) ? GetColorString(logLevel).c_str() : ""),
			time,
			m_Prefix.c_str(),
			ToString(logLevel).c_str(),
			Format(strMsg, 0, args...).c_str()
		);
	}

	template<class T, typename ...Args>
	inline std::string Logger::Format(std::string& fmt, uint64_t i, T arg, Args ...args) const
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

				else if (fmt[i] == '}')
				{
					// str: *{} -> {*} -> *({} was here) -> *arg -> arg*
					fmt.replace(i - 1, 2, "");
					--i;

					std::string argStr = ToString(arg);
					fmt.insert(i, argStr);
					i += argStr.length();

					return Format(fmt, i, args...);
				}

				else // str: *{ with no matching '{' or '}', and vice versa with '}'
					throw std::exception("Invalid character.");
			}

			placeHolderFound = fmt[i] == '{' || fmt[i] == '}';
		}
		if (placeHolderFound) // Place holder at end of string
			throw std::exception("Invalid character.");

		return fmt;
	}
}