#include <iostream>
using namespace std;

int main()
{
	const int size = 7;
	int arr[] = {8,5,1,3,9,7,6};
	for(int i = 0; i < size; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = i + 1; j < size;j++)
			{
				if(arr[i] < arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		else
		{
			for(int j = i + 1; j < size;j++)
			{
				if(arr[i] > arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	for(int i = 0; i < size;i++)
	{
		cout << arr[i] << " ";
	}
    return 0;
}
