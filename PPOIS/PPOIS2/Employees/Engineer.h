#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

/**
 * @brief Engineer who designs and checks constructions.
 */
class Engineer : public Employee {
private:
    bool blueprintReady;    ///< Flag indicating if blueprint is prepared.

public:
    /**
     * @brief Constructs an engineer with name and salary.
     * @param name Employee name.
     * @param sal Salary value.
     */
    Engineer(const std::string& name, double sal);

    /**
     * @brief Creates a new blueprint.
     */
    void CreateBlueprint();

    /**
     * @brief Approves prepared blueprint.
     */
    void ApproveBlueprint();

    /**
     * @brief Engineer-specific work on a project.
     * @param project Pointer to project.
     */
    void WorkOnProject(Project* project) override;
};

#endif // ENGINEER_H
