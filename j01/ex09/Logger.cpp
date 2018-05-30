#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>

Logger::Logger(std::string const &file) : _filename(file)
{

}

Logger::~Logger()
{

}

void Logger::logToConsole(std::string const &message) const
{
	std::cout << this->makeLogEntry(message) << std::endl;
}

void Logger::logToFile(std::string const &message) const
{
	std::ofstream	file;
	if (!file.is_open())
		file.open(this->_filename.c_str());
	if (!file.is_open()) // bein ui
	{
		std::cout << "Error: Unable to open the log file, redirecting to the console : ";
		this->logToConsole(message);
		return;
	}
	file << this->makeLogEntry(message) << std::endl;

}

std::string Logger::makeLogEntry(std::string const &message) const
{
	std::time_t	now = time(0);
	std::string	res;
	char		buf[19]; // alo la polis

	buf[18] = '\0';
	std::tm *ltm = localtime(&now);
	std::strftime(buf,18,"[%Y%m%d-%H%M%S] ",ltm);
	res = buf;
	res = "[" + res + message + "]";
	return (res);
}

typedef void(Logger::*humanMethodCall)(std::string const &); // le std::string const c'est pas le nom mais le target

void	Logger::log(std::string const & dest, std::string const & message) {

	std::map<std::string, humanMethodCall> myMap;
	myMap["logToFile"] = &Logger::logToFile;
	myMap["makeLogEntry"] = &Logger::makeLogEntry;
	myMap["logToConsole"] = &Logger::logToConsole;

	if ((myMap.count(dest)) == 0)
	{
		std::cout << "attempt to call method : " << dest << " which is invalid" << std::endl;
		return;
	}

	humanMethodCall call = myMap[dest];
	(this->*call)(message);
}