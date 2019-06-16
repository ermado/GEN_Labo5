//
// Created by Marion on 07.06.2019.
//

#ifndef GEN_LABO5_MOCKCUSTOMER_H
#define GEN_LABO5_MOCKCUSTOMER_H

#include "gmock/gmock.h"
#include "Customer.h"
#include <string>

class MockCustomer : public Customer {

public:

    MOCK_METHOD1(addRental, void(const Rental&()));
    MOCK_CONST_METHOD0(getName, const std::string());
    MOCK_CONST_METHOD0(getRentals, const std::vector<Rental>&());

};


#endif //GEN_LABO5_MOCKCUSTOMER_H
