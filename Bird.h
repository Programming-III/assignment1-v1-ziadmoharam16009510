#pragma once

#include "animal.H"
#include <string>

using namespace std;

class bird : public animal {
private:
    float wingspan;

public:
    bird() ;
    bird(string n, int a, bool H) ;

    void setWingspan(float ws) ;

    float getWingspan() ;
};
