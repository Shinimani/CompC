#include <iostream>
#include "cube.h"

int cube::getLen()
{
    return len_;
}

void cube::setLen(int l)
{
    len_=l;
}

cube::cube(int len){
    len_=len;
}

cube::cube(){
    len_ = 1;
}