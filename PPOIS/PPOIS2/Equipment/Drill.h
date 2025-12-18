#ifndef DRILL_H
#define DRILL_H

#include "Tool.h"

/**
 * @brief Power drill tool.
 */
class Drill : public Tool {
private:
    bool isDrilling;     ///<If drill is drilling.
    int power;          ///< Drill power in watts.
    bool safetyLock;    ///< Safety lock flag.

public:
    /**
     * @brief Constructs a drill with power value.
     * @param name Drill name.
     * @param cost Drill cost.
     * @param weight Drill weight.
     * @param power Drill power in watts.
     */
    Drill(const std::string& name, double cost, double weight, int power);

    /**
     * @brief Starts drilling operation.
     */
    void StartDrilling();

    /**
     * @brief Stops drilling operation.
     */
    void StopDrilling();

    /**
     * @brief Prints detailed information about the drill.
     */
    void PrintInfo() const override;
};

#endif // DRILL_H
