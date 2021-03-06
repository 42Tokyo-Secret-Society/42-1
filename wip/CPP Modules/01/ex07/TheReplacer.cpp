/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheReplacer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:32:52 by ecaceres          #+#    #+#             */
/*   Updated: 2020/01/03 11:32:56 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stddef.h>

#include "TheReplacer.hpp"
#include "Common.hpp"

TheReplacer::TheReplacer(std::string file, std::string s1, std::string s2)
{
	this->_file = file;
	this->_s1 = s1;
	this->_s2 = s2;

	this->_outFile = Common::get_file_name(file).append(".replace");
}

int
TheReplacer::_readInputFile(std::string &dest)
{
	this->_in.open(this->_file);

	if (errno)
	{
		return (errno);
	}

	if (this->_in.is_open())
	{
		std::string line;
		while (std::getline(this->_in, line))
		{
			dest.append(line);

			if (!this->_in.eof())
			{
				dest.append("\n");
			}
		}
	}

	return (0);
}

int
TheReplacer::_writeOutputFile(std::string &src)
{
	this->_out.open(this->_outFile);

	if (errno)
	{
		return (errno);
	}

	if (this->_out.is_open())
	{
		this->_out << src;
	}

	return (0);
}

void
TheReplacer::_closeStreams(void)
{
	if (this->_in.is_open())
	{
		this->_in.close();
	}

	if (this->_out.is_open())
	{
		this->_out.close();
	}
}

int
TheReplacer::replace(void)
{
	int error;

	std::string input;
	if ((error = _readInputFile(input)))
	{
		return (error);
	}

	size_t start = 0;
	size_t charIndex;

	std::string replaced;

	if (this->_s1 == this->_s2)
	{
		replaced = input;
	}
	else
	{
		while (true)
		{
			charIndex = Common::strict_strstr(input, this->_s1, start);

			if (charIndex == (size_t)-1)
			{
				replaced.append(input, start, input.length());
				break;
			}

			replaced.append(input, start, charIndex - start);
			replaced.append(this->_s2);

			start = charIndex + this->_s1.length();
		}
	}

	if ((error = _writeOutputFile(replaced)))
	{
		return (error);
	}

	if (DEBUG_REPLACER)
	{
		std::cout << "OUT FILE : " << this->_outFile << std::endl;
		std::cout << "s1       : ..." << this->_s1 << "..." << std::endl;
		std::cout << "s2       : ..." << this->_s2 << "..." << std::endl;
		std::cout << "input    : ..." << input << "..." << std::endl;
		std::cout << "output   : ..." << replaced << "..." << std::endl;
	}

	return (0);
}
