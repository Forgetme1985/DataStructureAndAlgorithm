#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int arr1[] = {1,2,3,4,5};
	cout << "1D" << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << &arr1[i] << endl;
	}

	int arr2[3][3] = {
		{1,2,3},
		{1,2,3},
		{1,2,3}
	};
	cout << "2D" << endl;
	for(int i =0; i < 3; i++)
		for(int j =0; j < 3;j++)
		{
			cout << &arr2[i][j] << endl;
		}
	int arr3[3][3][3] = {
		{{1,2,3},{1,2,3},{1,2,3}},
		{{1,2,3},{1,2,3},{1,2,3}},
		{{1,2,3},{1,2,3},{1,2,3}},
	};
	cout << "3D" << endl;
	for(int i =0; i < 3; i++)
		for(int j =0; j < 3;j++)
		{
			for(int k =0; k < 3;k++)
				cout << &arr3[i][j][k] << endl;
		}
    return 0;
}
