#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Project;

/**
 * @brief Base class for all company employees.
 */
class Employee {
protected:
    std::string fullName;                 ///< Employee full name.
    std::string position;                 ///< Job position title.
    double salary;                        ///< Current salary value.
    bool active;                          ///< Employment status flag.
    std::vector<Project*> assignedProjects; ///< Projects assigned to the employee.

public:
    /**
     * @brief Constructs an employee with basic info.
     * @param name Employee name.
     * @param pos Position title.
     * @param sal Initial salary.
     */
    Employee(const std::string& name, const std::string& pos, double sal);

    /**
     * @brief Assigns the employee to work on a project.
     * @param project Pointer to project.
     */
    virtual void WorkOnProject(Project* project);

    /**
     * @brief Simulates a break for the employee.
     */
    virtual void TakeBreak();

    /**
     * @brief Adds payment to employee salary.
     * @param amount Payment amount.
     */
    virtual void ReceivePayment(double amount);

    /**
     * @brief Prints or sends a work report.
     */
    virtual void ReportWork() const;

    /**
     * @brief Dismisses the employee from the company.
     */
    virtual void Dismiss();

    /**
     * @brief Gets employee name.
     * @return Full name.
     */
    std::string GetName() const { return fullName; }

    /**
     * @brief Checks if employee is active.
     * @return True if still employed.
     */
    bool IsActive() const { return active; }

    /**
     * @brief Virtual destructor for polymorphic deletion.
     */
    virtual ~Employee() = default;
};

#endif // EMPLOYEE_H
