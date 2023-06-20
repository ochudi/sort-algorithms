# Generate a list of 20 random numbers
numbers = (1..1000).to_a.sample(20)

# Sort the list using bubble sort
def bubble_sort(arr)
  n = arr.length
  for i in 0..n-2
    for j in 0..n-i-2
      if arr[j] > arr[j+1]
        arr[j], arr[j+1] = arr[j+1], arr[j]
      end
    end
  end
end

# Perform binary search on a sorted list
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

# Print the original list
puts "Original list: #{numbers}"

# Sort the list
bubble_sort(numbers)

# Print the sorted list
puts "Sorted list in ascending order: #{numbers}"

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
