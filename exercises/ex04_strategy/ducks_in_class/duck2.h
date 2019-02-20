#include <iostream>
#include <string>

class DuckClass {
public:
  DuckClass() {
    typeOf = "duck";
    name = "noname";
  }
  void Display() {
    std::cout << "I am " << name << ", and I am a " << typeOf << ".\n";
  }
  void Fly() {
    std::cout << "I fly like any typical duck." << std::endl;
  }
  void Quack() {
    std::cout << "I quack like any typical duck." << std::endl;
  }
protected:
  std::string typeOf;
  std::string name;
};

class Mallard : public DuckClass {
public:
  Mallard(std::string n="none") { typeOf = "Mallard"; name = n; }
}
