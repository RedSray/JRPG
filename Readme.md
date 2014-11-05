JRPG
====
The name says everything, I'm trying to recreate one of those old school JRPG games. 

What is working 
-------------
Actually you can:
- select menu using Up and Down arrow keys and validate with Enter
- move around the map using Arrow keys
- use Escape to go back to the menu and
- use ALT + F4 when on the map to quit directly the game

Refacto Note
------------
I'm happy with the idea of using state to represent the different part of the game. The same with the usage of compound state. But, I'm not happy with the implementation. Also, the Game class is not what I intended in the first place.

So, before I continue to implement new features, I have to work on some refactoring. I have already thought about what I want to do and the changes should come soon. The main idea will be:

- SceneState: that represent a part of the game. They manage rendering and members needed in every logical state.
- LogicState: they will let me implement different behaviour for a SceneState like when exploring you can actually be moving around or talking. But they won't have to deal with rendering, only logic.
- Game: this class will be the interface to all the game's data (quest, dialog...), it will know which file contain which information and will be able to load what is actually needed (I needed to work more on this part to define exactly what are the data).

Todo List
---------
- Transfer GDD on the wiki
- Refactoring
- continue with new features
