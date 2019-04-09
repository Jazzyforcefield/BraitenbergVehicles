### Decorator Design Pattern : People of UMN

Start by looking at the Decorator example of coffee. The idea is to take this version of UMN people and covert to an implementation of the decorator pattern.

The base class is UMNPerson. Each person can take on multiple roles (e.g. student, student worker, staff). For a student, there is an associated tuition and scholarship. For workers and staff, there is an associated department and hourly wage or salary, respectively. Look at main.cc and see how roles are added to a person (i.e. roles are decorating the person).

Think about what code needs to change to add roles (e.g. research assistant, graduate student, etc.).

Think about what code needs to change for someone to have 2 student worker jobs.

Clearly, this is not closed to change!

To convert the UMNPerson example to the decorator pattern, you will need to create the following classes (add Staff after you get this done):

- class RoleDecorator : public UMNPerson
- class Student : public RoleDecorator
- class StudentWorker : public RoleDecorator

For every class, you should be able to call Describe and MoneySituation. Try to create it such that it will work with this main function:

```
int main() {
  // Instantiate Nina
  UMNPerson * nina = new UMNPerson("Nina");

  // Nina is a student taking 1 class.
  // Interface: Student(UMNPerson*, tuition, scholarship=0);
  nina = new Student(nina,13790.00);
  static_cast<Student *>(nina)->AddClass("CSCI3081");

  // Nina has 2 jobs. One pays more than the other, but has fewer hours.
  // Interface StudentWorker(UMNPerson*, wage_, hours_, department_)
  nina = new StudentWorker(nina,15.75,15,"Rec Center");
  nina = new StudentWorker(nina,20.15,5,"OIT");

  nina->Describe();
  nina->MoneySituation();
}
```

The output of the above is ...

```
Nina is a student worker for the OIT
Nina is a student worker for the Rec Center
Nina is taking 1 classes.
At OIT, Nina is payed 20.15 per hour for 5 hours per week = $100.75 per week.
At Rec Center, Nina is payed 15.75 per hour for 15 hours per week = $236.25 per week.
Nina is paying tuition of $13790
```

Once you have this working, see how easy it is to add a new role "Staff"!

This is open to extension and closed to change!
