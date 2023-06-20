import random

# Generate a list of 20 random numbers
numbers = random.sample(range(1, 1001), 20)


# Sort the list using bubble sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# Perform binary search on a sorted list
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1


# Print the original list
print("Original list:", numbers)

# Sort the list
bubble_sort(numbers)

# Print the sorted list
print("Sorted list in ascending order:", numbers)

# Get the number to search from the user
k = int(input("Enter a number to search: "))

# Perform binary search
result = binary_search(numbers, k)

# Check if the number is found or not
if result != -1:
    print("Number", k, "is found at index", result)
else:
    print("Number", k, "is not found in the list")
