from random import sample

def selectSort(arr):
  result = []
  source_copy = arr.copy()

  for i in range(len(source_copy)):
    max_item = max(source_copy)
    source_copy.remove(max_item)
    result.append(max_item)

  return result   

rand_arr = sample(range(20), 10)

print(rand_arr)
print(selectSort(rand_arr))
