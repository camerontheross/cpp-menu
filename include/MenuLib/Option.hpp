/*
 * Option.hpp
 * Written By : Cameron Ross
 * Last Edit  : October 18, 2025
 */
#ifndef OPTION_HPP
#define OPTION_HPP

#include <functional>
#include <string>

struct Option
{
	// stores the name of the option
	std::string label;
	// stores the function the option will execute
	std::function<void()> action;
};

#endif
