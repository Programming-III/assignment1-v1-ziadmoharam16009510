

#include "animal.H"
#include <vector>

using namespace std;

class enclosure {
private:
    vector<animal*> animals;
    int capacity;
    int currentCount;

public:
    enclosure() : capacity(0), currentCount(0) {}

    enclosure(int c, int cc);

    bool addAnimal(animal* a) ;
    void displayAnimals() ;
};
