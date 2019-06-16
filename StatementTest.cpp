#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockRental.h"
#include "MockMovie.h"
#include "MockCustomer.h"
#include "MockStatement.h"
#include "Statement.h"

using ::testing::Return;

/**
 * Test de la fonction processRentals de Statement.h
 */
TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {
    MockMovie movie1, movie2;
}