#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> read_checklist_file(const std::string& filename) {
    std::vector<std::string> checklist;
    std::ifstream infile(filename);
    std::string task;
    while (std::getline(infile, task)) {
        checklist.push_back(task);
    }
    return checklist;
}

void print_checklist(const std::vector<std::string>& checklist) {
    int numChoice = 1;
    for (const auto& task : checklist) {
        std::cout << numChoice << ". " << task << std::endl;
        numChoice++;
    }
    std::cout << std::endl << std::endl << "What would you like to do?" << std::endl;
    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. Remove a task" << std::endl;
    std::cout << "3. Search for a task" << std::endl;
}

int get_user_choice() {
    int choice;
    std::cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3) {
        std::cout << "Invalid choice" << std::endl;
        std::cin >> choice;
    }
    return choice;
}

void handle_user_choice(int choice, std::vector<std::string>& checklist) {
    std::string task; // Initialize task here
    bool found = false;
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
    case 3:
        std::cout << "Enter a search query:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, task);
        for (int i = 0; i < checklist.size(); i++) {
            if (checklist[i].find(task) != std::string::npos) {
                std::cout << i + 1 << ". " << checklist[i] << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No tasks found" << std::endl;
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
