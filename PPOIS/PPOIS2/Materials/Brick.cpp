#include "Brick.h"
#include <iostream>

Brick::Brick(const std::string& name, double weight, double qty, const std::string& clr, bool fireproof)
    : Material(name, weight, qty), color(clr), isFireproof(fireproof) {}

void Brick::CheckDurability() {
    std::cout << "Проверена прочность кирпича (" << (isFireproof ? "огнеупорный" : "обычный") << ").\n";
}

void Brick::DescribeMaterial() const {
    std::cout << "Кирпич: цвет " << color << ", количество: " << quantity
    << ", вес: " << weight << ", " << isFireproof ? "огнеупорный" : "обычный";
}
