#include "ShoppingMall.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

ShoppingMall::ShoppingMall(const std::string& addr, double area, int floors)
    : Building(addr, area, floors), shopsCount(0), parking(true), escalatorWorking(true) {}

void ShoppingMall::AddShop() {
    shopsCount++;
    std::cout << "Добавлен новый магазин. Всего: " << shopsCount << ".\n";
}

void ShoppingMall::ManageEscalator(bool on) {
    escalatorWorking = on;
    std::cout << "Эскалаторы " << (on ? "включены" : "отключены") << ".\n";
}


void ShoppingMall::PrintBuildingInfo() const {
    std::cout << "ТЦ: этажей " << floors << ", магазинов " << shopsCount
              << ", парковка: " << (parking ? "есть" : "нет") << ".\n";
}
