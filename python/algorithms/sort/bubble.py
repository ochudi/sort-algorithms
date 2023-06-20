import random

# Generate a list of 20 random numbers
numbers = random.sample(range(1, 1001), 20)

print("Original list:", numbers)

# Bubble sort algorithm


def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                # Swap the elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# Sort the list using bubble sort
bubble_sort(numbers)

print("Sorted list in ascending order:", numbers)
