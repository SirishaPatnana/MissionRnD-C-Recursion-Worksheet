/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/
int path_exist(int *maze, int M, int N, int x1, int y1, int x2, int y2)
{
	int x, y, a = 0, b = 0, t, c = 0, d = 0;
	if (x1 == x2 && y1 == y2)
		return 1;
	t = maze[x1*N + y1];
	maze[x1*N + y1] = -1;
	if (x1 - 1 >= 0)
	if (maze[(x1 - 1)*N + y1] == 1)
		a = path_exist(maze, M, N, x1 - 1, y1, x2, y2);
	if (x1 + 1 < M)
	if (maze[(x1 + 1)*N + y1] == 1)
		b = path_exist(maze, M, N, x1 + 1, y1, x2, y2);
	if (y1 - 1 >= 0)
	if (maze[(x1)*N + y1 - 1] == 1)
		c = path_exist(maze, M, N, x1, y1 - 1, x2, y2);
	if (y1 + 1<N)
	if (maze[(x1)*N + y1 + 1] == 1)
		d = path_exist(maze, M, N, x1, y1 + 1, x2, y2);
	maze[x1*N + y1] = t;
	if (a == 1 || b == 1 || c == 1 || d == 1)
		return 1;
	return 0;
}
int path_exists(int *maze, int M, int N, int x1, int y1, int x2, int y2)
{

	if (x1 >= M || x1 < 0 || x2 >= M || x2 < 0 || y1 >= N || y1 < 0 || y2 >= N || y2 < 0)
		return 0;
	if (maze[x2*N + y2] == 0 || maze[x1*N + y1] == 0)
		return 0;
	return path_exist(maze, M, N, x1, y1, x2, y2);
}
