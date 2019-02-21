### Feedback for Lab 09

Run on February 20, 21:18:48 PM.


#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab09_robots" exists.

+ Pass: Change into directory "labs/lab09_robots".

+ Pass: Check that make compiles.



+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "Lab09".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>==== Auto-Generating Dependencies for ../src/robot_land.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/robot_land.d -MP -MT ../build/obj/tests/robot_land.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -std=c++14 ../src/robot_land.cc
==== Compiling ../src/robot_land.cc into ../build/obj/tests/robot_land.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -std=c++14  -c -o  ../build/obj/tests/robot_land.o ../src/robot_land.cc
==== Auto-Generating Dependencies for robot_unittest.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/tests/robot_unittest.d -MP -MT ../build/obj/tests/robot_unittest.o -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c -I/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -std=c++14 robot_unittest.cc
robot_unittest.cc:7:10: fatal error: src/robot.h: No such file or directory
 #include "src/robot.h"
          ^~~~~~~~~~~~~
compilation terminated.
Makefile:141: recipe for target '../build/obj/tests/robot_unittest.o' failed
make: *** [../build/obj/tests/robot_unittest.o] Error 1
</pre>



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

