#include <iostream>
#include <vector>
#include "functions.h"
#include <string>
#include <fstream>


int main() {

	std::vector<std::string> checklist;
	int numChoice = 1;
	int choice;
	char cont;
	std::string task;

	std::ifstream infile("checklist.txt");
	while (std::getline(infile, task))
	{
		checklist.push_back(task);
	}

	std::cout << "Welcome To My Coding Checklist" << std::endl << std::endl;

	for (int i = 0; i < checklist.size(); i++, numChoice++)
	{
		std::cout << numChoice << ". " << checklist[i] << std::endl;
	}

	std::cout << std::endl << std::endl << "What would you like to do?" << std::endl;

	print_menu();
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid choice" << std::endl;
		std::cin >> choice;
	}


	switch (choice)
	{
	case 1:
		std::cout << "Enter a task" << std::endl;
		std::cin.ignore(); // ignore any leftover characters in the buffer
		std::getline(std::cin, task);
		checklist.push_back(task);
		std::cout << "Task added" << std::endl;
		break;
	case 2:
		int task_num;
		std::cout << "Enter the task number to remove:" << std::endl;
		std::cin >> task_num;
		if (task_num < 1 || task_num > checklist.size())
		{
			std::cout << "Invalid task number" << std::endl;
			break;
		}
		else
		{
			checklist.erase(checklist.begin() + task_num - 1);
			std::cout << "Task removed" << std::endl;
		}
		break;
	default:
		std::cout << "Invalid choice" << std::endl;
		break;
	}

	std::ofstream outfile("checklist.txt");
	for (const auto& task : checklist) {
		outfile << task << std::endl;
	}

	//Continue or exit the program
	std::cout << std::endl << "Would you like to continue? (y/n)" << std::endl;
	std::cin >> cont;
	if (cont == 'y')
	{
		system("CLS");
		main();
		return 0; // add this line to terminate the program properly
	}
	else
	{
		system("CLS");
		std::cout << std::endl << "Goodbye" << std::endl;
		return 0; // add this line to terminate the program properly
	}
}
