### Feedback for Proj 01

Run on March 15, 13:16:58 PM.

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Compile Tests

+ Pass: Clean project.



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/arenaviewer" exists.


#### Documentation Tests

+ Pass: Check that file "docs/uml_design.pdf" exists.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Pass: Check git commit history
Sufficient commits (found=58,required=25)

+ Pass: Run git ls-remote gather all branches in repo

5eaf039e96955d29acfa3431a7c67bd20bf46780	refs/heads/dev/collision-avoidance

76e45f201d1dcecab99e4cd5a7e9b53cf9d3484c	refs/heads/dev/factory-implementation

595fdf43e2ce4fb1c2d263f5f7000d3a31cf0615	refs/heads/dev/json-factories

3f2cc1dfe1069dbad0650fd1eaf6a1e5492ee86f	refs/heads/dev/vehicle-behaviors

595fdf43e2ce4fb1c2d263f5f7000d3a31cf0615	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

647a5ebd468b601715d67b91b4dacfbff7634172	refs/heads/fix/02-robot-walls

b9878699ac10d51f2c8961420c018e61124df5b3	refs/heads/master

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 3)

[OPEN issue #11] :  Implement json configuration for factory classes

[OPEN issue #7] :  Update uml_design.pdf to include relationships between Arena and BraitenbergVehicle

[OPEN issue #6] :  Refactor BraitenbergVehicle class 





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 8)

[CLOSED issue #10] :  Implement colors to BV 1 @ungxx028

[CLOSED issue #9] :  Add collision avoidance behavior to BV 1 @ungxx028

[CLOSED issue #8] :  Implement BV behaviors 1

[CLOSED issue #5] :  Rename UML.pdf to uml_design.pdf 1

[CLOSED issue #4] :  Implement FactoryPointer and subclasses

[CLOSED issue #3] :  fix(arena_mobile_entity.h) ↑

[CLOSED issue #2] :  Robots getting stuck in walls [bug] 1

[CLOSED issue #1] :  Compilation error [bug] 1






#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src'
==== Checking style is correct ====
/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/cpplint/cpplint.py --root=.. *.cc *.h
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:59:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
common.h:20:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:21:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
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
Total errors found: 4
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Unit Tests

+ Pass: Check that file "build/bin/unittest" exists.

+ Pass: Check that a GoogleTest test passes.
    passes the test: InstBraitenbergVehicle.RobotMovesInEmptyScene.



