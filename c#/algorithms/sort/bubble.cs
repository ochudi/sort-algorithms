using System;
using System.Linq;

int[] numbers = new int[20];

// Generate a list of 20 random numbers
Random random = new Random();
for (int i = 0; i < 20; i++)
{
    numbers[i] = random.Next(1, 1001);
}

// Print the original list
Console.WriteLine("Original list: " + string.Join(", ", numbers));

// Bubble sort algorithm
void BubbleSort(int[] arr)
{
    int n = arr.Length;

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

// Sort the list using bubble sort
BubbleSort(numbers);

// Print the sorted list
Console.WriteLine("Sorted list in ascending order: " + string.Join(", ", numbers));
