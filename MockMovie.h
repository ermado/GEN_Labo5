//
// Created by Marion on 07.06.2019.
//

#ifndef GEN_LABO5_MOCKMOVIE_H
#define GEN_LABO5_MOCKMOVIE_H

#include "gmock/gmock.h"
#include "movie.h"

class MockMovie : public Movie {

public:

    MOCK_METHOD0(getTitle, const std::string());
    MOCK_METHOD0(getPriceCode, int());
    MOCK_METHOD1(setPriceCode, void(int price));

};


#endif //GEN_LABO5_MOCKMOVIE_H
