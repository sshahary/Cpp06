/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:34:45 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/03 17:47:45 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(const std::string& literal)
{
	bool isSpecial = (literal == "nan" || literal == "+inf" || literal == "-inf" ||
					  literal == "nanf" || literal == "+inff" || literal == "-inff");
	try
	{
		if (isSpecial)
		{
			std::cout << "char: impossible" << std::endl;
		}
		else
		{
			int i = std::atoi(literal.c_str());
			if (i >= 32 && i <= 126)
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
	}

	try
	{
		if (isSpecial)
		{
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			int i = std::atoi(literal.c_str());
			std::cout << "int: " << i << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		float f = std::strtof(literal.c_str(), NULL);
		if (std::isnan(f) || std::isinf(f))
			std::cout << "float: " << f << "f" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		double d = std::strtod(literal.c_str(), NULL);
		if (std::isnan(d) || std::isinf(d))
			std::cout << "double: " << d << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "double: " << d << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isInt(const std::string& literal)
{
	char* end;
	long value = std::strtol(literal.c_str(), &end, 10);
	return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	char* end;
	std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	char* end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}
