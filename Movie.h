// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>


//const double movieAmount[] = {2, 3, 1,5};

class Movie {
public:

   // enum movieType {REGULAR, NEW_RELEASE, CHILDRENS};

    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    Movie( const std::string& title, int priceCode = REGULAR );

    Movie();

    int getPriceCode() const;
    double getAmount(int movieType) const;
    void setPriceCode( int arg );
    std::string getTitle() const;

private:
    std::string _title;
    int _priceCode;
};

inline double Movie::getAmount(int movieType) const {
    return 1;//movieAmount[movieType];
}

inline Movie::Movie() = default;

inline Movie::
Movie( const std::string& title, int priceCode )
        : _title( title )
        , _priceCode( priceCode )
{}

inline int Movie::
getPriceCode() const { return _priceCode; }

inline void Movie::
setPriceCode( int arg ) { _priceCode = arg; }

inline std::string Movie::
getTitle() const { return _title; }



#endif // MOVIE_H