# SpaceShip_ConsoleGame
 
### By: JOAN ORTIGA BALCELLS

Game developed in C++. Uses a custom engine built for doing other console games.
You can download "SpaceShip_ConsoleGame.zip" to see the final sourcecode and play with the .exe

### Compatibility: 
Due to changes in Windows 11 console, there's only compatibility with Windows 10 and Windows 7

### Features LamterEngine:
- Custom engine, with console buffer. Focused on getting rid of flickering and reducing drawcalls.
- Custom Input system, similar to popular engines. (GetKeyDown, GetKeyUp, GetKey).
- Custom time management, makes sure engine runs at X fps.
- Component driven system, similar to Unity.
- Collider component, and collision system.
- Utility functions like GetGameObjectOfTypeByTag that returns a pointer to the object with a tag.
- User only needs to write the main.cpp to make the engine run, without other tweekings.
- Using read/write of xml with tinyxml12 with layer of abstraction.
- (...)

### Game features:
- Free movement of ship. (8 axis)
- 2 enemy types.
- Different drawing speeds depending on the movement speed.
- Customizable enemy spawn system:
  - Rounds
  - Enemy groups and spawning times. (Allows creating patterns of enemies very fast.).
  - Enemies: enemy type, delay between spawns, position, quantity.
- Score saved between sessions.

