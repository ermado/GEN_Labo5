#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockRental.h"
#include "MockCustomer.h"
#include "MockStatement.h"
#include "Statement.h"

using ::testing::Return;

/**
 * Test de la fonction processRentals de Statement.h
 */
//TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {
//    MockCustomer customer;
//
//    // Ajout fictif de films loués au mock customer
//    //EXPECT_CALL(customer, getRentals()).WillRepeatedly(Return());
//}