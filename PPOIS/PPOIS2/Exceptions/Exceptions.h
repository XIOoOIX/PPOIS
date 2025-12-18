#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidPaymentException : public std::runtime_error {
public:
    explicit InvalidPaymentException(const std::string &msg)
        : std::runtime_error("Invalid payment: " + msg) {}
};

class NotEnoughFundsException : public std::runtime_error {
public:
    explicit NotEnoughFundsException(const std::string &msg)
        : std::runtime_error("Not enough funds: " + msg) {}
};

class EmployeeNotFoundException : public std::runtime_error {
public:
    explicit EmployeeNotFoundException(const std::string &msg)
        : std::runtime_error("Employee not found: " + msg) {}
};

class ProjectNotFoundException : public std::runtime_error {
public:
    explicit ProjectNotFoundException(const std::string &msg)
        : std::runtime_error("Project not found: " + msg) {}
};

class MaterialNotFoundException : public std::runtime_error {
public:
    explicit MaterialNotFoundException(const std::string &msg)
        : std::runtime_error("Material not found: " + msg) {}
};

class InvalidContractException : public std::runtime_error {
public:
    explicit InvalidContractException(const std::string &msg)
        : std::runtime_error("Invalid contract: " + msg) {}
};

class EquipmentOverloadException : public std::runtime_error {
public:
    explicit EquipmentOverloadException(const std::string &msg)
        : std::runtime_error("Equipment overload: " + msg) {}
};

class UnsafeWorkConditionException : public std::runtime_error {
public:
    explicit UnsafeWorkConditionException(const std::string &msg)
        : std::runtime_error("Unsafe work condition: " + msg) {}
};

class InvalidBlueprintException : public std::runtime_error {
public:
    explicit InvalidBlueprintException(const std::string &msg)
        : std::runtime_error("Invalid blueprint: " + msg) {}
};

class InvalidAccessException : public std::runtime_error {
public:
    explicit InvalidAccessException(const std::string &msg)
        : std::runtime_error("Access denied: " + msg) {}
};

class OutOfStockException : public std::runtime_error {
public:
    explicit OutOfStockException(const std::string &msg)
        : std::runtime_error("Material out of stock: " + msg) {}
};

class WarehouseCapacityException : public std::runtime_error {
public:
    explicit WarehouseCapacityException(const std::string &msg)
        : std::runtime_error("Warehouse capacity exceeded: " + msg) {}
};

#endif
