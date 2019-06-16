//
// Created by Edd993Surface on 16/06/2019.
//

#ifndef GEN_LABO5_MOCKMOVIE_H
#define GEN_LABO5_MOCKMOVIE_H

class MockRegularMovie : public Movie {
public:

    MOCK_CONST_METHOD1(setTitle, void);
    MOCK_CONST_METHOD0(getTitle, std::string);
    MOCK_CONST_METHOD1(getAmount, double);
    MOCK_CONST_METHOD0(getRenterPoints, int);

};

class MockNewReleaseMovie : public Movie {
public:

    MOCK_CONST_METHOD1(setTitle, void);
    MOCK_CONST_METHOD0(getTitle, std::string);
    MOCK_CONST_METHOD1(getAmount, double);
    MOCK_CONST_METHOD0(getRenterPoints, int);

};

class MockChildrenMovie : public Movie {
public:

    MOCK_CONST_METHOD1(setTitle, void);
    MOCK_CONST_METHOD0(getTitle, std::string);
    MOCK_CONST_METHOD1(getAmount, double);
    MOCK_CONST_METHOD0(getRenterPoints, int);

};






#endif //GEN_LABO5_MOCKMOVIE_H
