### Understanding Implementation of the Strategy Pattern

Design patterns are a collection of solutions to common software design problems. You will sometimes hear the authors of the original text _Design Patterns: Elements of Reusable Object-Oriented Software_ referred to as the "Gang of Four." They are Eric Gamma, Richard Helm, Ralph Johnson, and John Vlissides. Each pattern presents a framework that can be implemented in any object oriented language.

This duck example is straight out of Chapter 1 of _Head First Design Patterns_ by Eric Freeman and Elisabeth Robson. The premise is that you are creating a duck simulator, and at first, it is pretty straight-forward because all ducks have typical flying and quacking behavior. But then you have to incorporate atypical behaviors/strategies for lame ducks and rubber ducks. The pattern shows how to use composition and inheritance to create code that is "closed to change yet open to extension." This is a clever solution, but it does come at the expense of complexity. Notice the number of classes that are needed to implement just 3 types of ducks.

To take advantage of the strategy pattern, which uses a combination of inheritance and composition, you have to correctly implement polymorphism. This requires 2 key ingredients: the word _virtual_ used with methods that will be overridden in the derived class and the use of dynamic memory allocation (i.e. run-time instantiation of a class using the keyword _new_), which facilitates late binding.

#### 1. Implement Polymorphism

The ducks in the array in main are generically flying and quacking, but they shouldn't be. Implement polymorphism using _virtual_ and pointers.

- Start by creating a second array of 3 duck pointers and filling it with a new Duck, Mallard, and RubberDuck object. Then iterate through to Display(), Fly(), and Quack() just as you did with the static array of ducks.

- Now add the keyword _virtual_ to any base class methods you want to override. You should see some progress with respect to Display(), but you probably haven't fixed the flying and quacking behavior.

- Do you know how to fix the flying and quacking behavior so that the methods Fly() and Quack() of the derived classes get called instead of the base class? Remember, you need to use _virtual_ and pointers.

> Now everyone is flying and quacking as intended EXCEPT that some of the strategies are not filled in.

#### 2. Add More Classes for Flying

- Fill in NoFly class
- Fill in FlyWithRocket class

#### 3. Add More Classes for Quacking

- Fill in Honking class

#### 4. Create New Ducks

- Create a futuristic duck that flies with a rocket and quacks.
- Create an ugly duckling (i.e. swan) that flies and honks.
- Instantiate one of each and place in your arrays in main().

#### 5. Add Parameter Name to Ducks

- Add the parameter name to the Duck class, making it **__private__**.
- Add a setter for the name in the Duck class.
- For each constructor of a duck, add a name parameter and use the setter to define the name.
- Add the name to the display function.
