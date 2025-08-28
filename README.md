# Rock Paper Scissors Game in C++

A console-based implementation of the classic Rock Paper Scissors game with multiple rounds and comprehensive score tracking.

## 🎮 Features

- **Multiple Rounds**: Play 1 to 10 rounds per game
- **Score Tracking**: Keep track of wins, losses, and draws
- **Visual Feedback**: Clear display of choices and results
- **Replay Option**: Play multiple games without restarting
- **Sound Effects**: Audio feedback for computer wins
- **Input Validation**: Ensures valid user inputs

## 📋 How to Play

1. **Start the game** by running the executable
2. **Enter the number of rounds** you want to play (1-10)
3. **Make your choice** each round:
   - `1` for Scissors ✂️
   - `2` for Stone (Rock) 🪨
   - `3` for Paper 📄
4. **View the results** after each round
5. **See the final score** at the end of all rounds
6. **Choose to play again** or exit

## 🎯 Game Rules

- **Scissors** beats Paper ✂️ > 📄
- **Paper** beats Stone (Rock) 📄 > 🪨
- **Stone** (Rock) beats Scissors 🪨 > ✂️
- **Same choices** result in a draw

## 🚀 Installation & Compilation

### Compile with g++:

```bash
g++ rock-paper-scissors.cpp -o rps
```

Run the game:

```bash
./rps
```

One-line compilation and execution:

```bash
g++ rock-paper-scissors.cpp -o rps && ./rps
```

## 🎪 Example Game Session

```text
Please, enter the number of rounds from 1 to 10: 3

----------------------------------| Round [1] |----------------------------------
Please, enter your number of choice (3 for Paper, 2 for Stone, 1 for Scissor): 2

------| The result |------
Player Choice: Stone.
Computer Choice: Scissor.
Round Winner: User.

----------------------------------| Round [2] |----------------------------------
Please, enter your number of choice (3 for Paper, 2 for Stone, 1 for Scissor): 3

------| The result |------
Player Choice: Paper.
Computer Choice: Stone.
Round Winner: User.

----------------------------------| Round [3] |----------------------------------
Please, enter your number of choice (3 for Paper, 2 for Stone, 1 for Scissor): 1

------| The result |------
Player Choice: Scissor.
Computer Choice: Scissor.
Round Winner: No Winner (Draw).

		--------------------------------------------------------------------
			+++ G a m e  O v e r +++
		--------------------------------------------------------------------
		___________________________[Game Results]___________________________
		Game Rounds: 3.
		The user won 2 times.
		The computer won 0 times.
		They draw 1 time.
		Final Winner: User.
		____________________________________________________________________
		Please, do you want to play again (y/n)? n
```

## 🏗️ Code Structure

The program uses several programming concepts:

- Enumerations for game choices and winners
- Structures to organize game data
- Input validation for user choices
- Random number generation for computer AI
- Modular functions for clean code organization

Key Components:

- En_Choice: Defines game options (Scissor, Stone, Paper)
- En_Winner: Tracks round outcomes (User, Computer, Draw)
- St_Round_Info: Stores individual round data
- St_Game_Info: Tracks overall game statistics

## 📊 Scoring System

- User Win: +1 point to user score
- Computer Win: +1 point to computer score
- Draw: +1 to draw counter
- Final Winner: Determined by comparing total wins

## ⚙️ Requirements

- C++ Compiler: g++, clang++, or MSVC
- C++ Standard: C++11 or higher
- Terminal: Supports ANSI escape codes for formatting
- Audio: System sound support for bell notifications

## 📁 Project Structure

```text
rock-paper-scissors/
│
├── rock-paper-scissors.cpp    # Main source code file
├── README.md                  # Documentation (this file)
└── (optional) Makefile        # Build automation (if added)
```

## 🐛 Known Issues & Notes

- Sound effects may vary across different operating systems
- Screen clearing uses system-specific commands
- Game is designed for terminal/console use only

## 🤝 Contributing

Feel free to contribute by:

- Forking the repository
- Creating a feature branch
- Making your improvements
- Submitting a pull request

## 📄 License

This project is open source and available under the [MIT](LICENSE) License.

## ❓ Support

For questions or issues, please check the code comments or open an issue in the project repository.
