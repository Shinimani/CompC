#include <iostream>
#include <vector>
#include "cube.h"
#pragma once

using namespace std;
#define PB push_back
#define V vector

class hanoi{
    // public int getVol();
    // private:
    //     V<cube> l_;
    //     V<cube> c_;
    //     V<cube> r_;

    public:
        V<V<cube>> stacks_;
        void printS(int index); 
        void printAll();

        hanoi(int n);
};