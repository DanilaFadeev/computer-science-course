from random import sample

unsorted_arr = sample(range(100), 20)
print(unsorted_arr)

# Insertion sort function implementet with aditional array
def Insertion_Sort_with_additional_array(arr):
  result = []
  for i in range(len(arr)):
    key = arr[i]
    j = i - 1
    while j >= 0 and result[j] > key:
      j -= 1
    result.insert(j + 1, key)  
  return result

print(Insertion_Sort_with_additional_array(unsorted_arr))  

# Insertion sort function with source array mutation
def Insertion_Sort(arr):
  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1
    arr[j + 1] = key

  return arr

print(Insertion_Sort(unsorted_arr))

# Insertion sort with descending items order
def Insertion_Sort_Desc(arr):
  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] < key:
      arr[j + 1] = arr[j]
      j -= 1
    arr[j + 1] = key

  return arr    

print(Insertion_Sort_Desc(unsorted_arr))