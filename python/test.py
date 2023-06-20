import random


# Using a supporting counting_sort function.
def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for num in arr:
        index = (num // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        num = arr[i]
        index = (num // exp) % 10
        output[count[index] - 1] = num
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr):
    max_num = max(arr)

    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10


# Generate a list of 20 random numbers
numbers = random.sample(range(1, 101), 20)

print("Original list:", numbers)

# Sort the list in descending order using radix sort
radix_sort(numbers)
numbers.reverse()

print("Sorted list (descending order):", numbers)
