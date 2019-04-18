#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

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

/*
This code demonstrates how to convert a csv file for configuring entities into a json formatted string that matches the scenes files formatting in the project.

Each row of the csv file corresponds to an entity. It is parsed and converted to a json formatted string that represents an array element.

After compilation: $ g++ main.cc, you can test by calling
$ ./a.out 20 20 test.csv
Output is sent both to the stdout and to the file output.json
*/

int main(int argc, char **argv) {
  // Expecting argv[4] arguments:
  // [1] and [2]: x,y dimensions of graphics window
  // [3]: config filename
  if(argc != 4){
    std::cout<<"Incorrect Command Line Arguments"<<std::endl;
    return 1;
  }
  try{
    // a word parsed from csv row
    std::string token;

    // all column labels of csv -- correspond to json keys (e.g. "type")
    std::vector<std::string> keys;

    // read the file that was passed in as argument
    std::ifstream fin(argv[3]);

    // pull first row of column headings
    std::string labels;
    fin >> labels;

    // Save these as the keys that are put into the json string.
    // These include "type" "x" "robot_behavior" etc.
    std::istringstream ss(labels);
    while(std::getline(ss, token, ',')) {
      keys.push_back(token);
    }

    // Start the json configuration string with { "entities": ["
    std::string entities = "{ \"entities\": [\n";

    // read and parse csv file line-by-line
    // convert each line to json entity row and add to entities ...
    /*  for example, using keys from first row, convert
    Braitenberg,220,400,15,270.0,Love,Aggressive,Coward
        to
    {"type": "Braitenberg", "x":220, "y":400, "r":15, "theta": 270.0, "light_behavior": "Love", "food_behavior": "Aggressive", "robot_behavior": "Coward" }
    */

    std::string entity_json;  // populate below by converting csv row to json
    std::string row;          // temp holder of csv row
    std::vector<std::string> words;   // all words parsed from csv row

    // while more rows to parse and convert ...
    while(fin>>row) {
      // parse into separate words (separated by commas)
      std::istringstream ss(row);
      words.clear();
      while(std::getline(ss, token, ',')) {
        words.push_back(token);
      }
      // combine each key with associated word into json row
      // for example: "type" : "Braitenberg" or "x":220
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

    // Erase last comma added to entities
    entities = entities.substr(0, entities.length()-2);

    // Close out the entities array and json string
    entities += "\n  ]\n}";

    // Let's see what we made ...
    std::cout << entities << std::endl;

    // Here it is in a file if you want to save it ...
    std::ofstream out("output.json");
    out << entities;
    out.close();
    return 1;
  }
  catch(const std::exception& e){
    std::cout<<"Incorrect Format of CSV file"<<std::endl;
  }
  return 1;
}
