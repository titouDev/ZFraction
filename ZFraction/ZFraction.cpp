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
    m_numerateur(numerateur),
    m_denominateur(denominateur)
{
    (*this).simplify();
}

ZFraction::ZFraction():m_numerateur(0),m_denominateur(1) // par default, une fraction vaut 0
{
}

ZFraction &ZFraction::operator*=(ZFraction const &a)
{
    m_numerateur*= a.m_numerateur;
    m_denominateur*= a.m_denominateur;
    return *this; //no need to simplify
}
ZFraction & ZFraction::operator+=(ZFraction const &a)
{
    m_numerateur*=a.m_denominateur;
    m_numerateur+= (a.m_numerateur*m_denominateur);
    m_denominateur *= a.m_denominateur;
    
    
    return (*this).simplify();
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction fractionCopie(a);
    fractionCopie += b;
    return fractionCopie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction fractionCopie(a);
    fractionCopie *= b;
    return fractionCopie;
}


void ZFraction::afficher(ostream &flux) const
{
    if (m_denominateur == 1)
    {
    flux << m_numerateur;
    }
    else
    {
    flux << m_numerateur << "/" << m_denominateur;
    }
    
}

bool ZFraction::isSuperior(ZFraction const &a) const
{
    return (m_numerateur*a.m_denominateur) > (m_denominateur*a.m_numerateur);
}

bool ZFraction::isEqual(const ZFraction &a) const
{
    //Pas besoin de simplifier les fractions, elles le sont deja a l'initialisation
    return (m_numerateur==a.m_numerateur) && (m_denominateur==a.m_denominateur);
}


bool operator>(ZFraction const& a, ZFraction const& b)
{
    return a.isSuperior(b);
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.isEqual(b);
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

ZFraction &ZFraction::simplify()
{
    //On s'assure de simlpifier la fonction
    int currentPgdc = pgcd(m_numerateur, m_denominateur);
    m_numerateur/=currentPgdc;
    m_denominateur /= currentPgdc;

    return *this;
}