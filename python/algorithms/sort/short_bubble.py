import random

# Generate a list of 20 random numbers
numbers = random.sample(range(1, 1001), 20)

print("Original list:", numbers)


# Short bubble sort algorithm
def short_bubble_sort(arr):
    n = len(arr)
    swapped = True
    passes = 0

    while swapped:
        swapped = False
        passes += 1
        for i in range(n - passes):
            if arr[i] > arr[i + 1]:
                # Swap the elements
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True


# Sort the list using short bubble sort
short_bubble_sort(numbers)

print("Sorted list in ascending order:", numbers)
