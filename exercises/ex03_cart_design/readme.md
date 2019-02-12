### Shopping with Bad Design

This example demonstrates bad design. There are many things wrong with respect to the design principles of encapsulation, coupling, cohesion, and information hiding. The interface of the class, which is dictated by the class definition, is integral to the quality of the design.

1. Shared Information:
  - Try using UML to draw the relationship between the classes.
  - For each class, determine what information it needs to know about other classes for the OrderTotal to be calculated, and
  - Identify the "badness" of this approach.

2. Programming style guides help to standardize naming conventions and common programming constructs. A common naming convention is to end all class variables with an underscore (e.g. "price_"). Perform your first refactoring by changing all class variable names by adding an underscore.

  **__Note the ripple effect of having to change names given the current design.__**

3. There is a data structure called a _vector_ in C++, which is a fancy array implemented with a template. It can change the way that you access elements and iterate over the elements of an array. This would be good to use to store cart items. Together, identify the places in which the code would need to change.

4. It is common practice to have all class members _private_, so let's comply and make all class members private.

5. You just broke the code in a significant way -- look at the calculation of the order total. Think about how the code is broken and how you would fix it without changing the design.

6. Thinking about those good OOP characteristics, what does the use of _private_ enforce in the interaction between classes? Comment on how this would benefit future changes to class names (as in what was done in 3 above) and a change to a class data structure (e.g. array to vector).

<hr>

#### Part 2

It is time to fix this bad design.

Use 3 classes in your design that have analogous functionality:
- An item in a cart
- A cart
- An order that contains a cart of items

Use Google style compliance by:
- ending all class members with an underscore
- keep class members _private_

**Add functionality in which only some items incur a sales tax. The item should keep track of whether or not a sales tax should be charged.**
