#include <gtest/gtest.h>
#include "../Materials/Concrete.h"
#include "../Materials/Steel.h"
#include "../Exceptions/Exceptions.h"

TEST(MaterialTest, UseMoreThanQuantityThrows) {
    Material material("Mat", 10.0, 5.0);
    EXPECT_THROW(material.Use(10.0), OutOfStockException);
}

TEST(MaterialTest, UseValidAmountReducesQuantity) {
    Material material("Mat", 10.0, 5.0);
    material.Use(2.0);
    EXPECT_DOUBLE_EQ(material.GetQuantity(), 3.0);
}

