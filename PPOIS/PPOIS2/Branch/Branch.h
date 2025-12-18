#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <vector>
#include <memory>

class Place;
class Employee;
class Project;

/**
 * @brief Represents a branch of the company.
 */
class Branch {
private:
    std::string branchName;                 ///< Branch name.
    std::string city;                       ///< City where branch is located.
    std::vector<Employee*> employees;      ///< Employees working at the branch.
    std::vector<Project*> localProjects;     ///< Projects managed by the branch.
    double localBudget;                     ///< Local budget of the branch.
    bool active;                            ///< Flag indicating if branch is active.

public:
    /**
     * @brief Constructs a branch with name and city.
     * @param name Branch name.
     * @param city City name.
     */
    Branch(const std::string& name, const std::string& city);

    /**
     * @brief Adds an employee to the branch.
     * @param employee Pointer to employee.
     */
    void AddEmployee(Employee* employee);

    /**
     * @brief Removes an employee by name.
     * @param employeeName Employee name.
     */
    void RemoveEmployee(const std::string& employeeName);

    /**
     * @brief Assigns a project to the branch.
     * @param project Pointer to project.
     */
    void AssignProject(Project* project);

    /**
     * @brief Marks a local project as completed.
     * @param project Pointer to project.
     */
    void CompleteLocalProject(Project* project);

    /**
     * @brief Increases local branch budget.
     * @param amount Amount to add.
     */
    void IncreaseBudget(double amount);

    /**
     * @brief Decreases local branch budget.
     * @param amount Amount to subtract.
     */
    void DecreaseBudget(double amount);

    /**
     * @brief Transfers an employee to another branch.
     * @param employee Pointer to employee.
     * @param anotherBranch Target branch.
     */
    void TransferEmployee(Employee* employee, Branch* anotherBranch);

    /**
     * @brief Prints current status of the branch.
     */
    void InspectStatus() const;

    /**
     * @brief Closes the branch and marks it inactive.
     */
    void CloseBranch();

    /**
     * @brief Gets city of the branch.
     * @return City name.
     */
    std::string GetCity() const { return city; }

    /**
     * @brief Checks if branch is active.
     * @return True if active.
     */
    bool IsActive() const { return active; }
};

#endif // BRANCH_H
