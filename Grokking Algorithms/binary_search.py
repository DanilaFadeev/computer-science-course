from random import sample

rand_arr = list(set(sample(range(40), 20)))
rand_arr.sort()

def binary_search(arr, item):
  low, high = 0, len(arr) - 1

  while low <= high:
    middle = round((low + high) / 2)
    if arr[middle] == item:
      return middle
    elif arr[middle] > item:
      high = middle - 1
    else:
      low = middle + 1

  return None        

print(rand_arr)
print(binary_search(rand_arr, 10))
