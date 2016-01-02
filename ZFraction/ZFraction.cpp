//
//  ZFraction.cpp
//  ZFraction
//
//  Created by Cedric Bonnaffoux on 2016-01-02.
//  Copyright © 2016 Cedric Bonnaffoux. All rights reserved.
//

#include "ZFraction.hpp"

using namespace std;

ZFraction::ZFraction(const int & numerateur,const int &denominateur):
    m_numerateur(numerateur/pgcd(numerateur, denominateur)),
    m_denominateur(denominateur/pgcd(numerateur, denominateur))
{
}

void ZFraction::afficher(ostream &flux) const
{
    if (m_denominateur == 1)
    {
    flux << m_numerateur << endl;
    }
    else
    {
    flux << m_numerateur << "/" << m_denominateur << endl;
    }
    
}

ostream &operator<<( ostream &flux, ZFraction const& fraction)
{
    fraction.afficher(flux);
    return flux;
}


int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}