### Exercise 16 : Templates

In this collection of files, you will find a class _Data_ that holds an array of ints and a method _SelectionSort_ that will sort the array. Your task is to convert the class Data to a template.

#### Warm Up

In the file _warm-up.h_, you will see an example of the template function _MySwap()_ and the template class _Position_.

1. In _warmup.h_, define the overloaded member operator+ for Position.

2. In main(), define 2 position instances with type double, and use std::cout to print the results of adding these two instances.

3. In main(), define 2 position instances with type int, and use std::cout to print the results of adding these two instances.

4. In main(), print the results of swapping the 2 double Positions.

In _warmup.h_, look at the definition of the global overloaded operator-. Notice that it makes use of two separate class types. This allows us to mix types.

5. In main(), use your defined positions to try operator- with double-int.

6. In main(), use your defined positions to try operator- with int-double.

#### Your Turn

Now that you have some experience with using templates, convert the class Data to a template version. Notice that there is only a _data.h_ file. The compiler has to see the entire definition before using it, so all definitions have to be contained in that one file, either in-line or defined outside the class definition. You can see examples of both in the file.

1. In _data.h_, add the template keyword as appropriate to make the class a template.

2. In _data.h_, add this same template syntax to the method _SelectionSort_ defined outside the class definition. This one requires that you use your generic type with the scope _Data_ in the method definition Data::SelectionSort.

3. In _data.h_, find all the occurrences of _int_ that need to be replaced with the generic type defined in the template syntax.

4. In _circle.cc_ and _math-vector.cc_, complete the definitions for the operator< to be used in SelectionSort. Use the circle radius and vector length for the comparison.

5. In _main.h_, define an instance _circles_ of Data with type Circle.

6. In _main.h_, uncomment the use of that instance to print and sort the data.

7. In _main.h_, define an instance _math_vectors_ of Data with type MathVector then uncomment the use of that instance.

#### Some Extras

Can you add in some methods to _Data_ to find the maximum, minimum, and calculate the average of the data?
- Data::Max()
- Data::Min()
- Data::Average()
