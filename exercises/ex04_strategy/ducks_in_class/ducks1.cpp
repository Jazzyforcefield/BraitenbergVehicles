#include "duck1.h"

using std::string;

class Mallard : public DuckClass {
public:
  Mallard(string n="nameless") {
    typeOf = "mallard";
    name = n;
  }
  void fly() { std::cout << "I fly.\n"; }
  void quack() { std::cout << "I quack.\n"; }
};

class Loon : public DuckClass {
public:
  // This duck quacks and flies   <<<<<<<<<<<< FILL THIS IN
  Loon( string n = "nameless" ) {
    typeOf = "loon";
    name = n;
  }
};

class Decoy : public DuckClass {
  // This duck quacks but cannot fly   <<<<<<<<<<< FILL THIS IN
public:
  Decoy( string n = "nameless" ) {
    typeOf = "decoy";
    name = n;
  }
};

// <<<<<<<<<<<< WHAT ABOUT A RUBBER DUCK ??

int main() {
  Mallard molly("molly");
  molly.display();
  molly.fly();
  molly.quack();
}

