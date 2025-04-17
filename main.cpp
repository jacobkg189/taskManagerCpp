#include "TaskManager.h"
#include <iostream>

void printMenu() {
    std::cout << "\nTask Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. List Tasks\n";
    std::cout << "3. Remove Task\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();
            std::string desc;
            int priority;
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            std::cout << "Enter task priority (higher number = higher priority): ";
            std::cin >> priority;
            manager.addTask(desc, priority);
        } else if (choice == 2) {
            manager.listTasks();
        } else if (choice == 3) {
            int id;
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;
            manager.removeTask(id);
        } else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
