def radix_sort(arr)
    # Find the maximum number to determine the number of digits
    max_num = arr.max
    num_digits = max_num.to_s.length
  
    # Perform counting sort for each digit
    num_digits.times do |digit|
      # Initialize the count array and the output array
      count = Array.new(10, 0)
      output = Array.new(arr.length, 0)
  
      # Count the occurrences of each digit
      arr.each do |num|
        count[(num / 10 ** digit) % 10] += 1
      end
  
      # Calculate the cumulative count
      (1..9).each do |i|
        count[i] += count[i - 1]
      end
  
      # Build the output array
      (arr.length - 1).downto(0) do |i|
        digit_value = (arr[i] / 10 ** digit) % 10
        output[count[digit_value] - 1] = arr[i]
        count[digit_value] -= 1
      end
  
      # Copy the sorted elements back to the original array
      arr.each_index do |i|
        arr[i] = output[i]
      end
    end
  end
  
  # Generate a list of 20 random numbers
  numbers = (1..1000).to_a.sample(20)
  
  puts "Original list: #{numbers}"
  
  # Sort the list in descending order using radix sort
  radix_sort(numbers)
  numbers.reverse!
  
  puts "Sorted list in descending order: #{numbers}"
  