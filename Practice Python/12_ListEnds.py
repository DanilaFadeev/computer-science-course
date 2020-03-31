# https://www.practicepython.org/exercise/2014/04/25/12-list-ends.html

# Write a program that takes a list of numbers (for example, a = [5, 10, 15, 20, 25]) and makes a new list of only the first and last elements of the given list.
# For practice, write this code inside a function.

from random import sample, randint

def get_ends_list(source_list):
  return [source_list[0], source_list[len(source_list) - 1]]

list_random = sample(range(100), randint(2, 10))

print(list_random)
print(get_ends_list(list_random))