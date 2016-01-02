//
//  ZFraction.hpp
//  ZFraction
//
//  Created by Cedric Bonnaffoux on 2016-01-02.
//  Copyright © 2016 Cedric Bonnaffoux. All rights reserved.
//

#ifndef ZFraction_hpp
#define ZFraction_hpp

#include <iostream>
#include <ostream>

class ZFraction
{
    public:
        ZFraction(); //constructeur vide
        ZFraction(const int &numerateur,const int &denominateur=1); //constructeur
        void afficher(std::ostream &flux) const;
        ZFraction &operator+=(ZFraction const &a);
        ZFraction &operator*=(ZFraction const &a);
        void simplify();
        bool isSuperior(ZFraction const &a) const;
        bool isEqual(ZFraction const &a) const;
    private:
        int m_numerateur;
        int m_denominateur;
};

//Helper
int pgcd(int a, int b);


//Operators

std::ostream &operator<<( std::ostream &flux, ZFraction const& fraction);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator==(ZFraction const& a, ZFraction const& b);


#endif /* ZFraction_hpp */
