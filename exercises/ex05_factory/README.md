## Factory and Strategy for Robots

This is an exercise to help you think about how to incorporate the Factory Pattern and Strategy Pattern into the Braitenberg Vehicle project.

Included in these files are a Robot class and LeggedRobot, which is derived from Robot.

<hr>

### Robot Factories

In main, you see the creation of a base class array that is filled with different robots, and then the position is updated based on a time step.

1. Create FactoryPointer class that is responsible for creating various robots. Write just 1 class using the UML diagram on the board. Add some output within the FactoryPointer class methods to indicate which one you are in (e.g. "in create legged").

2. Use the factory to fill the array with robots and run it.

3. Define a Robot (e.g. `Robot * robot`) and LeggedRobot pointer in main and use the factory to instantiate those objects. Notice the difference in which methods are called!

You might need something like this:
```
BraitenbergVehicle* bv = static_cast<BraitenbergVehicle*>(ent);
```

4. Create FactoryReturn class using the UML diagram on the board.

5. Repeat process above and use the Factory to instantiate the robots.

There is a design choice here with respect to the Factory. You can choose either, but you should have a reason for choosing one over the other. Honestly, either is fine.

6. Now derive a LeggedRobot factory from Factory and use that for LeggedRobot creation.

When you design your factory for Arena Entities, those objects will also get placed in a base class array. Also, keep in mind that you will need to pass along the json configuration to the factory. Do you like one of these designs of the factory better than the other given that information? Honestly, either is fine, but you should be prepared to justify your choice.

<hr>

### Movement Strategies/Behaviors

Braitenberg vehicles move according to the defined relationship (e.g. Love, Explore, Cowar, Aggression) between the sensors and the wheels.

1. Redesign your robot so that it has different movement (i.e. UpdatePosition accounts for different behaviors) depending on its behavior and the sensor readings. You can hard code this to begin with.

2. Now think about how you can use the strategy pattern to implement this. What does the UML diagram look like for this?

In the Braitenberg vehicles, both the behavior towards light and food contribute to the wheel velocity.

```
wheel_velocity_ = WheelVelocity(
  (light_wheel_velocity.left + food_wheel_velocity.left)/numBehaviors,
  (light_wheel_velocity.right + food_wheel_velocity.right)/numBehaviors,
  defaultSpeed_);
```

3. Add another sensor pair to the robots and incorporate those into your strategy pattern. Add to your UML if necessary.

4. Try to implement your UML diagram.
