#include <iostream>

using namespace std;

int main()
{
	
	/*int matrix [10][12] = 
	{
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,-1,0,0,0,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{4,0,0,-3,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{-1,0,0,0,5,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,0,0,4,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0}
	};*/
	int matrix[7][6] =
	{
		{0,1,0,0,0,0},
		{0,0,0,0,0,0},
		{-2,0,0,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,-3,0,0,0,0},
		{0,0,0,0,0,1}

	};
	int row = 7;
	int column = 6;
	int countNonZero;
	int arrIndexRow[100];
	int arrIndexCol[100];
	int arrValue[100];
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
		{
			if(matrix[i][j] != 0)
			{
				arrIndexRow[countNonZero] = i;
				arrIndexCol[countNonZero] = j;
				arrValue[countNonZero] = matrix[i][j];
				countNonZero++;
			}
		}
	int sparseMatrix[countNonZero + 1][3];
	//step 1: row 0th: the number of rows, the number of cols and the number of non-zero elements
	sparseMatrix[0][0] = row;
	sparseMatrix[0][1] = column;
	sparseMatrix[0][2] = countNonZero;
	//step 2: row ith->n-1th: the row index, the col index and the value
	for(int i =1; i <= countNonZero;i++)
	{
		sparseMatrix[i][0] = arrIndexRow[i - 1];
		sparseMatrix[i][1] = arrIndexCol[i - 1];
		sparseMatrix[i][2] = arrValue[i - 1];
	}

	for(int i = 0; i < countNonZero + 1; i++)
	{
		for(int j =0; j < 3; j++)
		{
			cout << sparseMatrix[i][j] << " ";
		}
		cout << endl;
	}

	//step 3: transpose matrix
	int transposeMatrix[3][countNonZero + 1];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j <= countNonZero; j++)
		{
			transposeMatrix[i][j] = sparseMatrix[j][i];
			cout << transposeMatrix[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}
