#include <iostream>
#include <string>

using std::string;

class DuckClass {
 protected:
  string typeOf;
  string name;
  bool canFly;
  bool canQuack;
 public:
	DuckClass() : canFly(true), canQuack(true) {
    typeOf = "duck";
    name = "noname";
  }
  void display() 
	{ std::cout << "I am " << name << ", and I am a " << typeOf << ".\n"; }
  void fly() { 
    if (canFly) std::cout << "I fly.\n"; 
    else std::cout << "I cannot fly.\n";
  }
  void quack() { 
    if (canQuack) std::cout << "I quack.\n";
    else std::cout << "I do not quack.\n";
  }
};




