# Proof-of-Concept for the Robot Simulator Project for 3081W

The base code for the robot simulator project of 3081W was born from this
proof-of-concept application written by Dan Keefe. There are 2 primary
components: the <i>robot_viewer</i> and <i>robot_land</i>. Robots live in robot land and are quite oblivious to being viewed by the viewer. The viewer is in control of everything in that it sends a message to robot_land to update, meaning move the robots the appropriate amount given how much time has passed since the last update. It then gets the appropriate positional information from each robot and draws these to the screen. All the while, the system is listening for keyboard and mouse activity by the user. If any action occurs, the associated callback is executed.

<hr>

## Mechanics of the System

### Resources

You will probably want to refer to these as you work on the lab.

- libMinGfx : https://github.com/ivlab/MinGfx
- nanogui : https://github.com/wjakob/nanogui
- nanogui documentation: https://nanogui.readthedocs.io/en/latest/
- nanovg : https://github.com/memononen/NanoVG
- Google Style Guide : https://google.github.io/styleguide/cppguide.html
- cpplint : https://github.com/google/styleguide/tree/gh-pages/cpplint

### libMinGfx and /project/f17c3081

The robot viewer is derived from `GraphicsApp` in MinGfx. When building the
simulator, the local object files are linked with libMinGfx, which are being created locally the first time you run _make_.

> **Do not submit to your repo any of the code from libMinGfx.**

### Directory Structure

The directory structure for this lab is identical to that of the project.

- `Makefile`:
   - `make all` and `make clean` for the whole project (calls make recursively
     in subdirs).

- `src`:
  - All source code (.cc AND .h) lives under here. For this lab, that is
    robot_viewer.h/cc and robot_land.h/cc.

- `src/Makefile`:
<<<<<<< HEAD
  - You should *NOT* have to modify this makefile _EXCEPT_ for the `CS3081DIR`
    variable described above (both for this lab and the project).
