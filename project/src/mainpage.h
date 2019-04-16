// Copyright 2019, Michael Ung

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/**
 * \mainpage Braitenberg Vehicle Project Iteration 2
 *
 * This is a program that simulates the Braitenberg Vehicle. In short, there are four basic 
 * behaviors that are used: Coward, Love, Aggressive, and Explore. These basic behaviors 
 * control how the vehicle moves. Present in the simlulation are also stimuli such as light or 
 * food that may also affect how the vehicle moves. (More information can be found at this 
 * link: https://en.wikipedia.org/wiki/Braitenberg_vehicle). It also uses minGfx and nanogui as
 * the method for visualization.
 *
 * As a student, we were given a base project to work with that included the basic setup as
 * described in the paragraph above. The project is broken up into iterations where we implement
 * different design patterns to learn good design practice. The first iteration required
 * implementation of the Factory pattern and the Strategy pattern, the second iteration required
 * implementation of the Observer pattern, and the third iteration includes the decorator
 * pattern. All iterations include feature enhancements.
 * 
 * For the design patterns mentioned above, the factory pattern serves as the creation method
 * for all (almost atm) entities in the arena. Factories take in json objects as well as an 
 * ArenaEntity pointer to a pointer in order to instantiate the object. For the strategy pattern
 * we enforce loose coupling by having the wheel velocities calculated a separate class. The
 * observer pattern is used to allow for viewing the vehicle speed at the current moment. There
 * are future patterns to be implemented, but at the moment this is the extent.
 *
 * In order to use the simulation, one must download and call 'make' in a terminal. The proper
 * framework and libraries must be present on the computer in order to run. The program will
 * setup minGfx and nanogui if they are not installed. As for the interface, you can select
 * which entity you wish to configure and choose the behavior that it has toward a certain
 * type of entity. Pressing the 'Play' button will start the simulation and the same button will
 * turn into the 'Pause' button to pause the simulation. You are able to use the 'Reset' button
 * to restore the simulation to its original loaded state.
 */

#endif  // SRC_MAINPAGE_H_
