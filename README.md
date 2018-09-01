# ComS-327-KnightsTour
Assignment 1 for ComS-327. Common Programming problem.

# Info
See this Wikipedia article about the Knight’s Tour problem: http://en.wikipedia.org/wiki/Knight%27s tour.
Finding all directed, open tours on a standard, 8 × 8 chessboard is computationally intractable. To find
them all on a 7 × 7 board in reasonable time would require a supercomputer. My quick-and-dirty solution
finds all 6 × 6 solutions in 127 minutes 52 seconds and all 5 × 5 tours in under 0.6 seconds on a laptop.
Write a C program to find all directed, open Knight’s Tours on a 5 × 5 chess board. Assume the spaces
of the board are numbered:
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

# Print
Print all tours as a list of numbers corresponding to the spaces in the order they are visited. For instance,
here is one solution:
25,18,21,12,23,20,9,2,11,22,19,10,13,16,7,4,15,24,17,6,3,14,5,8,1
There are 1727 others.
See the syllabus for information about what to turn in and submission format.

# Extra Challenges (nothing below this line is required)
• Generalize your program to handle boards of arbitrary dimension x × y.
• Generalize your program to handle boards on a cylinder.
• Generalize your program to handle boards on a torus.
• Generalize your program to handle arbitrary boards (a graph with rectilinearly connected nodes).
• Find only the subset of tours which are unique under rotation and reflection.
• Print a board with the spaces numbered by the order in which they are visited. For instance, here is
the board corresponding with the solution given above:
25 8 21 16 23
20 15 24 7 12
9 4 13 22 17
14 19 2 11 6
3 10 5 18 1
• Generate graphical representations of your tours. For instance, I used METAPOST to generate an
image of the tour above and one on a full 8 × 8 board:
