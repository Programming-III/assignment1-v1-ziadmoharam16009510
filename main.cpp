#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;
    bool isHungry;

public:
    Animal() {}

    Animal(string n, int a, bool H) {
        name = n;
        age = a;
        isHungry = H;
    }

    virtual ~Animal() {}

    virtual void display() {
        string hungerStatus = isHungry ? "Hungry" : "Not Hungry";
        cout << name << " (Age: " << age << ", " << hungerStatus << ")" << endl;
    }

    void feed() {
        isHungry = false;
    }
};

class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal() : Animal() {}
    Mammal(string n, int a, bool H) : Animal(n, a, H) {}
};

class Bird : public Animal {
private:
    float wingspan;

public:
    Bird() : Animal() {}
    Bird(string n, int a, bool H) : Animal(n, a, H) {}
};

class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile() : Animal(), isVenomous(false) {}
    Reptile(string n, int a, bool H) : Animal(n, a, H), isVenomous(false) {}

    void setVenomous(bool v) { isVenomous = v; }
};

class Enclosure {
private:
    vector<Animal*> animals;
    int capacity;
    int currentCount;

public:
    Enclosure() : capacity(0), currentCount(0) {}
    Enclosure(int c, int cc) : capacity(c), currentCount(cc) {
        animals.reserve(capacity);
    }

    bool addAnimal(Animal* a) {
        if (!a) return false;
        if (currentCount >= capacity) return false;
        animals.push_back(a);
        ++currentCount;
        return true;
    }

    void displayAnimals() const {
        for (int i = 0; i < currentCount && i < (int)animals.size(); ++i) {
            if (animals[i]) animals[i]->display();
        }
    }
};

class Visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    Visitor() {}
    Visitor(string v, int t) {
        visitorName = v;
        ticketsBought = t;
    }

    void displayInfo() {
        cout << "Name: " << visitorName << endl;
        cout << "Tickets Bought: " << ticketsBought << endl;
    }
};

int main() {
    Enclosure zoo(5, 0);

    Mammal* lion = new Mammal("Lion", 5, true);
    Bird* parrot = new Bird("Parrot", 2, false);
    Reptile* snake = new Reptile("Snake", 3, true);
    snake->setVenomous(true);

    zoo.addAnimal(lion);
    zoo.addAnimal(parrot);
    zoo.addAnimal(snake);

    zoo.displayAnimals();

    Visitor guest("Sarah Ali", 3);
    guest.displayInfo();

    delete lion;
    delete parrot;
    delete snake;

    return 0;
}
