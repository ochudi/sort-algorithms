#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Bubble Sort algorithm.
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search algorithm (should be called on a sorted list).
int binary_search(const vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    // Generate a list of 20 random numbers
    vector<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < 20; i++)
    {
        numbers.push_back(dis(gen));
    }

    cout << "Original list: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Sort the list
    bubble_sort(numbers);

    cout << "Sorted list in ascending order: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Get the number to search from the user
    int k;
    cout << "Enter a number to search: ";
    cin >> k;

    // Perform binary search
    int result = binary_search(numbers, k);

    // Check if the number is found or not
    if (result != -1)
    {
        cout << "Number " << k << " is found at index " << result << endl;
    }
    else
    {
        cout << "Number " << k << " is not found in the list" << endl;
    }

    return 0;
}
