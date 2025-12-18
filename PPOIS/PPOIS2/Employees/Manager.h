#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Employee;

/**
 * @brief Manager controlling projects and subordinates.
 */
class Manager : public Employee {
private:
    int managedProjects;   ///< Number of projects under management.

public:
    /**
     * @brief Constructs a manager with name and salary.
     * @param name Employee name.
     * @param sal Salary value.
     */
    Manager(const std::string& name, double sal);

    /**
     * @brief Assigns a task to an employee.
     * @param employee Pointer to employee.
     */
    void AssignTask(Employee* employee);

    /**
     * @brief Evaluates performance of subordinates.
     */
    void EvaluatePerformance();

    /**
     * @brief Plans a meeting with client or team.
     */
    void PlanMeeting();

    /**
     * @brief Manager-specific work on a project.
     * @param project Pointer to project.
     */
    void WorkOnProject(Project* project) override;
};

#endif // MANAGER_H
