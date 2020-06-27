# https://www.practicepython.org/exercise/2014/11/11/20-element-search.html

from random import sample, randint

def binary_search(arr, item, start=0, end=None):
  end = end if end else len(arr) - 1
  middle = int((start + end) / 2)

  if start > end:
    return None
  if item > arr[middle]:
    return binary_search(arr, item, start=middle + 1, end=end)
  elif item < arr[middle]:
    return binary_search(arr, item, start, end=middle - 1)

  return middle

def main():
  init_list = sample(range(100), 50)
  init_list.sort()

  print("Sorted array", init_list)
  item = input("Enter item to search: ")

  print("Item position: ", binary_search(init_list, int(item)))

if __name__ == "__main__":
  main()