### Dynamic Allocation Exercise

Included in this directory is a class definition for _Duck_, and a class definition for _ArrayPointerTest_ that has a collection of duck arrays of various types.

Part of the assignment is to fill in the code that initializes, displays, and destroys the arrays in the ArrayPointerTest class. You will show what you have learned by completing the corresponding Canvas quiz.

Open ArrayPointerTest.cc and complete the following. Recall that to compile and run the executable:
```
make
./ducks
```

1. In the ArrayPointerTest constructor, for each of the ducks#_ arrays, fill in the code that will initialize "count_" ducks. For our purposes, the count_ is set to 3 (which is already in the code).

2. In the NameTheDucks class method, for each of ducks2_, ducks3_, and ducks4_, fill in the code to name the 3 ducks and to set the array number in which the duck is stored.

3. In the DisplayContents class method, uncomment all the code that performs the quack for each duck in each array.

4. Take notice in the class method DisplayContents how the individual ducks are referenced. In ducks1_ and ducks2_, they are referenced using the '.' operator, but in ducks3_ and ducks4_, they are referenced using the '->' operator. You don't have to answer this in the quiz, but you should understand why the different operators are needed in the different circumstances.

5. In the ArrayPointerTest destructor, for each of the ducks#_ arrays, fill in the code that will destroy all objects created at the instantiation of an ArrayPointerTest object. If done correctly, when you execute the code, you should see
```
lemon in ducks# is being destroyed.
yang in ducks# is being destroyed.
mia in ducks# is being destroyed.
```
printed to the screen for all four duck arrays.
