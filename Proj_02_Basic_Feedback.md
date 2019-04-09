### Feedback for Proj 02

Run on April 08, 22:15:54 PM.


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

884733de75e62f51b198ded6c4ea140bf8d5647f	refs/heads/dev/implement-behavior-strategy

595fdf43e2ce4fb1c2d263f5f7000d3a31cf0615	refs/heads/dev/json-factories

35e357056b06b04b2b97994c66fa98012425f924	refs/heads/dev/observer-pattern

3f2cc1dfe1069dbad0650fd1eaf6a1e5492ee86f	refs/heads/dev/vehicle-behaviors

0ff4d1b1c12bb6ab1882f73b057fc8aa8d8bfa66	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

647a5ebd468b601715d67b91b4dacfbff7634172	refs/heads/fix/02-robot-walls

182468b97829c240822faca09865caecdc99ad60	refs/heads/fix/cpplint-const

0c60526b4c434f41911937444c7a8f59a2abef79	refs/heads/master

b179867dfb0be8097bdb6187c49581a494c9d72b	refs/heads/pre-release/iteration1

a6f4f90ca13c9ed2c24846136b6d4a93bfca61d9	refs/heads/release/iteration1

d9b98d1b0d837037d7fc3e5afcc78c656b2be0ca	refs/heads/release/iteration2-prelim1

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 3)

[OPEN issue #17] :  BV Behavior is reversed [bug] 2

[OPEN issue #16] :  Implement Predator Class

[OPEN issue #15] :  Implement Observer Pattern





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 14)

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
AggressiveBehavior.cc:7:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
AggressiveBehavior.cc:0:  project/src/AggressiveBehavior.cc should include its header file project/src/AggressiveBehavior.h  [build/include] [5]
braitenberg_vehicle.cc:29:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.cc:31:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:118:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.cc:118:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
braitenberg_vehicle.cc:174:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:175:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:235:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
CowardBehavior.cc:7:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
CowardBehavior.cc:0:  project/src/CowardBehavior.cc should include its header file project/src/CowardBehavior.h  [build/include] [5]
ExploreBehavior.cc:7:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
ExploreBehavior.cc:0:  project/src/ExploreBehavior.cc should include its header file project/src/ExploreBehavior.h  [build/include] [5]
graphics_arena_viewer.cc:327:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:327:  At least two spaces is best between code and comments  [whitespace/comments] [2]
graphics_arena_viewer.cc:329:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:329:  At least two spaces is best between code and comments  [whitespace/comments] [2]
graphics_arena_viewer.cc:333:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:335:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:339:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:341:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:425:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
graphics_arena_viewer.cc:425:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
graphics_arena_viewer.cc:435:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
graphics_arena_viewer.cc:435:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
graphics_arena_viewer.cc:442:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:443:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:444:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:445:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:446:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:447:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:448:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
LoveBehavior.cc:0:  project/src/LoveBehavior.cc should include its header file project/src/LoveBehavior.h  [build/include] [5]
AggressiveBehavior.h:13:  You don't need a ; after a }  [readability/braces] [4]
AggressiveBehavior.h:19:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_vehicle.h:140:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:140:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.h:152:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.h:153:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:153:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.h:154:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:171:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:185:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.h:186:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:186:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.h:187:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:204:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:226:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
CowardBehavior.h:12:  You don't need a ; after a }  [readability/braces] [4]
ExploreBehavior.h:12:  You don't need a ; after a }  [readability/braces] [4]
ExploreBehavior.h:18:  At least two spaces is best between code and comments  [whitespace/comments] [2]
graphics_arena_viewer.h:56:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.h:225:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
graphics_arena_viewer.h:224:  Add #include <vector> for vector<>  [build/include_what_you_use] [4]
LoveBehavior.h:12:  You don't need a ; after a }  [readability/braces] [4]
LoveBehavior.h:18:  At least two spaces is best between code and comments  [whitespace/comments] [2]
Observer.h:12:  You don't need a ; after a }  [readability/braces] [4]
Observer.h:16:  You don't need a ; after a }  [readability/braces] [4]
Observer.h:21:  At least two spaces is best between code and comments  [whitespace/comments] [2]
Observer.h:16:  Add #include <vector> for vector<>  [build/include_what_you_use] [4]
Subject.h:12:  You don't need a ; after a }  [readability/braces] [4]
Subject.h:16:  You don't need a ; after a }  [readability/braces] [4]
Subject.h:21:  You don't need a ; after a }  [readability/braces] [4]
Subject.h:26:  You don't need a ; after a }  [readability/braces] [4]
Subject.h:31:  At least two spaces is best between code and comments  [whitespace/comments] [2]
WheelBehavior.h:12:  You don't need a ; after a }  [readability/braces] [4]
WheelBehavior.h:18:  At least two spaces is best between code and comments  [whitespace/comments] [2]
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
Done processing rgb_color.h
Done processing Subject.h
Done processing WheelBehavior.h
Done processing wheel_velocity.h
Total errors found: 67
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

