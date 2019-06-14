// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>


// ecrire pourquoi in fait ca!!!!
enum movieType {REGULAR, NEW_RELEASE, CHILDRENS};
static double movieBaseAmount[] = {2, 3, 1.5};
static double movieDayLimit[] = {2, 0, 3};
const double BASETAX = 1.5;

/***************************************************************************************************
 * MainClass
 **************************************************************************************************/

class Movie {
public:

    Movie(const std::string& title);

    // abstraire le price (ces deux methodes)
    int getPriceCode() const;
    void setPriceCode( int arg );


    std::string getTitle() const;

    virtual double getAmount(int daysRented) const = 0;
    virtual int getRenterPoints() const = 0;

private:
    std::string _title;
    int _priceCode = 99;
};


/***************************************************************************************************
 * SubClasses
 **************************************************************************************************/


class RegularMovie : public Movie {

public:
    explicit RegularMovie(const std::string& title) : Movie(title) {}
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};

class NewReleaseMovie : public Movie {

public:
    explicit NewReleaseMovie(const std::string& title) : Movie(title) {}
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};

class ChildrenMovie : public Movie {

public:
    explicit ChildrenMovie(const std::string& title) : Movie(title) {}
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};

/***************************************************************************************************
 * MainClass Implementations
 **************************************************************************************************/


inline Movie::Movie( const std::string& title) : _title( title )
{}

inline void Movie::
setPriceCode( int arg ) { _priceCode = arg; }

inline std::string Movie::
getTitle() const { return _title; }



/***************************************************************************************************
 * SubClass Implementations
 **************************************************************************************************/

inline double RegularMovie::getAmount(int daysRented) const {
    double amount = movieBaseAmount[REGULAR];
    if (daysRented > movieDayLimit[REGULAR])
        amount += (daysRented - movieDayLimit[REGULAR]) * BASETAX;
    return amount;
}

inline double NewReleaseMovie::getAmount(int daysRented) const {
    return daysRented * movieBaseAmount[NEW_RELEASE];
}

inline double ChildrenMovie::getAmount(int daysRented) const {
    double amount = movieBaseAmount[CHILDRENS];
    if (daysRented > movieDayLimit[CHILDRENS])
        amount += (daysRented - movieDayLimit[CHILDRENS]) * BASETAX;
    return amount;

}

inline int RegularMovie::getRenterPoints() const {
    return 1;
}

inline int NewReleaseMovie::getRenterPoints() const {
    return 2;
}

inline int ChildrenMovie::getRenterPoints() const {
    return 1;
}


#endif // MOVIE_H