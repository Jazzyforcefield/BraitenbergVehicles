#include <iostream>
#include <cstdlib>

#include "duck.h"
#include "duck_mallard.h"
#include "duck_rubberduck.h"

int main() {

  Duck mia;
  Mallard liu;
  RubberDuck genevieve;

  std::cout << "\n------------------  DIRECT ACCESS --------" << std::endl;

  std::cout << "\nMia does this ... " << std::endl;
  mia.Display();
  mia.Fly();
  mia.Quack();

  std::cout << "\nLiu does this ... " << std::endl;
  liu.Display();
  liu.Fly();
  liu.Quack();

  std::cout << "\nGenevieve does this ... " << std::endl;
  genevieve.Display();
  genevieve.Fly();
  genevieve.Quack();

  std::cout << std::endl;
  std::cout << "\n--------- UPCASTING: STATIC ARRAY --------" << std::endl;

  Duck ducks[3];
  ducks[0] = mia;
  ducks[1] = liu;
  ducks[2] = genevieve;

  for (int i = 0; i<3; i++) {
    ducks[i].Display();
    ducks[i].Fly();
    ducks[i].Quack();
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "\n--------- UPCASTING: DYNAMIC ARRAY --------" << std::endl;
  // >>>>>> FILL THIS IN WITH NEW ARRAY THEN DISPLAY, FLY, QUACK as above.
}