=======
>>>>>>> support-code
  - Builds the project source, assumes it should build all .cc files in the
    current directory.
  - Creates the `build/bin/robotviewer` executable.
  - Uses g++ auto dependency generation to get dependencies from #includes in
    .cc files (So that you don't have to worry about this).

- `build`: Created by the Makefiles. Should be added to your `.gitignore`.
  - `build/bin`: All executables generated for the project will appear in here.
  - `build/obj`: all .o's and .d's (from make depend) go in here.
  - **Do not push the build folder to your repo**

<hr>

## Getting Started

1. _pull_ into your support-code branch on your repo.

2. _merge_ the new lab code into your master branch.

3. At the top level from the OS command prompt: `make`. The first time you make, a local version of the MinGfx library will be built. This might take awhile (and it is likely you will only be able to do this on a cselabs machine unless you have the appropriate software installed on your personal machine, such as cmake and OpenGL). After the first build, compilation should go faster.

4. At the command prompt: `./build/bin/robotviewer`. You will not be able to run the executable from any remote connection other than Vole3d. It will compile, but you will not be able to run it.

<hr>

## Code Explanation

### class GraphicsApp

The GraphicsApp makes use of the nanogui, nanovg, and openGL libraries to create
a window with 2D graphics and a GUI. As with most graphics applications, there
is a main loop in which keyboard and mouse events are handled, then all objects
in the graphics window are drawn. The loop is executed at the frame rate until
the application is closed. The actual loop is in the Run method of GraphicsApp, important excerpts shown below.
Notice the **two very important function calls `UpdateSimulation()` and `DrawUsingNanoVG()`.**

```C++
void GraphicsApp::Run() {
  while (!glfwWindowShouldClose(window_) {  // while graphics window open
    glfwPollEvents();  // handle key presses and mouse clicks
    UpdateSimulation(now-lastDrawT_);  // change state of relevant objects
    DrawUsingNanoVG(screen_->nvgContext());  // draw all relevant objects
  }
}
```
<br>

### class RobotViewer in robot_viewer.h / .cc

RobotViewer is a subclass of GraphicsApp. In this application, it is
instantiated in main() with the name _app_. Notice in the constructor of
RobotViewer, you see the instantiation of `RobotLand`. The simulator gets
started with a call to app->Run(), which enters the loop discussed above:

```C++
int main(int argc, char **argv) {
   csci3081::RobotViewer *app = new csci3081::RobotViewer();
   app->Run();
   return 0;
}
```

> We have done a minimal review of namespaces thus far, but this is an important part of large projects to avoid name clashes. Notice that `NAMESPACE_BEGIN(csci3081);` precedes class definitions. This means that you have to provide scope for any of the methods called within that namespace. This is why you see `csci3081::RobotViewer()` and not `RobotViewer()`.

Recall that in the Run() function of the GraphicsApp, there is a call to
`UpdateSimulation()` and `DrawUsingNanoVG()`. **Look at these function definitions
in <i>robot_viewer.cc</i>**. All that is happening in Update is a call to robot land to update based on how much time has passed. In the draw function, each object of robot land is being drawn. Notice that the graphics commands for drawing each of the objects begins with `nvg` for nanovg. The header file
`https://github.com/memononen/nanovg/blob/master/src/nanovg.h` is fairly well
documented. Take a moment to look at this header file and read about some of the
function calls that you see in drawing the various graphics objects
(e.g. DrawRobot, DrawObstacle).

(The keyboard and mouse event processing is discussed below.)

<br>

### class RobotLand

RobotLand has no awareness of RobotViewer, despite the fact that it was
instantiated inside of the viewer. You can think about robots in RobotLand
constantly moving, even though they move in the graphics window in discrete steps. The idea is that periodically the robot viewer takes a snapshot of the situation and displays it on the screen. RobotViewer interacts with RobotLand through getters. In the current code base, the viewer gets those pieces of information from RobotLand that are necessary for drawing the robots and the obstacle. When you are done with this lab, a whole Robot object will be passed to the viewer for drawing.

Currently, RobotLand consists of one stationary "obstacle" and two robots going
around in circles. (Obstacle is in quotes because currently the robots are passing right through it.) No robot class **_currently_** exists, but you will be implementing one as part of this lab. The position and direction of each robot is determined by the circular pattern they are following. A call to circle_x() and circle_y() with a time value will generate the current position of the robot.

Notice that the RobotLand::AdvanceTime() sets the current time of the simulation. When the robot viewer needs to draw the objects, circle_x and circle_y are called to calculate and return the current position of the robot.

### Keyboard and Mouse Event Handling

Events are handled inside the robot viewer, because this manages all aspects of the GUI. Look in robot_viewer.cc to see the various events to be handled
(e.g. OnKeyDown(), which handles a key press). The name gives an
indication of which event it is responding to. When that event occurs, this is
the function that is called. You never see the call to this function, but know
that it does happen. Currently, for the most part, events are handled by
printing messages to a terminal, but they really come in handy when you want the
user to interact with the graphics window. For example, you might want the
functionality that wherever the user clicks the mouse, a robot is created at
that position. In this lab, you will be creating a couple of buttons to change the color of each robot.

The menu you see in the application with a reset and pause button was a custom
menu made for this application. If you downloaded the nanogui examples, you saw
how complex these menus can be. It is quite easy to add buttons with various
functionality to the menu. Let's trace that process through the code ...

It starts in RobotViewer::InitNanoGUI (this overrides GraphicsApp::InitNanoGUI):

```C++
nanogui::FormHelper *gui = new nanogui::FormHelper(screen());

nanogui::ref<nanogui::Window> window =
   gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
pause_btn_ =
   gui->addButton("Pause", std::bind(&RobotViewer::OnPauseBtnPressed, this));
gui->addButton("Restart", std::bind(&RobotViewer::OnRestartBtnPressed, this));
```

You start with the instantiation of FormHelper, then add the various
components. The parameters being passed to the `addButton` are the name that
appears on the button and the _callback_ function, meaning the one that is
called when the button is pressed (which is registered via a mouse
click). Again, all of this is going on behind the scenes and you will not see an
explicit call to the callback function.

Next, look at each of the functions passed to the "Restart" and "Pause" buttons:

```C++
void RobotViewer::OnRestartBtnPressed() {
   robot_land_->set_time(0.0); }

void RobotViewer::OnPauseBtnPressed() {
   paused_ = !paused_;
   if (paused_) {
   pause_btn_->setCaption("Play");
   } else {
   pause_btn_->setCaption("Pause");
   }
}
```

At this point, you should have a general understanding of the framework for the
graphics application. If you are really not understanding it, read through again
or talk to a peer.

Seriously, do it. The project works in the same way, and is MUCH larger, so you
should try to have a good handle on the basic flow of control before continuing with this
lab, and eventually the project.

<hr>

## The Lab Assignment

### Create a Robot Class

1. Add a robot class to the application. Define the robot class in the 2 files
   _robot.h_ and _robot.cc_. Use the robot class to save the radius, color,
   position, speed, and direction. A file "point.h" has been included to store the {x,y} position of the robot. The Robot class must have (at least) the following interface. You are welcome to add methods and variables as seems appropriate.

```C++
/**
 * @brief An entity in RobotLand that moves around the window.
 *
 * Its id, size, initial position, and velocity are fixed.
 * The position and direction are updated at each frame refresh.
 * The color can be changed via a user button in the RobotViewer.
 */
class Robot {

public:
  /**
   * @brief A Robot is instantiated with a user-defined id, radius, and origin.
   * The constructor must also set the position, direction, color,
   * and sensor range and angle.
   *
   * @param[in] id The identifying number of the robot (now just 0 or 1)
   * @param[in] radius The radius of the graphics circle representing the robot.
   * @param[in] origin The {x,y} position around which the robot rotates.
   * @param[in] speed It controls the speed at which robot moves in circle
   */
	Robot(int id, double radius, Point origin, double speed);

  /**
    * @brief Given time, update the {x,y} position and direction angle of the Robot.
    *
    * @param[in] time The sim_time since the start of the simulator.
    */    
  void Update(double time);

  bool get_color();
  void set_color(bool color);
  int get_id();
  double get_radius();
  Point get_position();
  double get_direction();
  double get_sensor_angle();
  double get_sensor_range();

private:
  int id_;
  double radius_;  // pixel units for size of robot in graphics window.
  bool color_;     // "true" will color in the robot, "false" leaves it white.
  Point origin_;   // center of circle around which robot is rotating
  double speed_;    // fixed constant to control rate of movement
  Point position_; // current {x,y} position in graphics window
  double direction_; // current directional angle in radians
  double sensor_angle_; // angle between sensors relative to robot center.
  double sensor_range_;  // distance range of sensor.
};
```

<<<<<<< HEAD
2. The constructor initializes all class members. The origin should be set to {512,350}. The Update function calculates the new robot position based on the circle_x and circle_y equations of the original base code. It updates direction, based on the calculated velocity (i.e. change in x and y).

> Notice that the robots move at a different rate around the circle, which is accomplished in the base code by modifying the simulation time. For your robot, use the speed_ variable to control this. Also, notice how the direction is calculated in the RobotViewer in DrawUsingNanoVG based on velocity and then taking atan2(delta_y, delta_x). For your robot, the direction corresponds to the atan2 results.

The setters and getters for Robot are straightforward, but ask if you have questions. You do not need your robot class functional or working in the context of the graphics viewer to receive feedback about the Robot class.

### Incorporate Robot Class into RobotLand

1. Define Robot **pointers** as members of RobotLand. These can be 2 separate pointers or combined into an array. Instantiate the robots in the RobotLand constructor. Destroy the robots in the RobotLand destructor.
=======
2. The constructor initializes all class members based on the user-defined parameters AND for other member variables, use the values given in the provided code. The origin should be set to {512,350} **when you instantiate in RobotLand**. Initialize the position of the robot based on the user-defined origin and a sim_time_ of 0. The Update function calculates the new robot position based on the circle_x and circle_y equations of the original base code. It updates direction, based on the calculated velocity (i.e. change in x and y), as shown in DrawUsingNanoVG.

> Notice that the robots move at a different rate around the circle, which is accomplished in the base code by scaling the simulation time. For your robot, use the speed_ variable to control this. Also, notice how the direction is calculated in the RobotViewer in DrawUsingNanoVG based on velocity and then taking atan2(delta_y, delta_x). For your robot class, the direction corresponds to the atan2 results, and this should be calculated in the Robot then the RobotViewer uses a getter to get that information.

The setters and getters for Robot are straightforward, but ask if you have questions. You do not need your robot class functional or working in the context of the graphics viewer to receive feedback about the Robot class from the automated grading script.

### Incorporate Robot Class into RobotLand

1. Define Robot **pointers** as members of RobotLand. These can be 2 separate pointers or combined into an array. Instantiate the robots in the RobotLand constructor, setting the user-defined parameters for the Robot **such that they will look and behave exactly like they do in the provided code**. Destroy the robots in the RobotLand destructor.
>>>>>>> support-code

2. In `RobotLand::AdvanceTime()`, call Robot::Update(time) for each robot. The Update() function will update the position and direction of the robot.

3. Add the method Robot * RobotLand::get_robot(int id). This returns the Robot object with the passed id.

4. Remove the following methods from RobotLand:
  - get_robot_pos
  - get_robot_vel
  - get_robot_radius
  - get_robot_sensor_range
  - get_robot_sensor_angle
  - circle_x
  - circle_y

<hr>

### Incorporate Robot Class into RobotViewer

In RobotViewer::DrawUsingNanoVG, there is a for-loop for drawing robots. In this for-loop, instead of getting the pieces of information needed from the robot, pass along the whole robot object to RobotViewer::DrawRobot. The new signature for DrawRobot should be:

  ```
  void DrawRobot(NVGcontext *ctx, Robot * robot)
  ```

Within DrawRobot, use the setters and getters of the Robot class to extract the appropriate information. Make sure you retain the nvgSave and nvgRestore calls.

<hr>

### Add Buttons to Change Robot Color

1. Add 2 buttons to the GUI to change the color of each robot.
   - Create OnColorChangeBtnPressed0() method to change the color of robot 0.
   - Create OnColorChangeBtnPressed1() method to change the color of robot 1.
<<<<<<< HEAD
   - Create 2 new nanogui buttons in the RobotViewer constructor, binding its
=======
   - Create 2 new nanogui buttons in the RobotViewer InitNanoGUI, binding its
>>>>>>> support-code
     click action to the functions you just created (look at the other buttons in RobotViewer::InitNanoGUI for examples of how to do this).

2. In `RobotViewer::DrawRobots`, incorporate Robot::color_. If it is true, then fill the robot circle with maroon (or whatever color you want):
```
nvgFillColor(ctx, nvgRGBA(122, 0, 25, 255));
```
else, make it white (or whatever color you want):
```
nvgFillColor(ctx, nvgRGBA(255, 255, 255, 255));
```

Push your code up to your repo for feedback.

<hr>

### OPTIONAL linter

Run your code through the linter and fix any errors. In the project, any submitted code must not have any cpplint errors, so please get into the habit of making your code Google Style compliant.
