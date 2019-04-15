#include <iostream>
#include <string>

#include "umn_person.h"

void UMNPerson::AddStudentRole(float tuition, float scholarship) {
  roles_.push_back(Student);
  tuition_ = tuition;
  scholarship_ = scholarship;
}
void UMNPerson::AddStudentWorkerRole(float wage, float hours, std::string dept) {
  roles_.push_back(StudentWorker);
  wage_ = wage;
  hours_ = hours;
  department_ = dept;
}
void UMNPerson::AddStaffRole(float salary) {
  roles_.push_back(Staff);
  salary_ = salary;
}

void UMNPerson::Describe() {
  std::cout << std::endl;
  std::cout << name_ << " has these roles..." << std::endl;
  for (auto role : roles_) {
    switch(role) {
      case(Student) :
        std::cout << "A student taking " << classes_.size() << " classes." << std::endl;
        break;
      case(StudentWorker) :
        std::cout << "A student worker working for " << department_ << std::endl;
        break;
      case(Staff) :
        std::cout << "A salaried employee." << std::endl;
        break;
    }
  }
}

void UMNPerson::MoneySituation() {
  std::cout << std::endl;
  std::cout << name_ << "\'s money situation is ... " << std::endl;
  for (auto role : roles_) {
    switch(role) {
      case(Student) :
        std::cout << "Paying tuition of $" << tuition_-scholarship_ << std::endl;
        break;
      case(StudentWorker) :
        std::cout << "Payed $" << wage_ << " per hour for " << hours_;
        std::cout << " hours per week = $" << wage_*hours_ << " per week." << std::endl;
        break;
      case(Staff) :
        std::cout << "Payed $" << salary_ << " per year." << std::endl;
        break;
    }
  }
}
