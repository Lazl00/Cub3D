 <div align="center">

# 🎮 Cub3D — A Wolfenstein-like 3D Game

*A 3D raycasting game written in C, as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.cppreference.com/w/c)
[![School](https://img.shields.io/badge/School-42_Paris-black.svg)](https://42.fr)
[![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-orange.svg)](https://harm-smits.github.io/42docs/libs/minilibx)
[![Status](https://img.shields.io/badge/Status-Finished-brightgreen.svg)]()

**Author — [lcournoy](https://github.com/Lazl00)**

</div>

---

## 📖 About

**Cub3D** is a graphics project from the 42 curriculum inspired by classic first-person games such as *Wolfenstein 3D*.

The goal is to create a first-person 3D perspective from a two-dimensional map using **raycasting**. The player navigates through a maze-like environment, with walls rendered at different heights depending on their distance from the camera.

The project introduces fundamental concepts in graphics programming:

- **📐 Raycasting** — casting rays from the player's position to calculate wall distances.
- **🧱 Wall Rendering** — projecting 3D-looking walls onto a 2D screen.
- **🗺️ Map Parsing** — reading and validating map files.
- **🎨 Textures** — applying wall textures according to wall orientation.
- **⌨️ Event Handling** — processing player movement and camera rotation.
- **🧮 Mathematics** — working with vectors, angles, distances and projections.

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (`cc` / `gcc` / `clang`)
- `make`
- MiniLibX
- A compatible graphical environment

### Build & Run

```bash
# Clone the repository
git clone https://github.com/Lazl00/Cub3D.git
cd Cub3D

# Compile the project
make

# Launch the game
./cub3D maps/map.cub
```

Replace `maps/map.cub` with the path to a valid map file.

---

## 🎮 Controls

| Key | Action |
|:---:|---|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate the camera |
| `ESC` | Exit the game |

---

## 🗺️ Map Format

Cub3D uses `.cub` configuration files to define the environment.

A map file contains texture paths, floor and ceiling colors, and a grid representing the level.

Example:

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
101001
1000N1
111111
```

### Map Symbols

| Symbol | Description |
|:---:|---|
| `1` | Wall |
| `0` | Empty space |
| `N` | Player facing north |
| `S` | Player facing south |
| `E` | Player facing east |
| `W` | Player facing west |

The map defines the level layout and the player's initial position.

---

## 🧠 How Raycasting Works

Cub3D uses a raycasting algorithm to simulate a three-dimensional environment without a full 3D engine.

For each vertical column of pixels on the screen:

1. A ray is cast from the player's position in the direction of the camera.
2. The ray travels through the map until it hits a wall.
3. The distance to the wall is calculated.
4. The wall's projected height is computed.
5. The corresponding wall texture is rendered on screen.

Repeating this process across the screen creates the illusion of a 3D environment.

---

## 🛠️ Makefile Commands

| Command | Description |
|---|---|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the executable |
| `make re` | Recompile the project from scratch |

---

## 🏗️ Project Structure

```text
Cub3D/
├── includes/
│   └── cub3d.h
├── libft/
├── maps/
├── textures/
├── src/
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   ├── controls/
│   └── main.c
├── Makefile
└── README.md
```

*The structure above is illustrative; adapt it to match the actual repository.*

---

## 📚 Resources

- [42 Cub3D Project](https://42.fr/)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [42 Intra](https://intra.42.fr/)

---

## 🎓 42 Curriculum

*This project has been created by **lcournoy** as part of the 42 curriculum.*

