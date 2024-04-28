# so_long
So_long is a 2D top-down game made with C and graphics library called minilibx.

<img width="939" alt="Screen Shot 2023-10-23 at 1 39 56 PM" src="https://github.com/rosamakinen/so_long/assets/112611789/b73b4246-cd3f-4095-81a5-90766ca972c5">

In so_long you play as the treasure chest trying to find all the golden coins that it has lost. The goal of the game is to collect all the golden coins and get to the key with the least amount of moves.

## :computer: About

This project focuses on creating a 2D game called "so_long". The objective of this project is to gain a better understanding of fundamental concepts such as graphics rendering with sprites, 2D game mechanics, and file parsing.


## :space_invader: Features
- [x] :earth_americas: Map parsing and error handling
- [x] :video_game: Basic 2D game mechanics
- [x] 🌊: Flood Fill algorithm
- [x] :memo: Graphcs rendering using Minilibx
- [x] :moneybag: Player movement using key bindings, collectibles, and exit, that activates after coins are collected
- [x] :checkered_flag: Counter to track the player moves


## 🆘: Maps and error checking

<img width="300" alt="Screenshot 2024-04-28 at 20 50 54" src="https://github.com/rosamakinen/so_long/assets/112611789/9dd143a8-32a9-403d-b67d-e74bee36d466"> <br>
For example, the map for the rendered game above looks like this. 

- 0 = ground

- 1 = wall

- C = collectible

- P = player starting position

- E = exit

Map checking tests that all collectibles and the exit are reachable with a flood-fill -algorithm. Other checks are for example that there is only one player and one exit, the game area is surrounded by walls, and no extra characters on the map.

## :rocket: Getting Started

To get started with the "so_long" project, follow these steps:

1. **Clone the repository:**

   ```bash
   https://github.com/rosamakinen/so_long.git
   ```

2. **Cd into the folder**
   ```bash
   cd so_long
   ```

3. **Compile**
   ```bash
   make
   ```

4. **Run the program**
   ```bash
    ./so_long maps/test_map.ber
   ```
   you can find more maps to play from the maps folder

<img width="567" alt="Screen Shot 2023-10-23 at 1 43 46 PM" src="https://github.com/rosamakinen/so_long/assets/112611789/94d1ee59-56d7-416a-b178-f65438949f30">

The game has a built in counter to track your moves
