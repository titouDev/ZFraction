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
        ZFraction(const int &numerateur,const int &denominateur=1); //constructeur
        void afficher(std::ostream &flux) const;
    private:
        int m_numerateur;
        int m_denominateur;
};

int pgcd(int a, int b);
std::ostream &operator<<( std::ostream &flux, ZFraction const& fraction);

#endif /* ZFraction_hpp */
