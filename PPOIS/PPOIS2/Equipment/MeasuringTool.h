#ifndef MEASURING_TOOL_H
#define MEASURING_TOOL_H

#include "Tool.h"

/**
 * @brief Measuring tool such as tape or laser distance meter.
 */
class MeasuringTool : public Tool {
private:
    double accuracy;    ///< Measurement accuracy in percent.

public:
    /**
     * @brief Constructs a measuring tool.
     * @param name Tool name.
     * @param cost Tool cost.
     * @param weight Tool weight.
     * @param accuracy Measurement accuracy.
     */
    MeasuringTool(const std::string& name, double cost, double weight, double accuracy);

    /**
     * @brief Measures a given distance.
     * @param meters Distance value in meters.
     */
    void MeasureDistance(double meters);

    /**
     * @brief Prints detailed information about the measuring tool.
     */
    void PrintInfo() const override;
};

#endif // MEASURING_TOOL_H
