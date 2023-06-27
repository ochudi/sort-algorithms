#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Radix Sort algorithm.
void radix_sort(vector<int> &arr)
{
    int max_num = *max_element(arr.begin(), arr.end());
    int num_digits = log10(max_num) + 1;

    for (int digit = 0; digit < num_digits; digit++)
    {
        vector<int> count(10, 0);
        vector<int> output(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++)
        {
            int digit_value = (arr[i] / static_cast<int>(pow(10, digit))) % 10;
            count[digit_value]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int digit_value = (arr[i] / static_cast<int>(pow(10, digit))) % 10;
            output[count[digit_value] - 1] = arr[i];
            count[digit_value]--;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = output[i];
        }
    }
}

// Bubble Sort algorithm.
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
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
    // Allow the user to input 20 numbers
    vector<int> numbers;
    numbers.reserve(20);

    for (int i = 0; i < 20; i++)
    {
        int number;
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;
        numbers.push_back(number);
    }

    cout << "Original list: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Sort the list in descending order using radix sort
    radix_sort(numbers);
    reverse(numbers.begin(), numbers.end());
    cout << "\nSorted list in descending order using Radix sort: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Sort the list in ascending order using bubble sort
    bubble_sort(numbers);
    cout << "\nSorted list in ascending order using Bubble sort: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Get the number to search from the user
    int k;
    cout << "\nEnter a number to search: ";
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
