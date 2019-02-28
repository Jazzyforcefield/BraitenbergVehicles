#include <iostream>
#include <string>

using std::string;

class DuckClass {
public:
  DuckClass() : typeOf("duck"), name("noname"){}
  void Display() {
    std::cout << "I am " << name << ", and I am a " << typeOf << ".\n";
  }
  void Fly() { std::cout << "I fly typical.\n"; };
  void Quack() { std::cout << "I quack typical.\n"; };
 protected:
  string typeOf;
  string name;
};

class NoFlyDuck : public DuckClass {
 public:
  NoFlyDuck(std::string n="lame") {
    typeOf = "noFly";
    name = n;
  }
  void Fly() { std::cout << "I cannot fly.\n"; }
};

class NoQuackDuck : public DuckClass {
 public:
  NoQuackDuck( string n = "quiet" ) {
    typeOf = "noQuack";
    name = n;
  }
  void Quack() { std::cout << "I cannot quack.\n"; }
};

class LameDuck : public NoFlyDuck, public NoQuackClass {}
