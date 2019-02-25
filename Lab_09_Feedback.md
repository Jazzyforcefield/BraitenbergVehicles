### Feedback for Lab 09

Run on February 25, 16:42:20 PM.


#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab09_robots" exists.

+ Pass: Change into directory "labs/lab09_robots".

+ Pass: Check that make compiles.



+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "Lab09".

+ Pass: Check that make compiles.



+ Pass: Check that directory "../build/bin" exists.

+ Pass: Check that a GoogleTest test passes.
    passes the test: RobotTest.ConstructorUserDefined.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RobotTest.ConstructorDefault.



+ Fail: Check that a GoogleTest test passes.
    fails the test: RobotTest.UpdateRobot0.
<pre>
[ RUN      ] RobotTest.UpdateRobot0
robot_unittest.cc:48: Failure
The difference between robot0->get_direction() and dir is 2.5707963267948966, which exceeds .005, where
robot0->get_direction() evaluates to -0.49999999999999994,
dir evaluates to 2.0707963267948966, and
.005 evaluates to 0.0050000000000000001.
FAIL: dir update</pre>



+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

