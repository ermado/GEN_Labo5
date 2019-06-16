#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockRental.h"
#include "MockMovie.h"
#include "MockCustomer.h"
#include "Statement.h"

using ::testing::Return;

/**
 * Les 3 types de films differents doivent avoir le bon nombre
 * de points client
 */
TEST(MovieTypesTest, CorrectNumberOfRentedPoints) {

    RegularMovie rMov("Inception");
    NewReleaseMovie nrMov("It 2");
    ChildrenMovie chMov("The Lion King");

    ASSERT_EQ(rMov.getRenterPoints(), 1);
    ASSERT_EQ(nrMov.getRenterPoints(), 2);
    ASSERT_EQ(chMov.getRenterPoints(), 1);
}
