from random import sample

inf = float("inf") # infinity constant value

unsorted_arr = sample(range(100), 20)
print(unsorted_arr)

# invariant: arr[0..i] - sorted array
# best case: O(n^2)
# worst case: O(n^2)
def SelectionSort(arr):
  for i in range(len(arr) - 2):
    # find minimal item index
    index, value = 0, inf
    for j in range(i, len(arr)):
      if arr[j] < value:
        index, value = j, arr[j]

    arr[i], arr[index] = arr[index], arr[i]

  return arr

print(SelectionSort(unsorted_arr))    

