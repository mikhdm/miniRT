# miniRT

<p align="center">
  <img width="400" height="300" src="./miniRT/screenshot.bmp">
</p>

### Description

A ray tracing implementation that renders various shapes (plane, triangle, square, cylinder, and sphere) on the screen with lighting effects. This project was developed while studying at [42](https://42.fr) (Moscow).

### Task

The goal is to implement a simple ray tracer that can render different shapes, support ambient and global lighting, translation, rotation, shadows, and multiple cameras with the ability to switch between them. The scene can be customized using a configuration file.

### Configuration Structure

Below is an example of a scene configuration file, with descriptions for every possible option:

```
# Window resolution: R <width> <height>
R   800        600

# Ambient lighting: A <lighting ratio in [0.0,1.0]> <color: RGB in [0,255] for each channel>
A   0.5        255,0,0

# Camera(s): c <position coordinates: X,Y,Z> <orientation vector: X,Y,Z in [-1,1]> <horizontal FOV (field of view) in [0,180]>
c   0,0,-20     0,0,1     53.3

# Light(s): l <position coordinates: X,Y,Z> <brightness ratio in [0.0,1.0]> <color: RGB>
l   5,0,0      1          255,255,255
l   -5,0,0     1          255,255,255

# Sphere(s): sp <center coordinates: X,Y,Z> <diameter> <color>
sp  0,0,30     10         255,0,0

# Plane(s): pl <center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <color>
pl 0,0,100     0,0,-1     0,255,50

# Square(s): sq <center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <side size> <color>
sq 7.5,1,5    0.5,0,0.5   5         255,255,255

# Cylinder(s): cy <center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <diameter> <height> <color>
cy -20,20,80  0,1,1       10        20           255,20,255

# Triangle(s): tr <1st point coordinates> <2nd point coordinates> <3rd point coordinates> <color>
tr 10,10,10   5,10,10     10,5,20   255,20,0  
```

### Dependencies

This project depends on the [MLX42](https://github.com/codam-coding-college/MLX42.git) library, which itself depends on the [GLFW](https://www.glfw.org/) library. Both must be installed beforehand.

#### macOS

##### GLFW

To install GLFW on macOS, run:

```bash
brew install glfw
```

Alternatively, you can use precompiled binaries from the [official website](https://www.glfw.org/download.html).

##### MLX42

The easiest way to install MLX42 is to clone the repository and compile it. This will produce a static archive with all necessary functions, along with the include folder from the repo. Instructions from the [MLX42 repo](https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-macos):

```bash
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # 'build' refers to the output folder.
cmake --build build -j4 # or use make -C build -j4
```

The Makefile includes a predefined `mlx` target to automate these commands and install MLX42.

### How to Build

- `make` or `make all` - Build the binary and all necessary dependencies.
- `make mlx` - Build the MLX42 library (requires `git` and `cmake`).
- `make clean` - Remove object and dependency files.
- `make fclean` - Run `make clean` and remove the main binary.
- `make re` - Run `make fclean` and then `make all`.

### How to Use

To render a scene:

```bash
./miniRT <scene configuration file>
```

To save a screenshot in BMP format:

```bash
./miniRT <scene filepath> --save
```

The screenshot will be saved in the project root as `screenshot.bmp`.

To switch between multiple cameras, use the left and right arrow keys.

### References

- [Ray Tracing in One Weekend](https://raytracing.github.io/).

*Huge thanks to everyone from [42](https://42.fr) Moscow who provided scenes for the project!*