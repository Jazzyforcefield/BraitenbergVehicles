### Decorator Design Pattern

This example is taken directly from _Head First Design Patterns_. It demonstrates how to add functionality (decorate) an object dynamically.

The simple approach to this problem is to have flags inside the class that indicate whether or not that functionality is currently active. For example, we can create a beverage base class and derive coffee and latte from it. The coffee can vary its "functionality" with the addition of cream, sugar, etc. Therefore coffee could have the flags `has_sugar_` and `has_cream_` and `has_milk_`, and a latte could have `double_shot_` and `whip_` and `mocha_`. Any additional information or methods that need to be associated with the setting of these flags must also be in the class. For example, we need to add the cost of the extras to the base latte cost.

With the above described approach, you can think of the various functionality (add-ons) as contained within the beverage. This concept is turned inside-out with the decorator pattern. Each decorator both derives from and contains a beverage. The beverage can be decorated dynamically in whatever way the customer wants. New decorations can be added and applied to any beverage without changing the beverage! Pretty slick!
