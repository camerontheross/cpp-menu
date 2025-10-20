/*
 * Menu.cpp
 * Written By : Cameron Ross
 * Last Edit  : October 20, 2025
 */
#include "Menu.hpp"
#include <iostream>

namespace cppmenu
{

Menu::Menu(const std::string &menuTitle, bool isMainMenu)
{
	title = menuTitle;

	// adds a quit option for the main menu
	// adds a back option for the sub menus
	std::string quitLabel = isMainMenu ? "Quit" : "Back";
	// calls return when option is selected
	addOption(quitLabel, [this] { return; });
}

void Menu::display()
{

	std::cout << "\n##### " << title << "#####\n";

	// loop thru options and print labels
	for (int i = 0; i < numberOfOptions; i++)
	{
		std::cout << i << ". " << options[i].label << "\n";
	}
	std::cout << std::endl;
}
void Menu::run()
{
	// stores user choice
	// will select an option
	int choice;

	display();
	std::cout << "Enter choice: ";

	std::cin >> choice;

	bool validInput =
	    !(std::cin.fail() || choice < 0 || choice > numberOfOptions - 1);

	if (!validInput)
	{
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "Invalid input.\n";
	}
	else if (choice == 0)
	{
		return;
	}
	else
	{
		options[choice].action();
	}

	run();
}
void Menu::addOption(const std::string &label, std::function<void()> action)
{
	Option newOption;
	newOption.label = label;
	newOption.action = action;

	options.push_back(newOption);

	numberOfOptions = options.size();
}
} // namespace cppmenu
