/**
 * @file controller.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "src/arena.h"
#include "src/common.h"
#include "src/arena_viewer.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Controller that mediates Arena and GraphicsArenaViewer communication.
 *
 * The Controller instantiates the Arena and the GraphicsArenaViewer. The
 * viewer contains the main loop that keeps it live, but at each update, the
 * viewer sends a message to the controller to update its time.
 *
 * Other types of communication between Arena and Viewer include:
 * - keypresses intercepted by the Viewer.
 * - Play/Pause/New Game user input via the Viewer.
 * - Game status from arena to the viewer.
 **/
class Controller {
 public:
  /**
   * @brief Controller's constructor that will create Arena and Viewer.
   */
  Controller(int argc, char **argv);

  virtual ~Controller();

  virtual ArenaViewer* CreateViewer(int width, int height);

  /**
   * @brief Run launches the graphics and starts the game.
   */
  void Run();

  /**
   * @brief AdvanceTime is communication from the Viewer to advance the
   * simulation.
   */
  void AdvanceTime(double dt);

 /**
  * @brief Completely destroy and remake the arena
  */
  void Reset();


  Controller &operator=(const Controller &other) = delete;

  Controller(const Controller &other) = delete;

  // Add quotes around the string
  std::string add_quotes(std::string word) {
    std::string quoted_string("\"");
    quoted_string += (word + "\"");
    return quoted_string;
  }

  // To determine if quotes should be put around the parsed word
  inline bool in_number_set(std::string word) {
    // compare returns 0 when it matches the word
    return !(
      word.compare("x") && word.compare("y")
      && word.compare("r") && word.compare("theta") );
  }

  std::string convertCSV(std::string str) {
    std::string token;
    std::vector<std::string> keys;

    std::ifstream fin(str);
    std::string labels;
    fin >> labels;

    std::istringstream sss(labels);
    while (std::getline(sss, token, ',')) {
      keys.push_back(token);
    }

    std::string entities = "{ \"entities\": [\n";

    std::string entity_json;  // populate below by converting csv row to json
    std::string row;          // temp holder of csv row
    std::vector<std::string> words;   // all words parsed from csv row

    while (fin >> row) {
      std::istringstream ss(row);
      words.clear();
      while (std::getline(ss, token, ',')) {
        words.push_back(token);
      }
      int keys_index = 0;
      entity_json = "     {";
      for (auto word : words) {
        if (keys_index != 0) { entity_json += ","; }
        entity_json += add_quotes(keys[keys_index]) + ":";
        if (in_number_set(keys[keys_index])) {
          entity_json += word;
        } else {
          entity_json += add_quotes(word);
        }
        ++keys_index;
      }
      entity_json += "}";
      entities += entity_json + ",\n";
    }

    entities = entities.substr(0, entities.length() - 2);
    entities += "\n  ]\n}";
    return entities;
  }

 private:
  double last_dt{0};
  Arena* arena_{nullptr};
  ArenaViewer* viewer_{nullptr};
  std::vector<ArenaViewer*> viewers_;
  json_value* config_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_CONTROLLER_H_
