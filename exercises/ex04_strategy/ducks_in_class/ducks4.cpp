#include "duck4.h"

using std::string;

class Mallard : public DuckClass {
public:
  Mallard(string n="nameless") {
    typeOf = "mallard";
    name = n;
  }
};

class Decoy : public NoFlyDuck {
  // This duck quacks but cannot fly
public:
  Decoy( string n = "nameless" ) {
    typeOf = "decoy";
    name = n;
  }
};

class DuckKite : public DuckClass {
  // A kite, shaped like a duck, that flies but can't quack <<<<<< IMPLEMENT THIS
public:
  DuckKite( string n = "nameless" ) {
    typeOf = "kite";
    name = n;
  }
};

class RubberDuck : public DuckClass {
  // This duck squeeks (no quack) and cannot fly   <<<<<<<<<<<<< IMPLEMENT THIS
  // Inheriting from DuckClass gives it both behaviors. Need something else.
public:
  RubberDuck( string n = "nameless" ) {
    typeOf = "loon";
    name = n;
  }
};

//-------------------------------------------------
int main() {
  Mallard molly("molly");
  molly.display();
  molly.fly();
  molly.quack();
}

