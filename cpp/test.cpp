#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void counting_sort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int index = (num / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        int index = (num / exp) % 10;
        output[count[index] - 1] = num;
        count[index]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int> &arr)
{
    int max_num = *max_element(arr.begin(), arr.end());

    int exp = 1;
    while (max_num / exp > 0)
    {
        counting_sort(arr, exp);
        exp *= 10;
    }
}

int main()
{
    // Generate a list of 20 random numbers
    vector<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 20; i++)
    {
        numbers.push_back(dis(gen));
    }

    cout << "Original list: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Sort the list in descending order using radix sort
    radix_sort(numbers);
    reverse(numbers.begin(), numbers.end());

    cout << "Sorted list (descending order): ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
