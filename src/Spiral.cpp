/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int* path(int k, int m, int l, int n, int c, int **input_array, int *output)
{
	int i;
	if (input_array == NULL||m<0||n<0)
		return NULL;
	if (k < m && l < n)
	{
		for (i = l; i < n; ++i)
		{
			output[c++]=input_array[k][i];
		}
		k++;

		/* Print the last column from the remaining columns */
		for (i = k; i < m; ++i)
		{
			output[c++] = input_array[i][n-1]; 
		}
		n--;

		/* Print the last row from the remaining rows */
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				output[c++] = input_array[m-1][i];
			}
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				output[c++] = input_array[i][l];
			}
			l++;
		}
		return path(k, m, l, n, c, input_array, output);
	}
	else
		return output;
}
int *spiral(int rows, int columns, int **input_array)
{
	int *output = (int *)malloc(rows*columns*sizeof(int));
	if (rows <= 0 || columns <= 0)
		return NULL;
	return path(0,rows,0,columns,0,input_array,output);
}
