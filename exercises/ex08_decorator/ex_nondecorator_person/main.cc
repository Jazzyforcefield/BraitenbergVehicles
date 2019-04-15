#include <iostream>
#include "umn_person.h"

int main() {

  UMNPerson * nina = new UMNPerson("Nina");
  nina->AddStudentRole(13790.00);
  nina->AddClass("CSCI3081");
  nina->AddStudentWorkerRole(15.75,15,"Rec Center");
  nina->Describe();
  nina->MoneySituation();

  UMNPerson * ravi = new UMNPerson("Ravi");
  ravi->AddStaffRole(43200.56);
  ravi->Describe();
  ravi->MoneySituation();
}
