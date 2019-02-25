### Feedback for Lab 09

Run on February 25, 17:42:50 PM.


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



+ Pass: Check that a GoogleTest test passes.
    passes the test: RobotTest.UpdateRobot0.



+ Fail: Check that a GoogleTest test passes.
    fails the test: RobotTest.UpdateRobot1.
<pre>
[ RUN      ] RobotTest.UpdateRobot1
robot_unittest.cc:58: Failure
The difference between robot1->get_position().x_ and new_x is 121.48628179126055, which exceeds .005, where
robot1->get_position().x_ evaluates to 54.030230586813978,
new_x evaluates to 175.51651237807454, and
.005 evaluates to 0.0050000000000000001.
FAIL: x_ update
robot_unittest.cc:59: Failure
The difference between robot1->get_position().y_ and new_y is 11.738009240050957, which exceeds .005, where
robot1->get_position().y_ evaluates to 84.147098480789651,
new_y evaluates to 95.885107720840608, and
.005 evaluates to 0.0050000000000000001.
FAIL: y_ update
robot_unittest.cc:60: Failure
The difference between robot1->get_direction() and dir is 0.79785849061556435, which exceeds .005, where
robot1->get_direction() evaluates to 2.6186548174104609,
dir evaluates to 1.8207963267948966, and
.005 evaluates to 0.0050000000000000001.
FAIL: dir update</pre>



