# Python code to generate 20 numbers and implement Radix sort to rearrange in descending order.
import random


def radix_sort(arr):
    # Find the maximum number to determine the number of digits
    max_num = max(arr)
    num_digits = len(str(max_num))

    # Perform counting sort for each digit
    for digit in range(num_digits):
        # Initialize the count array and the output array
        count = [0] * 10
        output = [0] * len(arr)

        # Count the occurrences of each digit
        for num in arr:
            count[(num // 10 ** digit) % 10] += 1

        # Calculate the cumulative count
        for i in range(1, 10):
            count[i] += count[i - 1]

        # Build the output array
        for i in range(len(arr) - 1, -1, -1):
            digit_value = (arr[i] // 10 ** digit) % 10
            output[count[digit_value] - 1] = arr[i]
            count[digit_value] -= 1

        # Copy the sorted elements back to the original array
        for i in range(len(arr)):
            arr[i] = output[i]


# Generate a list of 20 random numbers
numbers = random.sample(range(1, 1001), 20)

print("Original list:", numbers)

# Sort the list in descending order using radix sort
radix_sort(numbers)
numbers.reverse()

print("Sorted list in descending order:", numbers)
