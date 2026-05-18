#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	// pseudo
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}

	// check: 1 caracter
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		unsigned char	c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return ;
	}

	// check: numbers + caracters
	char	*end;
	double	d = std::strtod(literal.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}

	// double	d = std::atof(literal.c_str());

	// char
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(d);
		if (!std::isprint(c) || (c >= 0 && c <= 31) || c == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (d >= 32 && d <= 126)
			std::cout << "char: '" << c << "'" << std::endl;
	}

	// int
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	// float
	if (d > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else if (d < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}
