/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:34:45 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/02 23:20:56 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
	{
		char c = literal[1];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
	}
	else if (isInt(literal))
	{
		int i = std::atoi(literal.c_str());
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	}
	else if (isFloat(literal))
	{
		float f = std::strtof(literal.c_str(), NULL);
		handleSpecialCases(f);
	}
	else if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		handleSpecialCases(d);
	}
	else
	{
		handleImpossible("char");
		handleImpossible("int");
		handleImpossible("float");
		handleImpossible("double");
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal)
{
	char* end;
	long value = std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
	{
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
	char* end;
	std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
	char* end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::printChar(char c)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalarConverter::handleImpossible(const std::string& type)
{
	std::cout << type << ": impossible" << std::endl;
}

void ScalarConverter::handleSpecialCases(float f)
{
	if (std::isnan(f) || std::isinf(f))
	{
		handleImpossible("char");
		handleImpossible("int");
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
	else
	{
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
}

void ScalarConverter::handleSpecialCases(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		handleImpossible("char");
		handleImpossible("int");
		printFloat(static_cast<float>(d));
		printDouble(d);
	}
	else
	{
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	}
}
