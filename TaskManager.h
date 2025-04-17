#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>

struct Task {
    int id;
    std::string description;
    int priority;
};

class TaskManager {
public:
    TaskManager();

    void addTask(const std::string& desc, int priority);
    void listTasks() const;
    bool removeTask(int id);

private:
    std::vector<Task> tasks;
    int nextId;
};

#endif
