using System;
using System.Collections.Generic;
using System.Linq;

// Using a supporting counting_sort function.
void CountingSort(List<int> arr, int exp)
{
    int n = arr.Count;
    List<int> output = new List<int>(new int[n]);
    int[] count = new int[10];

    foreach (int num in arr)
    {
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

void RadixSort(List<int> arr)
{
    int maxNum = arr.Max();

    int exp = 1;
    while (maxNum / exp > 0)
    {
        CountingSort(arr, exp);
        exp *= 10;
    }
}

List<int> numbers = new List<int>();
Random random = new Random();

// Generate a list of 20 random numbers
for (int i = 1; i <= 20; i++)
{
    int number = random.Next(1, 101);
    numbers.Add(number);
}

Console.WriteLine("Original list: " + string.Join(", ", numbers));

// Sort the list in descending order using radix sort
RadixSort(numbers);
numbers.Reverse();

Console.WriteLine("Sorted list (descending order): " + string.Join(", ", numbers));
