## Lab04 Dynamic Allocation Exercise

### What You Will Learn
1. How C++ allocates memory for static arrays.
2. How C++ dynamically allocates memory for arrays and array elements.
3. How memory is freed after dynamic allocation.


**__There is no grading script for this lab. Simultaneously view this lab and the Canvas quiz on dynamic allocation. The quiz will give some options in completing the code, and you can answer the questions on the quiz as you work through the lab.__**

### Retrieve Class Materials

> In case you forgot how, here is how to pull in the shared code ...

Navigate to your repository.
```
% cd <path_to_directory_repo-userid>
% git status
```

1. If you are on your master branch and you have made changes that are not yet committed and pushed, you should probably do that before proceeding.

2. Move to the support-code branch with `git checkout support-code`.

3. `git pull upstream support-code` to grab the latest changes from the shared class repo.

4. `git checkout master` to move back to the master branch for merging.

5. `git merge support-code`

### Completing the Code

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
