### Feedback for Proj 02

Run on April 15, 18:25:44 PM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Git Usage

+ Pass: Check git commit history
Commits found=70

+ Pass: Run git ls-remote gather all branches in repo

5eaf039e96955d29acfa3431a7c67bd20bf46780	refs/heads/dev/collision-avoidance

76e45f201d1dcecab99e4cd5a7e9b53cf9d3484c	refs/heads/dev/factory-implementation

e2ddf3e7fdac5b010aba965a1cc6545ca91b4016	refs/heads/dev/food-timer

884733de75e62f51b198ded6c4ea140bf8d5647f	refs/heads/dev/implement-behavior-strategy

595fdf43e2ce4fb1c2d263f5f7000d3a31cf0615	refs/heads/dev/json-factories

35e357056b06b04b2b97994c66fa98012425f924	refs/heads/dev/observer-pattern

2ee31626ba625f39d10b30886499289c82658a35	refs/heads/dev/predators

3f2cc1dfe1069dbad0650fd1eaf6a1e5492ee86f	refs/heads/dev/vehicle-behaviors

7dee1001b657db7074d856955b9ac5793ca80464	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

647a5ebd468b601715d67b91b4dacfbff7634172	refs/heads/fix/02-robot-walls

182468b97829c240822faca09865caecdc99ad60	refs/heads/fix/cpplint-const

3b1c5cbaba5e29e79a2dba52c9c2f7fb632a4bee	refs/heads/master

b179867dfb0be8097bdb6187c49581a494c9d72b	refs/heads/pre-release/iteration1

a6f4f90ca13c9ed2c24846136b6d4a93bfca61d9	refs/heads/release/iteration1

d9b98d1b0d837037d7fc3e5afcc78c656b2be0ca	refs/heads/release/iteration2-prelim1

75a6eeac6213fa1d1ad5bfa364dc253ef1898c4e	refs/heads/release/iteration2-prelim2

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 4)

[OPEN issue #21] :  Introduce dynamic bv wheel behavior

[OPEN issue #20] :  Implement a Food timer

[OPEN issue #18] :  Complete Predator-BV consumption interaction

[OPEN issue #17] :  BV Behavior is reversed [bug] 2





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 17)

[CLOSED issue #19] :  Starvation of bv

[CLOSED issue #16] :  Implement Predator Class 1

[CLOSED issue #15] :  Implement Observer Pattern

[CLOSED issue #14] :  Implement Strategy Pattern for BV [bug] 2

[CLOSED issue #13] :  Create Unit Tests for Strategy Pattern

[CLOSED issue #12] :  Change json references to pointers

[CLOSED issue #11] :  Implement json configuration for factory classes

[CLOSED issue #10] :  Implement colors to BV 1 @ungxx028

[CLOSED issue #9] :  Add collision avoidance behavior to BV 1 @ungxx028

[CLOSED issue #8] :  Implement BV behaviors 1

[CLOSED issue #7] :  Update uml_design.pdf to include relationships between Arena and BraitenbergVehicle

[CLOSED issue #6] :  Refactor BraitenbergVehicle class 

[CLOSED issue #5] :  Rename UML.pdf to uml_design.pdf 1

[CLOSED issue #4] :  Implement FactoryPointer and subclasses

[CLOSED issue #3] :  fix(arena_mobile_entity.h) ↑

[CLOSED issue #2] :  Robots getting stuck in walls [bug] 1

[CLOSED issue #1] :  Compilation error [bug] 1






#### Documentation Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-ungxx028/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-ungxx028/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:146:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:149:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:158:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:167:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
food.h:82:  You don't need a ; after a }  [readability/braces] [4]
food.h:87:  You don't need a ; after a }  [readability/braces] [4]
Done processing AggressiveBehavior.cc
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing BraitenbergVehicleFactory.cc
Done processing controller.cc
Done processing CowardBehavior.cc
Done processing ExploreBehavior.cc
Done processing Factory.cc
Done processing food.cc
Done processing FoodFactory.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
Done processing LightFactory.cc
Done processing LoveBehavior.cc
Done processing main.cc
Done processing motion_behavior.cc
Done processing motion_behavior_differential.cc
Done processing Predator.cc
Done processing rgb_color.cc
Done processing AggressiveBehavior.h
Done processing arena_entity.h
Done processing arena.h
Done processing arena_immobile_entity.h
Done processing arena_mobile_entity.h
Done processing arena_viewer.h
Done processing behavior_enum.h
Done processing BraitenbergVehicleFactory.h
Done processing braitenberg_vehicle.h
Done processing common.h
Done processing controller.h
Done processing CowardBehavior.h
Done processing entity_type.h
Done processing ExploreBehavior.h
Done processing Factory.h
Done processing FoodFactory.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing LightFactory.h
Done processing light.h
Done processing LoveBehavior.h
Done processing mainpage.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing Observer.h
Done processing params.h
Done processing pose.h
Done processing Predator.h
Done processing rgb_color.h
Done processing Subject.h
Done processing WheelBehavior.h
Done processing wheel_velocity.h
Total errors found: 6
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-ungxx028/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

