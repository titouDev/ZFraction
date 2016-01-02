//
//  main.cpp
//  ZFraction
//
//  Created by Cedric Bonnaffoux on 2016-01-02.
//  Copyright © 2016 Cedric Bonnaffoux. All rights reserved.
//

#include <iostream>
#include "ZFraction.hpp"

using namespace std;

int main()
{
    ZFraction a(4,5);      //Déclare une fraction valant 4/5
    ZFraction b(2);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d;         //Déclare deux fractions valant 0
    
    c = a+b;               //Calcule 4/5 + 2/1 = 14/5
    
    //d = a*b;               //Calcule 4/5 * 2/1 = 8/5
    
    cout << a << " + " << b << " = " << c << endl;
    
    cout << a << " * " << b << " = " << d << endl;
    /*
    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;
    */
    return 0;
}