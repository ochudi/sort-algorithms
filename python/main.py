# Allow the user to input 20 numbers
numbers = []
for i in range(20):
    number = int(input(f"Enter number {i+1}: "))
    numbers.append(number)

print("\nOriginal list:", numbers)


# Radix Sort algorithm.
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


# Bubble Sort algorithm.
def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                # Swap the elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# Binary Search algorithm (should be called on sorted list).
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


# Implementation
# Sort the list in descending order using radix sort
radix_sort(numbers)
numbers.reverse()
print("\nSorted list in descending order using Radix sort:", numbers)

# Sort the list using bubble sort
bubble_sort(numbers)
print("\nSorted list in ascending order using Bubble sort:", numbers)

# Print the original list
print("\nList of numbers:", numbers)

# Get the number to search from the user
k = int(input("Enter a number to search: "))

# Perform binary search
result = binary_search(numbers, k)

# Check if the number is found or not
if result != -1:
    print("Number", k, "is found at index", result)
else:
    print("Number", k, "is not found in the list")
