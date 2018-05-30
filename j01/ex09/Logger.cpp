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
		file.open(this->_filename.c_str(), std::ofstream::out | std::ofstream::app);
	if (!file.is_open()) // bein ui
	{
		std::cout << "Error: Unable to open the log file, redirecting to the console : ";
		this->logToConsole(message);
		return;
	}
	file << this->makeLogEntry(message) << std::endl;
	file.close();

}

std::string Logger::makeLogEntry(std::string const &message) const
{
	std::time_t	now = time(0);
	std::string	res;
	char		buf[19]; // alo la polis

	buf[18] = '\0';
	std::tm *ltm = localtime(&now);
	std::strftime(buf,18,"[%Y%m%d-%H%M%S] :",ltm);
	res = buf;
	res += message;
	return (res);
}

void	Logger::log(std::string const & dest, std::string const & msg)
{
	std::string	names[2] = {"logToConsole", "logToFile"};
	void	(Logger::*log_funcs[2])(std::string const &msg) const = {&Logger::logToConsole, &Logger::logToFile};
	void	(Logger::*log_func)(std::string const &msg) const;
	int		ind = 0;
	
	while (ind < 2 && names[ind] != dest)
		ind++;
	if (ind != 2)
	{
		log_func = log_funcs[ind];
		(this->*log_func)(msg);
	} 
}
