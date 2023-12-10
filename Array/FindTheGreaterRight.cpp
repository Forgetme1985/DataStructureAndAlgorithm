#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> greaterRight;
	const int size = 5;
	int arr[] = {6,8,4,3,9};
	for(int i = 0; i < size; i++)
	{
		int max = arr[i];
		for(int j = i + 1; j < size;j++)
		{
			if(max < arr[j])
			{
				max = arr[j];
				break;
			}
		}
		greaterRight.push_back(max);
	}
	for(auto iter = greaterRight.begin(); iter != greaterRight.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
    return 0;
}
