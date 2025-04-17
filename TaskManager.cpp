#include "TaskManager.h"
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addTask(const std::string& desc, int priority) {
    Task newTask{nextId++, desc, priority};
    tasks.push_back(newTask);
    std::cout << "Task added: [" << newTask.id << "] " << newTask.description << "\n";
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks to show.\n";
        return;
    }

    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority; 
    });

    std::cout << "ID\tPriority\tDescription\n";
    for (const auto& task : sortedTasks) {
        std::cout << task.id << "\t" << task.priority << "\t\t" << task.description << "\n";
    }
}

bool TaskManager::removeTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task " << id << " removed.\n";
        return true;
    } else {
        std::cout << "Task ID " << id << " not found.\n";
        return false;
    }
}
