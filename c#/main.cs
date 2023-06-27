using System;

void Main()
{
    int[] numbers = new int[20];

    // Generate an array of 20 random numbers
    Random random = new Random();
    for (int i = 0; i < 20; i++)
    {
        int number = random.Next(1, 1001);
        numbers[i] = number;
    }

    Console.WriteLine("Original array: " + string.Join(", ", numbers));

    // Radix Sort algorithm
    RadixSort(numbers);
    Array.Reverse(numbers);
    Console.WriteLine("\nSorted array in descending order using Radix sort: " + string.Join(", ", numbers));

    // Bubble Sort algorithm
    BubbleSort(numbers);
    Console.WriteLine("\nSorted array in ascending order using Bubble sort: " + string.Join(", ", numbers));

    // Get the number to search from the user
    Console.Write("\nEnter a number to search: ");
    int k = int.Parse(Console.ReadLine());

    // Binary Search algorithm (should be called on sorted array)
    int result = BinarySearch(numbers, k);

    // Check if the number is found or not
    if (result != -1)
    {
        Console.WriteLine("Number " + k + " is found at index " + result);
    }
    else
    {
        Console.WriteLine("Number " + k + " is not found in the array");
    }
}

void RadixSort(int[] arr)
{
    int maxNum = arr.Max();
    int numDigits = (int)Math.Log10(maxNum) + 1;

    for (int digit = 0; digit < numDigits; digit++)
    {
        int[] count = new int[10];
        int[] output = new int[arr.Length];

        foreach (int num in arr)
        {
            int index = (num / (int)Math.Pow(10, digit)) % 10;
            count[index]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = arr.Length - 1; i >= 0; i--)
        {
            int num = arr[i];
            int index = (num / (int)Math.Pow(10, digit)) % 10;
            output[count[index] - 1] = num;
            count[index]--;
        }

        output.CopyTo(arr, 0);
    }
}

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

Main();
