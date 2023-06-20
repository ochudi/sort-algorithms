using System;

int[] numbers = new int[20];

// Generate an array of 20 random numbers
Random random = new Random();
for (int i = 0; i < 20; i++)
{
    int number = random.Next(1, 1001);
    numbers[i] = number;
}

Console.WriteLine("Original array: " + string.Join(", ", numbers));

// Sort the list in descending order using radix sort
RadixSort(numbers);
Array.Reverse(numbers);

Console.WriteLine("Sorted list in descending order: " + string.Join(", ", numbers));

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