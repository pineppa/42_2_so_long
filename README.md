# So long... and thanks for all the fish

## Table of Content

- [The rules of the game](#the-rules-of-the-game);
- [Graphics management](#graphics-management);
- [Map](#map);
- The code organization:
  - [Programme input](#programme-input);
  - [Init Resources](#init-resources);
  - [Key Hooks](#key-hooks);
  - [Movements](#movements);

## The MinLibX library

This is a graphical engine developed by the school. The project has been developed as homework in Linux. Modified for MacOS for school submission.

## The rules of the game

- Implement movement functions that are associated to `W A S D` keys to catch the 4 different movement directions;
- The player cannot move through walls;
- The number of movement must be displayed in the shell;
- Must use a 2D view (top-down or profile);
- Game does not need to be real time (Can be a turned based one).

## Graphics management

- The image must be displayed in a window;
- The management of the window shall be smooth (change to another window, minimize, ...);
- `ESC` and the window X should close the window and the program in a clean way;
- The use of the `images` of the MiniLibX is mandatory.

## Map

- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 (6) characters:

  - `0` for an ground space,
  - `1` for a wall,
  - `C` for a collectible,
  - `E` for a map exit,
  - `P` for the player's starting position.
  - `D` for the enemies (_bonus_)

- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid. If the map contains a duplicates characters (exit/start), the program should display an error message.

Here is a simple valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

- The map must be rectangular.
- The map must be closed/surrounded by walls. If it is not, the program must return an error.
- There must be a valid path in the map.
- The user should be able to parse any kind of map, as long as it respects the above rules.
- Another example of a minimal `.ber` map:

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

- If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return `"Error\n"` followed by an explicit error message of your choice

<p style="text-align:right;">
  <a href="#so-long-and-thanks-for-all-the-fish">
	Go to the top
  </a>
</p>

# The code organization

## Programme input

The program must be passed the map to be used for the game. The code sequentially:

- Checks the presence of the additional argument;
- Checks that the file is properly formatted as `.ber`;

`map->map_size` tells how big the matrix of map is. This should be used to manage the content in the window;

## Check the map

- Checks the map to:
  - Be of rectangular shape
  - The whole perimeter is closed with a wall;
  - Go through map and load every location with the specific image required:
  - There is a valid path:
    - Use a flooding algorithm, with a block on Exit to ensure the collectibles are not hidden;
  - Each component has only 1 Player and Exit;

<p style="text-align:right;">
  <a href="#so-long-and-thanks-for-all-the-fish">
	Go to the top
  </a>
</p>

## Init resources

- Initiate the graphic connection to the display and retrieve the screen size;
- Checks that the map fits in the screen (Map movement is a possible future update)
- Create a new window:
  - Initialize objects information and throws an error if the specified file is missing
- Draw the map:
  - `0` Loads the Ground space;
  - `1` Loads the Wall image;
  - `E C P` loads an ground space as background plus the specific image that represents the Exit, a Collectible, or the Player;

<p style="text-align:right;">
  <a href="#so-long-and-thanks-for-all-the-fish">
	Go to the top
  </a>
</p>

## Key Hooks

|      Key      | Event |         EasierKey         |         Alias function          |                     Prototype                     |
| :-----------: | :---: | :-----------------------: | :-----------------------------: | :-----------------------------------------------: |
|   KeyPress    |   2   |       KeyboardPress       |                                 |       int (\*f)(int keycode, void \*param)        |
|  KeyRelease   |   3   |      KeyboardRelase       |         mlx_key_hook()          |       int (\*f)(int keycode, void \*param)        |
|  ButtonPress  |   4   |        Mouse Click        |                                 |                         /                         |
| ButtonRelease |   5   |       Mouse Release       |        mlx_mouse_hook()         | int (\*f)(int button, int x, int y, void \*param) |
| MotionNotify  |   6   |      Mouse Movement       |                                 |       int (\*f)(int x, int y, void \*param)       |
|    Expose     |  12   | Redrawing (to be checked) |        mlx_expose_hook()        |                         /                         |
| DestroyNotify |  17   |       Close Window        |                /                |       int (\*f)(int x, int y, void \*param)       |
|   LASTEvent   |  36   |             /             | _must be bigger than any event_ |

### Movements

The settings allow to use two different sets for movement:

| Up | Down | Left | Right |
|:--:|:----:|:----:|:-----:|
| W  |  S   |   A  |   D   |
| UP | DOWN | LEFT | RIGHT |

`ESC` is assigned to close the game window directly

<p style="text-align:right;">
  <a href="#so-long-and-thanks-for-all-the-fish">
	Go to the top
  </a>
</p>
