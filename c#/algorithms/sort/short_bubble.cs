using System;
using System.Collections.Generic;
using System.Linq;

List<int> numbers = new List<int>();

// Generate a list of 20 random numbers
Random random = new Random();
for (int i = 0; i < 20; i++)
{
    int number = random.Next(1, 1001);
    numbers.Add(number);
}

Console.WriteLine("Original list: " + string.Join(", ", numbers));

// Short bubble sort algorithm
void ShortBubbleSort(List<int> arr)
{
    int n = arr.Count;
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
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

// Sort the list using short bubble sort
ShortBubbleSort(numbers);

Console.WriteLine("Sorted list in ascending order: " + string.Join(", ", numbers));
