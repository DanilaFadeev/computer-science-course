from random import sample, randint

def sum(arr):
  if len(arr) == 1:
    return arr[0]
  return arr[0] + sum(arr[1:])

print(sum([50, 28, 12, 10, 80, 20]))

call_count = 0

def quick_sort(arr):
  global call_count
  call_count += 1

  if len(arr) < 1:
    return arr

  random_index = randint(0, len(arr) - 1)
  base = arr[random_index]
  less = [item for index, item in enumerate(arr) if item <= base and index != random_index]
  more = [item for index, item in enumerate(arr) if item > base and index != random_index]
  call_count

  return quick_sort(less) + [base] + quick_sort(more)


random_arr = sample(range(1000), 200)
print(quick_sort(range(200)))
print(call_count)