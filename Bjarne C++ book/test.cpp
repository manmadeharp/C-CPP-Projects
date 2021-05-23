//
// Created by Finbar on 22/12/2020.
//
#include <iostream>
#include "test.h"
int test() {
    int a;
    // copy assignment
    a = 5;
    // copy initialisation
    int aa = 3;
    // direct initialisation
    int b( 4 );
    // list initialisation
    int c{ 6 };
    std::cout << a+aa+b+c<< " " << aa << " " << b << " " << c << " " << std::endl;
    return 0;
}
