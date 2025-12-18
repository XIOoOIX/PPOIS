#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

class Client;
class Employee;
class Material;
class Equipment;
class Place;

/**
 * @brief Base class for all construction projects.
 */
class Project {
protected:
    std::string projectName;     ///< Project name.
    double budget;               ///< Allocated budget.
    double actualCost;           ///< Actual spent amount.
    std::string startDate;       ///< Project start date.
    std::string endDate;         ///< Project completion date.
    bool completed;              ///< Completion status.
    Client* client;              ///< Client for the project.
    std::vector<Employee*> team; ///< Project team members.
    std::vector<Material*> materialsUsed; ///< Materials used.
    std::vector<Equipment*> equipmentUsed; ///< Equipment used.
    Place* location;             ///< Project location.

public:
    /**
     * @brief Constructs a project with client.
     * @param name Project name.
     * @param projectBudget Initial budget.
     * @param client Pointer to client.
     */
    Project(const std::string& name, double projectBudget, Client* client);

    /**
     * @brief Starts the project and sets start date.
     */
    virtual void StartProject();

    /**
     * @brief Marks project as completed.
     */
    virtual void CompleteProject();

    /**
     * @brief Adds material to project usage.
     * @param material Pointer to material.
     */
    virtual void AddMaterial(Material* material);

    /**
     * @brief Adds employee to project team.
     * @param employee Pointer to employee.
     */
    virtual void AddEmployee(Employee* employee);

    /**
     * @brief Adds equipment to project.
     * @param equipment Pointer to equipment.
     */
    virtual void AddEquipment(Equipment* equipment);

    /**
     * @brief Calculates current project costs.
     */
    virtual void CalculateCost();

    /**
     * @brief Approves technical blueprint.
     */
    virtual void ApproveBlueprint();

    /**
     * @brief Checks if project is completed.
     * @return True if finished.
     */
    bool IsCompleted() const { return completed; }

    /**
     * @brief Gets project name.
     * @return Name string.
     */
    std::string GetName() const { return projectName; }

    /**
     * @brief Gets project budget.
     * @return Budget value.
     */
    double GetBudget() const { return budget; }

    /**
     * @brief Virtual destructor for polymorphic use.
     */
    virtual ~Project() = default;
};

#endif // PROJECT_H
