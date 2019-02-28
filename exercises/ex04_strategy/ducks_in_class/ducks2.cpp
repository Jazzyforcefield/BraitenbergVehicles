#include "duck2.h"

using std::string;

class Mallard : public DuckClass {
public:
  Mallard(string n="nameless") {
    typeOf = "mallard";
    name = n;
  }
};

class Loon : public DuckClass {
  // This duck flies and quacks  <<<<< IMPLEMENT THIS
public:
  Loon( string n="nameless") {
    typeOf = "loon";
    name = n;
  }
};

class RubberDuck : public DuckClass {
  // This duck squeaks (no quack) and cannot fly   <<<<< IMPLEMENT THIS
public:
  RubberDuck( string n="nameless") {
    typeOf = "rubber duck";
    name = n;
  }
};

class Decoy : public DuckClass {
  // This duck quacks but cannot fly    <<<<<<< IMPLEMENT THIS
public:
  Decoy (string n = "nameless") {
    typeOf = "decoy";
    name = n;
  }
};

int main() {
  Mallard molly("molly");
  molly.display();
  molly.fly();
  molly.quack();
}

