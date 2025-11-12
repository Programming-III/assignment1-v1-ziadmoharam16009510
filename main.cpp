#include <iostream>
#include <vector>
#include <string>
#include "animal.H"
#include "Mammal.H"
#include "Bird.H"
#include "Reptile.H"
#include "enclosure.H"
#include "visitor.H"


using namespace std;

class animal{

     private :
     string name;
     int age;
     bool isHungry;

    public :
    animal(){};

    animal(string n, int a, bool H){
        name = n;
        age = a;
        isHungry = H;
    };
    
    void display(){
        string a;
        if (isHungry){
            a="Hungry";
        }
        else {
            a="Not Hungry";
        }
        cout <<name<<"(Age : "<<age<<","<<a<<")"<<endl;
    };
    void feed(){
        isHungry = false;

    };

};
class Mammal : public animal{
private :
    string furcolor;

public :
    Mammal() : animal() {}
    
    Mammal(string n, int a, bool H) : animal(n, a, H) {}
    
};
class Bird : public animal{
private :
    float wingspan;

public :
    Bird() : animal() {}
    
    Bird(string n, int a, bool H) : animal(n, a, H) {}
    
};

class Reptile : public animal{
private :
    bool isVenomous;

public :
    Reptile() : animal() {}
    
    Reptile(string n, int a, bool H) : animal(n, a, H) {}
    
    void setVenomous(bool v) { isVenomous = v; }
    
};

class enclosure{
private :
    vector<animal*> animals;
    int capacity;
    int currentCount;

public :
    enclosure() {}

    enclosure(int c, int cc)
        : capacity(c), currentCount(cc)
    {
        animals.reserve(capacity);
    }


    bool addAnimal(animal* a){
        if (!a) return false;
        if (currentCount >= capacity) return false; 
        animals.push_back(a);
        ++currentCount;
        return true;
    }

    void displayAnimals() const {
        for (int i = 0; i < currentCount && i < static_cast<int>(animals.size()); ++i) {
            if (animals[i]) animals[i]->display();
        }
    }
};
class visitor{
 private :
     string visitorName;
     int ticketsBought;
    

    public :
    visitor(){};
    visitor(string v, int t){
       visitorName= v;
       ticketsBought = t;

    };
    
    void displayInfo(){
        cout<<"Name : "<< visitorName << endl;
        cout<<"Tickets Bought : "<< ticketsBought << endl;
    };
};


int main(){
    
    enclosure zoo(5, 0);
    
    
    mammal* lion = new mammal("Lion", 5, true);
    
    
    bird* parrot = new bird("parrot", 2, false);
    

    reptile* snake = new reptile("snake", 3, true);
    snake->setVenomous(true);


   
    zoo.addAnimal(lion);
  
    
    zoo.addAnimal(parrot);
    
    
   zoo.addAnimal(snake);
  
    
    
    
    zoo.displayAnimals();
    
   
    visitor guest("Sarah Ali", 3);
    
    
   
    guest.displayInfo();
    
  
    delete lion;
    delete parrot;
    delete snake;
    
    return 0;
}
