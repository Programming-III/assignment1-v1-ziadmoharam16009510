#pragma once

#include <iostream>
#include <string>

using namespace std;

class animal {
protected:
    string name;
    int age;
    bool isHungry;

public:
    animal() ;

    animal(string n, int a, bool H) ;

    virtual ~animal() {}

    void display() ;
    void feed() ;
    string getName();
    int getAge() ;
    bool getIsHungry() ;
};
