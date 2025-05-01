# strategy-battle-game
 C++ Turn-Based Battle Game

This is a C++ console-based battle game I developed as part of my programming portfolio.The game features a turn-based combat system where the player fights against a boss opponent with scalable difficulty and randomized behavior.

## Gameplay Summary
- **Player vs. Boss turn-based combat**
- Choose from 3 difficulty levels: Easy, Medium, Hard
- Player and boss take turns with a mix of:
  - Attacking (A)
  - Defending (D)
  - Reserving (extra turns) (R)
- Each round progresses with dynamic turn scaling (Max 4)
- Reserves allow the user to reach a maximumm of 8 turns
- Randomized boss behavior makes each game different
- The users aim is for the boss to reach 0hp

## 🛠 Features

- Dynamic difficulty scaling (boss stats change by level)
- Turn economy using "reserves" for strategic advantage
- Randomized AI for boss actions
- Replay loop with retry and exit options
- Well-commented and structured code

## How to Run

1. Make sure you have a C++ compiler installed (e.g., g++, Visual Studio, Code::Blocks).
2. Compile the code:
   ```bash
   g++ battle_game.cpp -o battle_game
   ```
3. Run the executable:
   ```bash
   ./battle_game
   ```

## Notes
-I developed this as my first project in C++ to demonstrate what I have learnt so far and to experiment with the features available in the language — including loops, conditionals, input handling, and basic AI.  
- The game is **fully playable**, though not yet extended into a graphical or object-oriented format. Future improvements could include refactoring into classes, GUI support, or multiplayer logic.

## Status

This project is **functionally complete** and ready to demo, but I consider it a work in progress — I’m continuing to improve the structure and possibly expand on the gameplay in the future.
