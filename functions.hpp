#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

	std::cout << "1. Add a task" << std::endl;
	std::cout << "2. Remove a task" << std::endl;
}

int get_user_choice() {
    int choice;
    std::cin >> choice;
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice" << std::endl;
        std::cin >> choice;
    }
    return choice;
}

void handle_user_choice(int choice, std::vector<std::string>& checklist) {
    std::string task; // Initialize task here
    switch (choice) {
    case 1:
        std::cout << "Enter a task:" << std::endl;
        std::cin.ignore(); // ignore any leftover characters in the buffer
        std::getline(std::cin, task);
        checklist.push_back(task);
        std::cout << "Task added" << std::endl;
        break;
    case 2:
        int task_num;
        std::cout << "Enter the task number to remove: ";
        std::cin >> task_num;
        if (task_num < 1 || task_num > checklist.size()) {
            std::cout << "Invalid task number" << std::endl;
        }
        else {
            checklist.erase(checklist.begin() + task_num - 1);
            std::cout << "Task removed" << std::endl;
        }
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}


void save_checklist_file(const std::string& filename, const std::vector<std::string>& checklist) {
    std::ofstream outfile(filename);
    for (const auto& task : checklist) {
        outfile << task << std::endl;
    }
}


bool should_continue() {
    char choice;
    std::cout << "Do you want to continue? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
