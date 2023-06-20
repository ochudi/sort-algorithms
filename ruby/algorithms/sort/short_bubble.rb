def short_bubble_sort(arr)
    n = arr.length
    swapped = true
    passes = 0
  
    while swapped
      swapped = false
      passes += 1
      (n - passes).times do |i|
        if arr[i] > arr[i + 1]
          # Swap the elements
          arr[i], arr[i + 1] = arr[i + 1], arr[i]
          swapped = true
        end
      end
    end
  end
  
  # Generate a list of 20 random numbers
  numbers = (1..1000).to_a.sample(20)
  
  puts "Original list: #{numbers}"
  
  # Sort the list using short bubble sort
  short_bubble_sort(numbers)
  
  puts "Sorted list in ascending order: #{numbers}"
  