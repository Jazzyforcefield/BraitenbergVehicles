// Copyright 2019, Michael Ung

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/**
 * \mainpage Braitenberg Vehicle Project Iteration 2
 * \section Intro Introduction
 *
 * This is a program that simulates the Braitenberg Vehicle. In short, there are four basic 
 * behaviors that are used: Coward, Love, Aggressive, and Explore that react toward stimuli 
 * such as light, food, or other Braitenberg Vehicles and control how the vehicle moves.
 * Present in the simlulation are also stimuli such as light or food that may also affect how the 
 * vehicle moves. (More information can be found at this link: 
 * https://en.wikipedia.org/wiki/Braitenberg_vehicle). It also uses minGfx and nanogui as
 * the method for visualization.
 *
 * \subsection Functionality Functionality
 *
 * The simulator employs multiple different design patterns and mainly uses the model-view-controller
 * design pattern (https://en.wikipedia.org/wiki/Software_design_pattern). The corresponding classes
 * are as follows: Arena : model, GraphicsArenaViewer : view, controller : controller. The arena
 * handles all entities, GraphicsArenaViewer handles the user interface and user input, and the controller
 * allows the two classes to communicate. The timing of the simulation runs in iterations which is controlled
 * by the Run() function in GraphicsApp. Each entity in the arena has its own TimestepUpdate() function that
 * allow the entity to change state every iteration. The factory pattern, strategy pattern, observer pattern,
 * and decorator pattern are also used.
 * 
 * \subsection Patterns Design Patterns
 *
 * The factory pattern is implemented using an abstract base class to derive each entity's factory.
 * The creation is handled in the arena as mentioned in the previous paragraph where the arena
 * handles all entities.
 *
 * The strategy pattern is employed when concerning vehicle movement. This allows the Update() function
 * in each BraitenbergVehicle or Predator to use polymorphism when updating the constituent WheelVelocity's.
 *
 * The observer pattern is used to create the velocity display interface. The chosen implementation
 * was for the subject to inherit from a subject class and an observer to inherit from the observer.
 * This provides loose coupling and allows for easy extension.
 *
 * The decorator pattern was difficult to implement and was employed to make Disguises for Predator's.
 * The disguising is controlled in the arena and chooses a random disguise.
 *
 * Although the adapter pattern is not used in this simulation, the controller contains a function
 * that acts similarly to an adapter and deserves mention.
 *
 * \subsection Run Downloading and Running
 *
 * In order to use the simulation, one must download and call 'make' in a terminal. The proper
 * framework and libraries must be present on the computer in order to run. The program will
 * setup minGfx and nanogui if they are not installed. As for the interface, you can select
 * which entity you wish to configure and choose the behavior that it has toward a certain
 * type of entity. Pressing the 'Play' button will start the simulation and the same button will
 * turn into the 'Pause' button to pause the simulation. You are able to use the 'Reset' button
 * to restore the simulation to its original loaded state.
 *
 * Configuration files of .json and .csv may also be used to create an arena. Calling in the command
 * line "./build/bin/arenaviewer <xdim> <ydim> <config>" will allow you to create an arena.
 * The .json files must be configured as similar to the following:
 * \code{.json}
 *  {
 *    "entities": [ 
 *      {"type": "Braitenberg", "x":120, "y":300, "r":15, "theta": 270.0, "light_behavior": "Aggressive", "food_behavior": "Aggressive" },
 *      {"type": "Braitenberg", "x":220, "y":300, "r":15, "theta": 270.0, "light_behavior": "Love", "food_behavior": "Aggressive" },
 *      {"type": "Braitenberg", "x":320, "y":300, "r":15, "theta": 270.0, "light_behavior": "Explore", "food_behavior": "Aggressive" },
 *      {"type": "Braitenberg", "x":420, "y":300, "r":15, "theta": 270.0, "light_behavior": "Coward", "food_behavior": "Aggressive" },
 *      {"type": "Food", "x":100, "y":100, "r":20, "theta": 0.0 },
 *      {"type": "Food", "x":300, "y":500, "r":20, "theta": 0.0 },
 *      {"type": "Food", "x":500, "y":100, "r":20, "theta": 0.0 },
 *      {"type": "Light", "x":100, "y":250, "r":30 },
 *      {"type": "Light", "x":500, "y":350, "r":30 } ]
 *  }
 *\endcode
 *
 * Whereas .csv files must be as such:
 * \code{.csv}
 *  type,x,y,r,theta,light_behavior,food_behavior,robot_behavior
 *  Braitenberg,220,400,15,270.0,Love,Aggressive,Coward
 *  Braitenberg,120,300,15,170.0,Aggressive,Aggressive,Explore
 *  Braitenberg,420,200,15,100.0,Explore,Aggressive,Coward
 *  Braitenberg,320,100,15,270.0,Love,Aggressive,Coward
 *  Predator,220,350,15,270
 *  Light,100,250,30
 *  Light,400,350,30
 *  Food,200,250,30,0.0
 *  Food,300,150,20,0.0
 *  Food,50,450,20,0.0
 * \endcode
 */

#endif  // SRC_MAINPAGE_H_
