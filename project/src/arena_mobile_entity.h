/**
 * @file arena_mobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <iostream>

#include "src/arena_entity.h"
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
// >>> MISSING HERE
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A mobile entity in the Arena, capable of updating its own position
 * and/or velocity when asked by the simulation.
 *
 * All mobile entities must have a heading angle so that their orientation can
 * be properly drawn by the GraphicsArenaViewer.
 *
 * Since this is also a food class, many of its methods are intuitively
 * `virtual`.
 */
class ArenaMobileEntity : public ArenaEntity {
 public:
  /**
   * @brief ArenaMobileEntity's constructor.
   */

  ArenaMobileEntity()
    : ArenaEntity(),
      speed_(0) {
        set_mobility(true);
  }
  ArenaMobileEntity(const ArenaMobileEntity& other) = delete;
  ArenaMobileEntity& operator=(const ArenaMobileEntity& other) = delete;

  virtual void HandleCollision(__unused EntityType ent_type,
                               __unused ArenaEntity * object = NULL) override { }

  virtual double get_speed() { return speed_; }
  virtual void set_speed(double sp) { speed_ = sp; }
  bool get_dlight() { return dlight_; }
  void set_dlight(bool b) { dlight_ = b; }

  bool get_dfood() { return dfood_; }
  void set_dfood(bool b) { dfood_ = b; }

  bool get_dbv() { return dbv_; }
  void set_dbv(bool b) { dbv_ = b; }


  int get_stime() const { return stime_; }
  void set_stime(int v) { stime_ = v; }

EntityType Disguise() {
  std::cout << "Disguising as ";
  bool changed = false;
  while ((dlight_ != true || dfood_ != true || dbv_ != true) && !changed) {
    int random = (std::rand() % 3) + 1;
    if (random == 3 && dlight_ == false) {
      dlight_ = true;
      changed = true;
      std::cout << "kLight" << std::endl;
      return kLight;
    } else if (random == 2 && dfood_ == false) {
      dfood_ = true;
      changed = true;
      std::cout << "kFood" << std::endl;
      return kFood;
    } else if (random == 1 && dbv_ == false) {
      dbv_ = true;
      changed = true;
      std::cout << "kBraitenberg" << std::endl;
      return kBraitenberg;
    }
  }
  return kUndefined;
}


  bool is_moving() { return is_moving_; }
  void set_is_moving(bool moving) { is_moving_ = moving; }

 private:
  double speed_{0};
  int stime_{0};
  bool is_moving_{true};
  bool dlight_{false};
  bool dfood_{false};
  bool dbv_{false};
 protected:
  bool collided_{false};
  int time_{0};
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_MOBILE_ENTITY_H_
