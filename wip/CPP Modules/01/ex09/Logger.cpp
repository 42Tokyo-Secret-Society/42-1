/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:32:52 by ecaceres          #+#    #+#             */
/*   Updated: 2020/01/03 11:32:56 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <errno.h>

#include "Logger.hpp"

#define ENSURE_DOUBLE_DIGIT(number) ((number < 10) ? "0" : "") << number

Logger::Logger(std::string file)
{
	this->_stream.open(file, std::ofstream::out | std::ofstream::app);

	if (!this->_stream.is_open())
	{
		this->log(DEST_CONSOLE, "WARNING: Failed to open output log file \"" + file + "\": " + strerror(errno));
	}
	else
	{
		this->_stream << std::endl;
	}
}

Logger::~Logger(void)
{
	if (this->_stream.is_open())
	{
		this->_stream.close();
	}
}

std::string
Logger::makeLogEntry(std::string msg)
{
	std::stringstream stream;

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    stream
		<< "["
		<< (now->tm_year + 1900)
		<< "/"
        << ENSURE_DOUBLE_DIGIT((now->tm_mon + 1))
		<< "/"
        << ENSURE_DOUBLE_DIGIT(now->tm_mday)
		<< " "
        << ENSURE_DOUBLE_DIGIT(now->tm_hour)
		<< ":"
        << ENSURE_DOUBLE_DIGIT(now->tm_min)
		<< ":"
        << ENSURE_DOUBLE_DIGIT(now->tm_sec)
        << "] "
        << msg;

    return (stream.str());
}

void
Logger::logToConsole(std::string msg)
{
	std::cout << msg << std::endl;
}

void
Logger::logToFile(std::string msg)
{
	if (this->_stream.is_open())
	{
		this->_stream << msg << std::endl;
	}
	else
	{
		std::cout << msg << " (FILE NOT OPEN)" << std::endl;
	}
}

void
Logger::log(std::string const &dest, std::string const &message)
{
	void (Logger::*methods[])(std::string) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};
	std::string names[] = {
		DEST_CONSOLE,
		DEST_FILE
	};

	int count = sizeof(names) / sizeof(std::string);

	int index;
	for (index = 0; index < count; index++)
	{
		void (Logger::*method)(std::string const) = methods[index];
		std::string name = names[index];

		if (name == dest)
		{
			std::string formatted = makeLogEntry(message);

			(this->*method)(formatted);
			break ;
		}
	}

	if (index >= count)
	{
		log(DEST_CONSOLE, "WARNING: Unknown log destination \"" + dest + "\". (message: \"" + message + "\")");
	}
}
