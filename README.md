
![PowerGrid](http://i.imgur.com/I8SAxWT.png)

PowerGrid is a bot platform that aims to provide a comprehensive suite of classes and tools to make scripting much easier and less frustrating than with the existing clients. 

## PowerGrid functionality ##
PowerGrid offers a completely new travelling system that allows the user to walk to any location in the Runescape world, while also using available teleports and shortcurs to get to the destination in the fastest possible way.

It also provides a mechanism to check a variety of stats and settings without needing to nagivate through widgets, PowerGrid automatically checks these when required, but caches the results so that consecutive calls are much faster.

PowerGrid offers a full user interface to travel to any destination or location using either landmarks, special locations such as banks and stores, or even an actual world map, allowing the user to click any tile on the map, after which PowerGrid computes a route and executes it for maximum control.

Scripters can use PowerGrid's functions to make scripts easier, but that's not all: PowerGrid comes with a unique plugin system, that allows scripters to create so-called Tasks that integrate seamlessly with the existing PowerGrid tasks to form larger, more complex tasks, making scripting much easier. Imagine the possibility of executing a task that gets you to the right location using only one line of code! These kind of possibilities make PowerGrid worthwhile, whether you're a scripter or an end-user.

PowerGrid is, unlike other bots, written in C++. While this causes a delay in transferring data from the Java environment to C++, the C++ functions themselves can be made much faster, and since most code will run outside the Java Virtual Machine, there is less chance of the Runescape client detecting the bot. 

The loader itself is inspired by the official open-source loader for Runescape, also written in C++. Because of this, PowerGrid will appear to be a normal loader application, while in reality, PowerGrid monitors various settings, objects, and data structures to use for botting purposes.
