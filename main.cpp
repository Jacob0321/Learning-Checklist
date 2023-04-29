#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"

const std::string CHECKLIST_FILE = "checklist.txt";

int main() {
    std::vector<std::string> checklist = read_checklist_file(CHECKLIST_FILE);

    std::cout << "Welcome To My Coding Checklist" << std::endl << std::endl;
    print_checklist(checklist);

    int choice = get_user_choice();
    handle_user_choice(choice, checklist);

    save_checklist_file(CHECKLIST_FILE, checklist);

    if (should_continue()) {
        system("CLS");
        main();
    }
    else {
        system("CLS");
        std::cout << std::endl << "Goodbye" << std::endl;
        return 0;
    }
}
