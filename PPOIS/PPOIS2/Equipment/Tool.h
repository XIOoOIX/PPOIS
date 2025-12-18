#ifndef TOOL_H
#define TOOL_H

#include "Equipment.h"

/**
 * @brief Portable construction tool.
 */
class Tool : public Equipment {
protected:
    double weight;     ///< Tool weight.
    bool powered;      ///< True if tool is powered (electric, pneumatic, etc.).

public:
    /**
     * @brief Constructs a tool with basic characteristics.
     * @param name Tool name.
     * @param cost Tool cost.
     * @param w Tool weight.
     * @param poweredTool True if powered.
     */
    Tool(const std::string& name, double cost, double w, bool poweredTool);

    /**
     * @brief Uses the tool on site.
     */
    void UseTool();

    /**
     * @brief Repairs the tool and restores working state.
     */
    void Repair();

    /**
     * @brief Checks current tool condition.
     */
    void CheckCondition() const;

    /**
     * @brief Prints detailed information about the tool.
     */
    void PrintInfo() const override;
};

#endif // TOOL_H
