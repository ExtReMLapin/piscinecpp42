#pragma once

#include <string>

class Logger
{
public:
		Logger(std::string const &file);
		~Logger();
		void log(std::string const & dest, std::string const & message);
private:
		void logToConsole(std::string const &message) const;
		void logToFile(std::string const &message) const;
		std::string makeLogEntry(std::string const &message) const;
		std::string const _filename;
};