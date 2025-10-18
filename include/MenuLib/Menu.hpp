/*
 * Menu.hpp
 * Written By : Cameron Ross
 * Last Edit  : October 18, 2025
 */
#pragma once
#include "Option.hpp"
#include <functional>
#include <string>

class Menu
{
public:
	Menu(const std::string &, bool); // initializer

	// add an option to the menu
	void addOption(const std::string &, std::function<void()>);
	void display(); // funcion displays menu info
	void run();     // display and take/validate input

private:
	std::string title;
	std::vector<Option> options;
	int numberOfOptions;
};
