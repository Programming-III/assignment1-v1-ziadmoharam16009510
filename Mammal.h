#pragma once

#include "animal.H"
#include <string>

using namespace std;

class mammal : public animal {
private:
    string furcolor;

public:
    mammal();

    mammal(string n, int a, bool H) ;

    void setFurColor(string color);

    string getFurColor();
};
