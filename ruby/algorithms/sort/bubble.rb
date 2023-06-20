# Generate a list of 20 random numbers
numbers = (1..1000).to_a.sample(20)

puts "Original list: #{numbers}"

# Bubble sort algorithm
def bubble_sort(arr)
  n = arr.length

  for i in 0..n-2
    for j in 0..n-2-i
      if arr[j] > arr[j+1]
        arr[j], arr[j+1] = arr[j+1], arr[j]
      end
    end
  end
end

# Sort the list using bubble sort
bubble_sort(numbers)

puts "Sorted list in ascending order: #{numbers}"
