#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> leaders;
	const int size = 8;
	int arr[] = {1,8,6,7,3,1,5,2};
	for(int i = 0; i < size - 1; i++)
	{
		int j = i;
		for(j = i; j < size - 1;j++)
		{
			if(arr[i] <= arr[j + 1])
				break;
		}
		if(j == size - 1)
			leaders.push_back(arr[i]);
	}
	for(auto iter = leaders.begin(); iter != leaders.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
    return 0;
}
