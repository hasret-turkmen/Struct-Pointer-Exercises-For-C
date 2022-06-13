# Struct-Pointer-Exercises-For-C

Task:

Create a .txt file which keeps the list of shapes. Please check the content of the example shapes1.txt below.

Content of shapes1.txt:
square 4 -5 3
rectangle -3 4 4 5
square 3 -2 1
circle 1 3 4
square -4 -1 5

Each line contains a shape data. The data format for each shape type is as follows:

  rectangle <bottom-left-corner-x-coordinate> <bottom-left-corner-y-coordinate> <width> <height>

  square <bottom-left-corner-x-coordinate> <bottom-left-corner-y-coordinate> <side-length>

  circle <center-x-coordinate> <center-y-coordinate> <radius>


Follow the below steps in your program:
-Create point_t structure with x (double) and y (double) coordinates.
-Create circle_t structure with center (point_t) and radius (double).
-Create square_t structure with bottom left corner (point_t) and side (double).
-Create rectangle_t structure with bottom left corner (point_t), width (double) and height (double).
-Create union type shape_data_t with circle (circle_t), square (square_t) and rectangle (rectangle_t).
-Create enumerated type class_t with constants CIRCLE, SQUARE, RECTANGLE.
-Create shape_t structure with type (class_t) and shape (shape_data_t). type field determines which
member of shape contains a value. If type is CIRCLE, shape.circle contains a value. If type is SQUARE,
shape.square contains a value. If type is RECTANGLE, shape.rectangle contains a value.

  Write 3 functions:

   int scanShape(FILE *filep, shape_t *objp);
scanShape function gets a pointer to FILE and a pointer to shape_t. Reads shape data from the
file, and fills shape_t pointed to, by objp. Returns 1 if the read operation is successful; otherwise,
returns 0.

   int loadShapes(shape_t shapes[]);
loadShapes function gets an array of shape_t. Opens the text file with the entered name. For
each array element, reads data by calling scanShape function. Stops reading when scanShape
function returns 0. Returns the number of read shapes.

   void printShape(const shape_t *objp);
printShape function gets a pointer to a constant shape_t. Prints shape information. The format
for each shape type is as follows (also see example run). While printing double values, use %.2lf
as the format specifier.

  Rectangle: <bottom-left-corner-x-coordinate bottom-left-corner-y-coordinate> <width> <height>

  Square: <bottom-left-corner-x-coordinate bottom-left-corner-y-coordinate> <side-length>

  Circle: <center-x-coordinate center-y-coordinate> <radius>

   main function is already provided to you (see shape_part1.c) and it is supposed to remain as it is
(you should not change it). In main function, an array of shape_t is declared, loadShapes function
is called, and all shapes are printed.
