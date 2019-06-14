// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>


//const double movieAmount[] = {2, 3, 1,5};
//enum movieType {REGULAR, NEW_RELEASE, CHILDRENS};

/***************************************************************************************************
 * MainClass
 **************************************************************************************************/

class Movie {
public:

    Movie(const std::string& title);

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
    double amount = 2;
    if (daysRented > 2)
        amount += (daysRented - 2) * 1.5;
    return amount;
}

inline double NewReleaseMovie::getAmount(int daysRented) const {
    return daysRented * 3;
}

inline double ChildrenMovie::getAmount(int daysRented) const {
    double amount = 1.5;
    if (daysRented > 3)
        amount += (daysRented - 3) * 1.5;
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