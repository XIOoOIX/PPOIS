#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

/**
 * @brief Construction worker on the site.
 */
class Worker : public Employee {
private:
    std::string specialization;   ///< Worker specialization (e.g. concrete, welding).

public:
    /**
     * @brief Constructs a worker with specialization.
     * @param name Employee name.
     * @param sal Salary value.
     * @param spec Specialization description.
     */
    Worker(const std::string& name, double sal, const std::string& spec);

    /**
     * @brief Performs a specific construction task.
     */
    void PerformTask();

    /**
     * @brief Worker-specific work on a project.
     * @param project Pointer to project.
     */
    void WorkOnProject(Project* project) override;
};

#endif // WORKER_H
