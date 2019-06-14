//
// Created by Edd993Surface on 07/06/2019.
//

#ifndef GEN_LABO5_MOCKRENTAL_H
#define GEN_LABO5_MOCKRENTAL_H

#include "gmock/gmock.h"
#include "rental.h"

class MockRental : public Rental {
public:
    
    MOCK_CONST_METHOD0(getMovie, const Movie&());
    MOCK_CONST_METHOD0(getDaysRented, int());

};

#endif //GEN_LABO5_MOCKRENTAL_H
