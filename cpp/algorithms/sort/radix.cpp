#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Radix Sort algorithm.
void radixSort(vector<int> &arr)
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

    // Sort the list in descending order using radix sort
    radixSort(numbers);
    reverse(numbers.begin(), numbers.end());

    cout << "Sorted list in descending order: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
