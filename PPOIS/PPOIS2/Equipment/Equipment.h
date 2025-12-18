#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

/**
 * @brief Base class for all equipment and inventory.
 */
class Equipment {
protected:
    std::string name;      ///< Equipment name.
    double cost;           ///< Purchase or rental cost.
    bool working;          ///< Flag indicating if equipment is running.
    bool assignedToSite;   ///< Flag indicating if equipment is assigned to a site.

public:
    /**
     * @brief Constructs equipment with name and cost.
     * @param name Equipment name.
     * @param cost Equipment cost.
     */
    Equipment(const std::string& name, double cost);

    /**
     * @brief Starts equipment operation.
     */
    virtual void Start();

    /**
     * @brief Stops equipment operation.
     */
    virtual void Stop();

    /**
     * @brief Assigns equipment to a construction site.
     */
    virtual void AssignToSite();

    /**
     * @brief Prints short information about equipment.
     */
    virtual void PrintInfo() const;

    /**
     * @brief Checks if equipment is currently working.
     * @return True if running.
     */
    bool IsWorking() const { return working; }

    /**
     * @brief Virtual destructor for polymorphic use.
     */
    virtual ~Equipment() = default;

    /**
    * @brief Gets equipment name.
    * @return Name.
    */
    std::string GetName() const { return name; }
};

#endif // EQUIPMENT_H
