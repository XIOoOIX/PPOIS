#ifndef DEMOLITION_PROJECT_H
#define DEMOLITION_PROJECT_H

#include "Project.h"

/**
 * @brief Project for building demolition.
 */
class DemolitionProject : public Project {
private:
    bool permitApproved;    ///< Demolition permit status.
    int workersInvolved;    ///< Number of workers.
    bool debrisRemoved;     ///< Debris cleanup status.

public:
    /**
     * @brief Constructs a demolition project.
     * @param name Project name.
     * @param projectBudget Project budget.
     * @param client Pointer to client.
     */
    DemolitionProject(const std::string& name, double projectBudget, Client* client);

    /**
     * @brief Requests demolition permit.
     */
    void RequestPermit();

    /**
     * @brief Removes debris from site.
     */
    void RemoveDebris();

    /**
     * @brief Calculates demolition project costs.
     */
    void CalculateCost() override;

    /**
     * @brief Completes demolition project workflow.
     */
    void CompleteProject() override;
};

#endif // DEMOLITION_PROJECT_H
