# 🪨📄✂️ Rock Paper Scissors Game

This is a simple **Rock-Paper-Scissors** game written in C++.  
It uses `struct`, `enum`, random number generation, and clean logic to simulate rounds between the player and the computer.

---

## 🎮 How to Play

- The game runs for 3 rounds by default.
- In each round, you choose between:
  - 1️⃣ Stone
  - 2️⃣ Paper
  - 3️⃣ Scissors
- The computer makes a random choice.
- The winner of each round is decided based on classic rules:
  - Stone beats Scissors
  - Scissors beats Paper
  - Paper beats Stone
- At the end, the overall winner is shown.

---

## 🧠 Features

- Use of **Enums** for clean choice/winner representation.
- Use of **Structs** to store:
  - Round information
  - Final results
- Generates **random choices** for the computer using `srand()` and `rand()`.
- Clean output showing round-by-round results and final game result.
- Replay support — play as many times as you like!

---

## 🔧 How to Run

1. Make sure you have a C++ compiler installed (e.g., g++, clang).
2. Compile the file:
   ```bash
   g++ main.cpp -o game
