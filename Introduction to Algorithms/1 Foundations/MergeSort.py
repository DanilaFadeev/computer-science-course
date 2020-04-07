from random import sample

inf = float("inf") # infinity constant value

# arr - input array
# p, q, r - indexes, p <= q < r
def Merge(arr, p, q, r):
  left_len = q - p + 1
  right_len = r - q

  left, right = [], []

  for i in range(left_len):
    left.append(arr[p + i])
  for j in range(right_len):
    right.append(arr[q + j + 1])

  # add infinity as a signal of array end
  left.append(inf)
  right.append(inf)

  i, j = 0, 0
  for k in range(p, r + 1):
    if left[i] <= right[j]:
      arr[k] = left[i]
      i += 1
    else:
      arr[k] = right[j]
      j += 1


# another implementation of merge subprocedure where
# signal array items is not used
def Merge_Witout_Signals(arr, p, q, r):
  left_len = q - p + 1
  right_len = r - q

  left, right = [], []

  for i in range(left_len):
    left.append(arr[p + i])
  for j in range(right_len):
    right.append(arr[q + j + 1])

  i, j = 0, 0
  for k in range(p, r + 1):
    if i < left_len and j < right_len: # if both arrays are not empty
      if left[i] <= right[j]:
        arr[k] = left[i]
        i += 1
      else:
        arr[k] = right[j]
        j += 1   
    elif j >= right_len: # if right is empty take from left
      arr[k] = left[i]
      i += 1
    else: # else take from right
      arr[k] = right[j]
      j += 1  

def MergeSort(arr, p, r):
  if p < r:
    q = (p + r) // 2
    MergeSort(arr, p, q)
    MergeSort(arr, q + 1, r)
    Merge(arr, p, q, r)
    # Merge_Witout_Signals(arr, p, q, r)

if __name__ == "__main__":
  unsorted_arr = sample(range(100), 20)
  print(unsorted_arr)

  MergeSort(unsorted_arr, 0, 19)  
  print(unsorted_arr)