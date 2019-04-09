#ifndef UMN_PERSON_H_
#define UMN_PERSON_H_

#include <iostream>
#include <string>
#include <vector>

enum Role { Student, StudentWorker, Staff };

class UMNPerson {
  public:
    UMNPerson(std::string name) : name_(name) {}
    void Describe();
    void MoneySituation();
    void AddStudentRole(float tuition, float scholarship=0);
    void AddClass(std::string course) {classes_.push_back(course);}
    void AddStudentWorkerRole(float wage, float hours, std::string dept);
    void AddStaffRole(float salary);
    std::string get_name() { return name_; }
  private:
    // Person
    std::string name_;
    std::vector<Role> roles_;
    // Student
    float tuition_;
    float scholarship_;
    std::vector<std::string> classes_;
    // Student Worker
    float wage_;
    float hours_;
    std::string department_;
    // Staff
    float salary_;
  };

#endif /* UMN_PERSON_H_ */
