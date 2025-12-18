#include "Worker.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Worker::Worker(const std::string& name, double sal, const std::string& spec)
    : Employee(name, "Рабочий", sal), specialization(spec) {}

void Worker::PerformTask() {
    std::cout << fullName << " выполняет задачу (" << specialization << ").\n";
}

void Worker::WorkOnProject(Project* project) {
    try {
        Employee::WorkOnProject(project);
        PerformTask();
    } catch (const std::exception& e) {
        std::cout << "Ошибка рабочего: " << e.what() << std::endl;
    }
}
