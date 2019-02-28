/**
 * @file robot_viewer.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_viewer.h"
#include <iostream>
#include <string>

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotViewer::RobotViewer()
    : GraphicsApp(1024, 768, "Robot Simulation"),
      robot_land_(new robot_land()),
      pause_btn_(nullptr) {
  // Create a menu with 2 buttons for pausing and restarting the simulation.
  nanogui::FormHelper *gui = new nanogui::FormHelper(screen());
  nanogui::ref<nanogui::Window> window =
      gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
  pause_btn_ =
      gui->addButton("Pause", std::bind(&RobotViewer::OnPauseBtnPressed, this));
  gui->addButton("Restart", std::bind(&RobotViewer::OnRestartBtnPressed, this));

  screen()->performLayout();

  paused_ = false;

  // Instantiate robot_land, which holds 2 robots and an obstacle.
  robot_land_ = new robot_land();
}

RobotViewer::~RobotViewer() { delete robot_land_; }

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void RobotViewer::UpdateSimulation(double dt) {
  // This is called at each pass through nanogui::mainloop.
  // It sends the time change dt to robot_land_ to advance the simulation.
  if (!paused_) {
    robot_land_->advanceTime(dt);
  }
}

// The handlers for the menu buttons ...
void RobotViewer::OnRestartBtnPressed() { robot_land_->set_time(0.0); }

void RobotViewer::OnPauseBtnPressed() {
  paused_ = !paused_;
  if (paused_) {
    pause_btn_->setCaption("Play");
  } else {
    pause_btn_->setCaption("Pause");
  }
}

// this function requires an active nanovg drawing context (ctx),
// so it should probably only be called from within DrawUsingNanoVG()
void RobotViewer::DrawRobot(NVGcontext *ctx, int id, double xpos, double ypos,
                            double xvel, double yvel, double rad) {
  // translate and rotate all graphics calls that follow so that they are
  // centered
  // at the position and heading for this robot

  // *********
  // IMPORTANT: the nvgSave(ctx) saves the current origin of the coordinate
  // system. When you translate and rotate, it modifies the origin. Any
  // subsequent reference to {x,y} is relative to that origin.
  // The nvgSave needs to be paired with nvgRestore, as that is what returns
  // the origin to its saved position. Notice these can be nested.
  // *********

  // Put the origin of the coordinate system at the center of the robot, and
  // orient the x-axis to align with the velocity (i.e. heading) of the robot.
  nvgSave(ctx);
  nvgTranslate(ctx, xpos, ypos);
  double angle = std::atan2(yvel, xvel);
  nvgRotate(ctx, angle);

  // robot's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, rad);
  nvgFillColor(ctx, nvgRGBA(200, 200, 200, 255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // robot id text label
  nvgSave(ctx);
  nvgRotate(ctx, M_PI / 2.0);
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  std::string text = "Robot " + std::to_string(id);
  nvgText(ctx, 0.0, 10.0, text.c_str(), NULL);
  nvgRestore(ctx);

  nvgRestore(ctx);
}

// this function requires an active nanovg drawing context (ctx),
// so it should probably only be called from with DrawUsingNanoVG()
void RobotViewer::DrawRobotSensors(NVGcontext *ctx, double xpos,
                                   double ypos, double xvel, double yvel,
                                   double sensor_angle,
                                   double sensor_dist) {
  // translate and rotate all graphics calls that follow so that they are
  // centered at the position and heading for this robot
  nvgSave(ctx);
  nvgTranslate(ctx, xpos, ypos);
  double angle = std::atan2(yvel, xvel);
  nvgRotate(ctx, angle);

  // sensor cone outline
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * sensor_angle);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 100));
  nvgStroke(ctx);
  nvgRestore(ctx);

  // blue for right sensor cone
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * sensor_angle);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -0.5 * sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgFillColor(ctx, nvgRGBA(100, 100, 255, 150));
  nvgFill(ctx);
  nvgRestore(ctx);

  // yellow for left sensor cone
  nvgSave(ctx);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -0.5 * sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgFillColor(ctx, nvgRGBA(255, 255, 100, 150));
  nvgFill(ctx);
  nvgRestore(ctx);

  nvgRestore(ctx);
}

// This function requires an active nanovg drawing context (ctx),
// so it should probably only be called from with DrawUsingNanoVG()
void RobotViewer::DrawObstacle(NVGcontext *ctx, int id, double xpos,
                               double ypos, double rad) {
  nvgBeginPath(ctx);
  nvgCircle(ctx, xpos, ypos, rad);
  nvgFillColor(ctx, nvgRGBA(255, 100, 100, 255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  std::string text = "Obstacle " + std::to_string(id);
  nvgText(ctx, xpos, ypos, text.c_str(), NULL);
}

void RobotViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // initialize text rendering settings
  nvgFontSize(ctx, 18.0f);
  nvgFontFace(ctx, "sans-bold");
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

  // Draw each obstacle in robot land
  for (int i = 0; i < robot_land_->get_num_obstacles(); i++) {
    double x, y;
    robot_land_->get_obstacle_pos(i, &x, &y);

    DrawObstacle(ctx, i, x, y, robot_land_->get_obstacle_radius());
  }

  // Draw each robot in robot land
  for (int i = 0; i < robot_land_->get_num_robots(); i++) {
    double xpos, ypos;
    robot_land_->get_robot_pos(i, &xpos, &ypos);

    double xvel, yvel;
    robot_land_->get_robot_vel(i, &xvel, &yvel);

    DrawRobot(ctx, i, xpos, ypos, xvel, yvel, robot_land_->get_robot_radius());
  }

  // Draw the field-of-view for the robot sensors
  // Sensor beams must be drawn last because they are semi transparent
  for (int i = 0; i < robot_land_->get_num_robots(); i++) {
    double xpos, ypos;
    robot_land_->get_robot_pos(i, &xpos, &ypos);

    double xvel, yvel;
    robot_land_->get_robot_vel(i, &xvel, &yvel);

    DrawRobotSensors(ctx, xpos, ypos, xvel, yvel,
                     robot_land_->get_robot_sensor_angle(),
                     robot_land_->get_robot_sensor_distance());
  }
}
