/**
 * @file robot_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_VIEWER_H_
#define SRC_ROBOT_VIEWER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <MinGfx-1.0/mingfx.h>
#include "src/robot_land.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
#define __unused __attribute__((unused))

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 *  @brief An application that uses the cs3081 SimpleGraphics library to open up
 *  a window that includes a few buttons for controlling the simulation and can
 *  be used to draw circles and other computer graphics.
 *
 *  After constructing a new RobotViewer, call Run() to start and run the
 *  application.  Run() will not return until the application window is closed.
 *  Make sure that you call cs3081::InitGraphics() before creating the
 *  RobotViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      RobotViewer *app = new RobotViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open \ref UpdateSimulation() will be called repeatedly,
 *  once per frame.  Fill this in to update your simulation or perform any other
 *  processing that should happen over time as the simulation progresses.
 *
 *  Fill in the On*() methods as desired to respond to user input events.
 *
 *  Fill in the Draw*() methods to draw graphics to the screen using
 *  either the nanovg library or raw OpenGL.
 */
using namespace mingfx;

class RobotViewer : public GraphicsApp {
 public:
  RobotViewer();
  ~RobotViewer();


  // Delete the copy constructor and assignment operator.
  RobotViewer(const RobotViewer &other) = delete;
  RobotViewer &operator=(const RobotViewer &other) = delete;

  void InitNanoGUI()  override;

  // Explicitely overriding the UpdateSimulation of GraphicsApp
  // This method is called at every frame refresh.
  // DrawUsingNanoVG is called immediately after UpdateSimulation.
  void UpdateSimulation(double dt) override;

  /**
   * @brief Draw the arena with all robots, obstacles using nanogui.
   *
   * @param[in] ctx Context for nanogui.
   */
  void DrawUsingNanoVG(NVGcontext *ctx) override;

  /**
   * @brief Draw using OpenGL. This callback had to be defined, but we are doing
   * all drawing with nanovg in this application, so it is empty.
   */
  void DrawUsingOpenGL(void) override {}

  /**
   * @brief Handle the user pressing the restart button on the GUI.
   */
  void OnRestartBtnPressed();

  /**
   * @brief Handle the user pressing the pause button on the GUI.
   */
  void OnPauseBtnPressed();

  void OnColorChangeBtnPressed0();

  void OnColorChangeBtnPressed1();

  /**
   * @brief Called each time the mouse moves on the screen within the GUI
   * window.
   *
   * Origin is at the lower left of the window. This function is a stub.
   *
   * @param[in] pos The position of the release.
   * @param[in] delta How far the mouse has moved.
   */
  void OnMouseMove(__unused const Point2& pos,
                   __unused const Vector2& delta) override {};

  /**
   * @brief Called each time the left mouse button is clicked.
   *
   * Origin is at the lower left of the window. This function is a stub.
   *
   * @param[in] pos The position of the release.
   */
  void OnLeftMouseDown(__unused const Point2& pos) override {};

  /**
   * @brief Called each time the left mouse button is released.
   *
   * Origin is at the lower left of the window. This function is a stub.
   *
   * @param[in] pos The position of the release.
   */
  void OnLeftMouseUp(__unused const Point2& pos) override {};

  /**
   * @brief Called each time the right mouse button is clicked.
   *
   * Origin is at the lower left of the window. This function is a stub.
   *
   * @param[in] pos The position of the release.
   */
  void OnRightMouseDown(__unused const Point2& pos) override {};

  /**
   * @brief Called each time the right mouse button is released.
   *
   * Origin is at the lower left of the window. This function is a stub.
   *
   * @param[in] pos The position of the release.
   */
  void OnRightMouseUp(__unused const Point2& pos) override {};

  /**
   * @brief Called each time a character key is pressed.
   *
   * This function is a stub.
   *
   * @param[in] c Character representing a key that was pressed.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnKeyDown(__unused const char *c, __unused int modifiers) override {};

  /**
   * @brief Called each time a character key is released.
   *
   * This function is a stub.
   *
   * @param[in] c Character representing a key that was released.
   * @param[in] modifiers Any modifier keys that were held with the key.
   */
  void OnKeyUp(__unused const char *c, __unused int modifiers) override {};

  /**
   * @brief Called each time a special (non-alphabetic) key is pressed.
   *
   * This function is a stub.
   *
   * @param[in] key The key that was pressed.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnSpecialKeyDown(__unused int key, __unused int scancode,
                        __unused int modifiers) override {};

  /**
   * @brief Called each time a special (non-alphabetic) key is released.
   *
   * This function is a stub.
   *
   * @param[in] key The key that was released.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnSpecialKeyUp(__unused int key, __unused int scancode,
                      __unused int modifiers) override {};



 private:
  /**
   * @brief Draw a robot using nanogui. Called from DrawUsingNanoVG.
   *
   * @param[in] ctx The nanogui context.
   * @param[in] id The ID of the robot.
   * @param[in] xpos The X position of the robot.
   * @param[in] ypos The Y position of the robot.
   * @param[in] xvel The X velocity of the robot.
   * @param[in] yvel The Y velocity of the robot.
   * @param[in] rad The radius of the robot.
   * @param[in] sensor_angle Angle between sensors relative to robot center.
   * @param[in] sensor_range Range distance in pixels of each sensor.
   */
  void DrawRobot(NVGcontext *ctx, Robot *robot);

  /**
   * @brief Draw the sensors from a robot using nanogui.
   *
   * @param[in] ctx The nanogui context.
   * @param[in] sensor_angle The angle of the robot's sensor.
   * @param[in] sensor_dist The range of the sensor.
   */
  void DrawRobotSensors(NVGcontext *ctx, double sensor_angle, double sensor_range);

  /**
   * @brief Draw an obostacle in the arena using nanogui.
   *
   * @param[in] ctx The nanogui context.
   * @param[in] xpos The X position of the obstacle.
   * @param[in] ypos The Y position of the obstacle.
   * @param[in] rad The radius of the obstacle.
   */
  void DrawObstacle(NVGcontext *ctx, double xpos, double ypos, double rad);

  RobotLand *robot_land_;
  bool paused_{false};
  nanogui::Button *pause_btn_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_ROBOT_VIEWER_H_ */
