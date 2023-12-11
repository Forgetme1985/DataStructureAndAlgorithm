#include <iostream>

using namespace std;

int fibonancy(int n)
{
    if(n == 0) return 0;
    else if(n == 1) return 1;
    return fibonancy(n - 1) + fibonancy(n - 2);
}

int main()
{
    cout << fibonancy(4) << endl;
    return 0;
}