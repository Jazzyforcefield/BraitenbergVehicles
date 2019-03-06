### Feedback for Proj 01

Run on March 05, 18:06:19 PM.

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

+ Fail: Check that file "src/mainpage.h" exists.

     "src/mainpage.h" not found.

+ Fail: Check that file "docs/uml_design.pdf" exists.

     "docs/uml_design.pdf" not found.

+ Fail: Check that file "docs/design.pdf" exists.

     "docs/design.pdf" not found.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


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
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
graphics_arena_viewer.cc:39:  Missing spaces around =  [whitespace/operators] [4]
graphics_arena_viewer.cc:46:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
graphics_arena_viewer.cc:46:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:52:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
arena.h:55:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
behavior_enum.h:37:  Add #include <string> for string  [build/include_what_you_use] [4]
common.h:15:  <chrono> is an unapproved C++11 header.  [build/c++11] [5]
common.h:22:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:23:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:24:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:23:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.h:72:  Tab found; better to use spaces  [whitespace/tab] [1]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing controller.cc
Done processing food.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
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
Done processing braitenberg_vehicle.h
Done processing common.h
Done processing controller.h
Done processing entity_type.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 22
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



+ Fail: Check that a GoogleTest test passes.
    fails the test: InstBraitenbergVehicle.RobotMovesInEmptyScene.
<pre>
[ RUN      ] InstBraitenbergVehicle.RobotMovesInEmptyScene
inst_braitenberg_vehicle.cc:70: Failure
Expected: ((bv->get_pose()-prevPose).Length()) > (0.005f), actual: 0 vs 0.005
The robot should move with Love even if there are not lights or food.</pre>



