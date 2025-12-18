#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "Employee.h"

/**
 * @brief Accountant responsible for financial operations.
 */
class Accountant : public Employee {
private:
    double totalPayments;   ///< Sum of all processed payments.

public:
    /**
     * @brief Constructs an accountant with name and salary.
     * @param name Employee name.
     * @param sal Salary value.
     */
    Accountant(const std::string& name, double sal);

    /**
     * @brief Calculates salaries or payroll.
     */
    void CalculateSalary();

    /**
     * @brief Pays salary to another employee.
     * @param employee Pointer to employee.
     * @param amount Payment amount.
     */
    void PayEmployee(Employee* employee, double amount);

    /**
     * @brief Accountant-specific work on a project.
     * @param project Pointer to project.
     */
    void WorkOnProject(Project* project) override;
};

#endif // ACCOUNTANT_H
