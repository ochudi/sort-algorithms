#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

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

    // Bubble Sort algorithm
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                // Swap the elements
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "Sorted list in ascending order: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
