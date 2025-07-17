#include <iostream>
#include <vector>
using namespace std;

void mergeCode(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSortingAlgo(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortingAlgo(arr, low, mid);
        mergeSortingAlgo(arr, mid + 1, high);
        mergeCode(arr, low, mid, high);
    }
}

int main()
{
    vector<int> nums = {6, 9, 21, 1, 20, 800, 54, 35};
    int size = nums.size() - 1;
    mergeSortingAlgo(nums, 0, size);
    for (int i = 0; i <= size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}

// Time Complexity :
//     Worst case : O(nlogn)
//     Avg case : O(n2)
//     Best case : O(n) (if array is already sorted.