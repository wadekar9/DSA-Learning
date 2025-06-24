// selection sort
//  select minimums
// in this algorithm, we search and select smallest element from given range and replace it with current first element;

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {62, 5, 10, 300, 75};
    for (int i = 0; i < arr.size(); i++)
    {
        int min = i;
        int temp = arr[i];
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// Nearest time complexity = O(n2) -- (best, average, worst)