### Feedback for Proj 01

Run on March 15, 00:27:19 AM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

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
Commits found=56

+ Pass: Run git ls-remote gather all branches in repo

5eaf039e96955d29acfa3431a7c67bd20bf46780	refs/heads/dev/collision-avoidance

76e45f201d1dcecab99e4cd5a7e9b53cf9d3484c	refs/heads/dev/factory-implementation

3f2cc1dfe1069dbad0650fd1eaf6a1e5492ee86f	refs/heads/dev/vehicle-behaviors

bf7b61ced8e7b632dff74506d85224d8e7bca4a1	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

647a5ebd468b601715d67b91b4dacfbff7634172	refs/heads/fix/02-robot-walls

5457d4e08d5632c03647c3bd38d33e6f9828cfc1	refs/heads/master

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 3)

[OPEN issue #7] :  Update uml_design.pdf to include relationships between Arena and BraitenbergVehicle

[OPEN issue #6] :  Refactor BraitenbergVehicle class 

[OPEN issue #4] :  Implement FactoryPointer and subclasses





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 7)

[CLOSED issue #10] :  Implement colors to BV 1 @ungxx028

[CLOSED issue #9] :  Add collision avoidance behavior to BV 1 @ungxx028

[CLOSED issue #8] :  Implement BV behaviors 1

[CLOSED issue #5] :  Rename UML.pdf to uml_design.pdf 1

[CLOSED issue #3] :  fix(arena_mobile_entity.h) ↑

[CLOSED issue #2] :  Robots getting stuck in walls [bug] 1

[CLOSED issue #1] :  Compilation error [bug] 1






#### Documentation Tests

+ Pass: Check that file "docs/uml_design.pdf" exists.


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-ungxx028/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-ungxx028/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:243:  Tab found; better to use spaces  [whitespace/tab] [1]
arena.cc:243:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
arena.cc:243:  Extra space after ( in function call  [whitespace/parens] [4]
arena.cc:50:  Add #include <string> for string  [build/include_what_you_use] [4]
braitenberg_vehicle.cc:88:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.cc:92:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:92:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:95:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:95:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:126:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
braitenberg_vehicle.cc:126:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
braitenberg_vehicle.cc:138:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
Factory.cc:3:  project/src/Factory.cc should include its header file project/src/Factory.h  [build/include] [5]
graphics_arena_viewer.cc:39:  Missing spaces around =  [whitespace/operators] [4]
graphics_arena_viewer.cc:46:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
graphics_arena_viewer.cc:46:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:56:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
arena.h:59:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
behavior_enum.h:37:  Add #include <string> for string  [build/include_what_you_use] [4]
BraitenbergVehicleFactory.h:3:  #ifndef header guard has wrong style, please use: SRC_BRAITENBERGVEHICLEFACTORY_H_  [build/header_guard] [5]
BraitenbergVehicleFactory.h:22:  #endif line should be "#endif  // SRC_BRAITENBERGVEHICLEFACTORY_H_"  [build/header_guard] [5]
common.h:19:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:20:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:21:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:20:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.h:72:  Tab found; better to use spaces  [whitespace/tab] [1]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
Factory.h:3:  #ifndef header guard has wrong style, please use: SRC_FACTORY_H_  [build/header_guard] [5]
Factory.h:21:  #endif line should be "#endif  // SRC_FACTORY_H_"  [build/header_guard] [5]
FoodFactory.h:3:  #ifndef header guard has wrong style, please use: SRC_FOODFACTORY_H_  [build/header_guard] [5]
FoodFactory.h:23:  #endif line should be "#endif  // SRC_FOODFACTORY_H_"  [build/header_guard] [5]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
LightFactory.h:3:  #ifndef header guard has wrong style, please use: SRC_LIGHTFACTORY_H_  [build/header_guard] [5]
LightFactory.h:22:  #endif line should be "#endif  // SRC_LIGHTFACTORY_H_"  [build/header_guard] [5]
mainpage.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
mainpage.h:0:  No #ifndef header guard found, suggested CPP variable is: SRC_MAINPAGE_H_  [build/header_guard] [5]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing BraitenbergVehicleFactory.cc
Done processing controller.cc
Done processing Factory.cc
Done processing food.cc
Done processing FoodFactory.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
Done processing LightFactory.cc
Done processing main.cc
Done processing motion_behavior.cc
Done processing motion_behavior_differential.cc
Done processing rgb_color.cc
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
Done processing entity_type.h
Done processing Factory.h
Done processing FoodFactory.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing LightFactory.h
Done processing light.h
Done processing mainpage.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 40
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-ungxx028/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

