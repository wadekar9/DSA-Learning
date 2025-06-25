#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {63, 85, 100, 15, 70, 95, 25, 43, 33};

    for (int i = 0; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}