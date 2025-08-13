
# ft_undertale

A small 2D game inspired by **Undertale**, created for the 42 school's `so_long` project. Navigate a pixel-art maze, collect items, and reach the exit, all in retro Undertale style

---
<img width="373" height="369" alt="Screenshot from 2025-07-21 15-34-31" src="https://github.com/user-attachments/assets/33b19bbd-780b-426a-94f4-3359938b7c47" />

## Description

You control a character trapped in a maze. The objective is to collect all items and find the exit, while enjoying classic pixel-art graphics and Undertale-inspired design.

## Project Structure

- `Makefile` — project build
- `main.c` — initializes the game, sets up graphics, and starts the main loop
- `map_validation.c` — validates map files and checks for errors
- `player_movement.c` — handles player movement and interactions
- `texture_load.c` — loads textures and images for game elements
- `window_create.c` — draws the game map and manages window rendering
- `collected.c` — logic for collecting items
- `exit.c` — handles exit logic and conditions
- `find_last.c` — utility for finding last elements in arrays
- `find_player.c` — locates the player on the map
- `flood_fill.c` — checks map accessibility using flood fill
- `map_shape.c` — checks map shape and dimensions
- `pec_check.c` — checks for required map elements
- `player_hook.c` — handles player input hooks
- `title_check.c` — validates map titles
- `wall_check.c` — checks wall placement and integrity

## Build and Run

```sh
make
./so_long <map_file>
```

Example:
```sh
./so_long maps/classic.ber
```

## Arguments
- `<map_file>` — path to the map file in `.ber` format

## Features
- Pixel-art maps inspired by Undertale
- Uses MLX42 for graphics and input
- Map validation and error handling

## Technologies
- **Language:** C
- **Graphics:** MLX42 (lightweight graphics library)
- **Platform:** Unix-based (macOS or Linux)
