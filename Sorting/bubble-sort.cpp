#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {56, 26, 30, 55, 22, 36, 9, 93, 888, 43};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}