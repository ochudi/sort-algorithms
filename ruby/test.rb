# Using a supporting counting_sort function.
def counting_sort(arr, exp)
  n = arr.length
  output = Array.new(n, 0)
  count = Array.new(10, 0)

  arr.each do |num|
    index = (num / exp) % 10
    count[index] += 1
  end

  (1..9).each do |i|
    count[i] += count[i - 1]
  end

  i = n - 1
  while i >= 0
    num = arr[i]
    index = (num / exp) % 10
    output[count[index] - 1] = num
    count[index] -= 1
    i -= 1
  end

  output.each_with_index do |num, i|
    arr[i] = num
  end
end

def radix_sort(arr)
  max_num = arr.max

  exp = 1
  while max_num / exp > 0
    counting_sort(arr, exp)
    exp *= 10
  end
end

# Generate a list of 20 random numbers
numbers = (1..100).to_a.sample(20)

puts "Original list: #{numbers}"

# Sort the list in descending order using radix sort
radix_sort(numbers)
numbers.reverse!

puts "Sorted list (descending order): #{numbers}"
