### Feedback for Lab 09

Run on February 25, 15:05:21 PM.


#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab09_robots" exists.

+ Pass: Change into directory "labs/lab09_robots".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>make -C src all
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Lab_09_Feedback/repo-ungxx028/labs/lab09_robots/src'
==== Auto-Generating Dependencies for robot_viewer.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/robot_viewer.d -MP -MT ../build/obj/src/robot_viewer.o -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 robot_viewer.cc
==== Compiling robot_viewer.cc into ../build/obj/src/robot_viewer.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/robot_viewer.o robot_viewer.cc
==== Auto-Generating Dependencies for robot_land.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/robot_land.d -MP -MT ../build/obj/src/robot_land.o -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 robot_land.cc
==== Compiling robot_land.cc into ../build/obj/src/robot_land.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/robot_land.o robot_land.cc
==== Auto-Generating Dependencies for main.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/main.d -MP -MT ../build/obj/src/main.o -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 main.cc
==== Compiling main.cc into ../build/obj/src/main.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/main.o main.cc
==== Auto-Generating Dependencies for robot.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/robot.d -MP -MT ../build/obj/src/robot.o -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 robot.cc
==== Compiling robot.cc into ../build/obj/src/robot.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Wall -g -std=c++14 -Wno-unused -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/robot.o robot.cc
In file included from robot.cc:1:0:
robot.h:24:31: error: ‘Point’ has not been declared
  Robot(int id, double radius, Point origin, double speed);
                               ^~~~~
robot.h:37:3: error: ‘Point’ does not name a type; did you mean ‘int’?
   Point get_position();
   ^~~~~
   int
robot.h:46:3: error: ‘Point’ does not name a type; did you mean ‘int’?
   Point origin_;   // center of circle around which robot is rotating
   ^~~~~
   int
robot.h:48:3: error: ‘Point’ does not name a type; did you mean ‘int’?
   Point position_; // current {x,y} position in graphics window
   ^~~~~
   int
robot.cc:3:7: error: redefinition of ‘class Robot’
 class Robot {
       ^~~~~
In file included from robot.cc:1:0:
robot.h:11:7: note: previous definition of ‘class Robot’
 class Robot {
       ^~~~~
robot.cc:47:1: error: expected unqualified-id at end of input
 }
 ^
Makefile:105: recipe for target '../build/obj/src/robot.o' failed
make[1]: *** [../build/obj/src/robot.o] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Lab_09_Feedback/repo-ungxx028/labs/lab09_robots/src'
Makefile:14: recipe for target 'proj01' failed
make: *** [proj01] Error 2
</pre>



+ Skip: Copy directory "Files for Testing".

  This test was not run because of an earlier failing test.

+ Skip: Change into directory "Lab09".

  This test was not run because of an earlier failing test.

+ Skip: Check that make compiles.

  This test was not run because of an earlier failing test.

+ Skip: Check that directory "../build/bin" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

