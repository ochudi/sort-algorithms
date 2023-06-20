#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void shortBubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped = true;
    int passes = 0;

    while (swapped)
    {
        swapped = false;
        passes++;

        for (int i = 0; i < n - passes; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
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

    // Sort the list using short bubble sort
    shortBubbleSort(numbers);

    cout << "Sorted list in ascending order: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
