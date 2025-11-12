

#include <iostream>
#include <string>

using namespace std;

class visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    visitor();

    visitor(string v, int t) ;

    void displayInfo() ;
};
