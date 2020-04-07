from random import sample
from MergeSort import MergeSort

def BinarySearch(arr, find, p, r):
  q = (p + r) // 2
  if arr[q] == find:
    return q
  if p >= r:
    return None  
  if arr[q] > find:
    return BinarySearch(arr, find, p, q)
  else:
    return BinarySearch(arr, find, q + 1, r)    

if __name__ == "__main__":
  arr = sample(range(50), 20)
  MergeSort(arr, 0, len(arr) - 1)
  print(arr)

  found_index = BinarySearch(arr, 26, 0, len(arr) - 1)
  print(found_index)