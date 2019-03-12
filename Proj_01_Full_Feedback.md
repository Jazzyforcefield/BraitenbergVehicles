### Feedback for Proj 01

Run on March 12, 15:17:35 PM.

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

+ Pass: Check that file "docs/design.pdf" exists.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Pass: Check git commit history
Sufficient commits (found=45,required=25)

+ Pass: Run git ls-remote to check for # of branches in repo
Sufficient branches (found=6,required=4)

+ Pass: Run git ls-remote gather all branches in repo

3f2cc1dfe1069dbad0650fd1eaf6a1e5492ee86f	refs/heads/dev/vehicle-behaviors

b354a8b938d0012028515fbf8849ca7afa8dadcb	refs/heads/devel

ac0e383e5b5007aca00575417ee7ee75b4164926	refs/heads/fix/01-compilation-errors

647a5ebd468b601715d67b91b4dacfbff7634172	refs/heads/fix/02-robot-walls

11c5e3a93d72fad48500001465e1f6cbae3e4dff	refs/heads/master

726e6a78bc90651955db2c59a9588b2ce741df0b	refs/heads/support-code




#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src'
==== Checking style is correct ====
/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:239:  Tab found; better to use spaces  [whitespace/tab] [1]
arena.cc:239:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
arena.cc:239:  Extra space after ( in function call  [whitespace/parens] [4]
arena.cc:46:  Add #include <string> for string  [build/include_what_you_use] [4]
braitenberg_vehicle.cc:100:  Tab found; better to use spaces  [whitespace/tab] [1]
braitenberg_vehicle.cc:105:  Tab found; better to use spaces  [whitespace/tab] [1]
braitenberg_vehicle.cc:110:  Tab found; better to use spaces  [whitespace/tab] [1]
braitenberg_vehicle.cc:129:  Tab found; better to use spaces  [whitespace/tab] [1]
braitenberg_vehicle.cc:134:  Tab found; better to use spaces  [whitespace/tab] [1]
braitenberg_vehicle.cc:139:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
BraitenbergVehicleFactory.cc:7:  You don't need a ; after a }  [readability/braces] [4]
BraitenbergVehicleFactory.cc:10:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.cc:11:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.cc:14:  You don't need a ; after a }  [readability/braces] [4]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
Factory.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
Factory.cc:8:  Tab found; better to use spaces  [whitespace/tab] [1]
Factory.cc:11:  You don't need a ; after a }  [readability/braces] [4]
Factory.cc:1:  grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src/Factory.cc should include its header file grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src/Factory.h  [build/include] [5]
FoodFactory.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
FoodFactory.cc:7:  You don't need a ; after a }  [readability/braces] [4]
FoodFactory.cc:10:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.cc:11:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.cc:14:  You don't need a ; after a }  [readability/braces] [4]
graphics_arena_viewer.cc:39:  Missing spaces around =  [whitespace/operators] [4]
graphics_arena_viewer.cc:46:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
graphics_arena_viewer.cc:46:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
LightFactory.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
LightFactory.cc:7:  You don't need a ; after a }  [readability/braces] [4]
LightFactory.cc:10:  Tab found; better to use spaces  [whitespace/tab] [1]
LightFactory.cc:11:  Tab found; better to use spaces  [whitespace/tab] [1]
LightFactory.cc:14:  You don't need a ; after a }  [readability/braces] [4]
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:52:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
arena.h:55:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
behavior_enum.h:37:  Add #include <string> for string  [build/include_what_you_use] [4]
BraitenbergVehicleFactory.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
BraitenbergVehicleFactory.h:12:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.h:13:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.h:14:  Tab found; better to use spaces  [whitespace/tab] [1]
BraitenbergVehicleFactory.h:15:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:19:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:20:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:21:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:20:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.h:72:  Tab found; better to use spaces  [whitespace/tab] [1]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
Factory.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
Factory.h:12:  Tab found; better to use spaces  [whitespace/tab] [1]
Factory.h:13:  Tab found; better to use spaces  [whitespace/tab] [1]
Factory.h:14:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
FoodFactory.h:12:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.h:13:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.h:14:  Tab found; better to use spaces  [whitespace/tab] [1]
FoodFactory.h:15:  Tab found; better to use spaces  [whitespace/tab] [1]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
LightFactory.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
LightFactory.h:12:  Tab found; better to use spaces  [whitespace/tab] [1]
LightFactory.h:13:  Tab found; better to use spaces  [whitespace/tab] [1]
LightFactory.h:14:  Tab found; better to use spaces  [whitespace/tab] [1]
LightFactory.h:15:  Tab found; better to use spaces  [whitespace/tab] [1]
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
Total errors found: 67
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-ungxx028/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Unit Tests

+ Pass: Check that file "build/bin/unittest" exists.

+ Fail: Check that a GoogleTest test passes.
    fails the test: InstBraitenbergVehicle.ColorMatchesBehavior.
<pre>
[ RUN      ] InstBraitenbergVehicle.ColorMatchesBehavior
inst_braitenberg_vehicle.cc:48: Failure
Expected equality of these values:
  bv->get_color()
    Which is: 12-byte object <7A-00 00-00 00-00 00-00 19-00 00-00>
  csci3081::RgbColor(csci3081::kBlue)
    Which is: 12-byte object <00-00 00-00 00-00 00-00 FF-00 00-00>
The robot's color should be Blue when there is only a food behavior.
inst_braitenberg_vehicle.cc:57: Failure
Expected equality of these values:
  bv->get_color()
    Which is: 12-byte object <7A-00 00-00 00-00 00-00 19-00 00-00>
  csci3081::RgbColor(csci3081::kGold)
    Which is: 12-byte object <FF-00 00-00 CC-00 00-00 33-00 00-00>
The robot's color should be Gold when there is only a light behavior.</pre>



+ Pass: Check that a GoogleTest test passes.
    passes the test: InstBraitenbergVehicle.RobotMovesInEmptyScene.



