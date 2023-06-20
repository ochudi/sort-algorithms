using System;
using System.Linq;

int[] numbers = new int[20];

// Generate a list of 20 random numbers
Random random = new Random();
for (int i = 0; i < 20; i++)
{
    numbers[i] = random.Next(1, 1001);
}

// Sort the list using bubble sort
void BubbleSort(int[] arr)
{
    int n = arr.Length;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Perform binary search on a sorted list
int BinarySearch(int[] arr, int target)
{
    int low = 0;
    int high = arr.Length - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
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

// Print the original list
Console.WriteLine("Original list: " + string.Join(", ", numbers));

// Sort the list
BubbleSort(numbers);

// Print the sorted list
Console.WriteLine("Sorted list in ascending order: " + string.Join(", ", numbers));

// Get the number to search from the user
Console.Write("Enter a number to search: ");
int k = int.Parse(Console.ReadLine());

// Perform binary search
int result = BinarySearch(numbers, k);

// Check if the number is found or not
if (result != -1)
{
    Console.WriteLine("Number " + k + " is found at index " + result);
}
else
{
    Console.WriteLine("Number " + k + " is not found in the list");
}
