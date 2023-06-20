require 'securerandom'

# Generate a list of 20 random numbers
numbers = Array.new(20) { rand(1..1000) }
puts "Original list: #{numbers}"

# Radix Sort algorithm.
def radix_sort(arr)
  # Find the maximum number to determine the number of digits
  max_num = arr.max
  num_digits = max_num.to_s.length

  # Perform counting sort for each digit
  (0...num_digits).each do |digit|
    # Initialize the count array and the output array
    count = [0] * 10
    output = [0] * arr.length

    # Count the occurrences of each digit
    arr.each do |num|
      count[(num / 10**digit) % 10] += 1
    end

    # Calculate the cumulative count
    (1..9).each do |i|
      count[i] += count[i - 1]
    end

    # Build the output array
    (arr.length - 1).downto(0) do |i|
      digit_value = (arr[i] / 10**digit) % 10
      output[count[digit_value] - 1] = arr[i]
      count[digit_value] -= 1
    end

    # Copy the sorted elements back to the original array
    output.each_with_index do |num, i|
      arr[i] = num
    end
  end
end

# Bubble Sort algorithm.
def bubble_sort(arr)
  n = arr.length

  (0...n-1).each do |i|
    (0...n-1-i).each do |j|
      if arr[j] > arr[j + 1]
        # Swap the elements
        arr[j], arr[j + 1] = arr[j + 1], arr[j]
      end
    end
  end
end

# Binary Search algorithm (should be called on sorted list).
def binary_search(arr, target)
  low = 0
  high = arr.length - 1

  while low <= high
    mid = (low + high) / 2
    if arr[mid] == target
      return mid
    elsif arr[mid] < target
      low = mid + 1
    else
      high = mid - 1
    end
  end

  return -1
end

# Implementation
# Sort the list in descending order using radix sort
radix_sort(numbers)
numbers.reverse!
puts "\nSorted list in descending order using Radix sort: #{numbers}"

# Sort the list using bubble sort
bubble_sort(numbers)
puts "Sorted list in ascending order using Bubble sort: #{numbers}"

# Print the original list
puts "Original list: #{numbers}"

# Get the number to search from the user
print "Enter a number to search: "
k = gets.chomp.to_i

# Perform binary search
result = binary_search(numbers, k)

# Check if the number is found or not
if result != -1
  puts "Number #{k} is found at index #{result}"
else
  puts "Number #{k} is not found in the list"
end
