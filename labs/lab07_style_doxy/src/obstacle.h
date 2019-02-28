// @copyright 2019 3081 class, all rights reserved

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

/*
 * Includes
 */
#include <utility>

/*
 * Class Definitions
 */
/** 
 * @brief Obstacle class for the obstacle which is used somewhere with robots.
 *
 */
class Obstacle {
 public:
  Obstacle() : radius_(10), position_(20.0, 20.0) {}
  /**
   * @brief Gets the radius for an obstacle.
   * This will be used to get the radius.
   * @return The radius of the obstacle.
   */
  int get_radius() {return radius_;}

  /**
   * @brief Gets the position for an obstacle.
   * This will be used to get the position.
   * @return The position of the obstacle as a pair.
   */
  std::pair<double, double> get_pos() {return pos_;}

 private:
  int radius_;
  std::pair<double, double> pos_;
}

#endif  // SRC_OBSTACLE_H_

