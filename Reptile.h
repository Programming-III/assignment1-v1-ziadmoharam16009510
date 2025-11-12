

#include "animal.H"
#include <string>

using namespace std;

class reptile : public animal {
private:
    bool isVenomous;

public:
    reptile();

    reptile(string n, int a, bool H) ;

    void setVenomous(bool v);

    bool getVenomous();
};
