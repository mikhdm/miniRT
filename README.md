# miniRT

### Description

Raytracing implementation drawing various figures (plane, triangle, square, cylinder and sphere) on the screen with lightning.
This project was implemented while studying at [42](https://42.fr) (Moscow).

### Task

The task is to implement simple raytracing and draw various figures on the screen, support ambience and global lighting, translation, rotation and shadows, multiple cameras with options to switch between them as well as custom configuration to properly control the scene.

#### Configuration

This is an example of scene configuration file with the description with every possible option:

```
# Resolution of the window settings: R <width> <height>
R   800        600

# Ambience lighting: A <lighting ratio in [0.0,1.0]> <color: RGB in [0,255] for each channel>
A   0.5        255,0,0

# Camera(s): c <position coordinates: X,Y,Z> <orientation vector: X,Y,Z in [-1,1]> <horizontal FOV (field of view) in [0,180]>
c   0,0,-20     0,0,1     53.3

# Light(s): l <position coordinates: X,Y,Z> <brightness ratio in [0.0,1.0]>
l   5,0,0      1          255,255,255
l   -5,0,0     1          255,255,255

# Sphere(s): sp <sphere center coordinates: X,Y,Z> <diameter> <color>
sp  0,0,30     10         255,0,0

# Plane(s):  pl <plane center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <color>
pl 0,0,100     0,0,-1     0,255,50

# Square(s): sq <square center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <size of the side> <color>
sq 7.5,1,5    0.5,0,0.5   5         255,255,255

# Cylinder(s): cy <cylinder center coordinates: X,Y,Z> <orientation vector: X,Y,Z> <diameter> <height> <color> 
cy -20,20,80  0,1,1       10        20           255,20,255

# Triangle(s): tr  <1-st point coordinates> <2-nd point coordinates> <3-rd point coordinates> <color>
tr 10,10,10   5,10,10     10,5,20   255,20,0  
```