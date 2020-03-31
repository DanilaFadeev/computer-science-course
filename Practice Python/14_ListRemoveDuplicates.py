# https://www.practicepython.org/exercise/2014/05/15/14-list-remove-duplicates.html

# Write a program (function!) that takes a list and returns a new list that contains all the elements of the first list minus all the duplicates.
# Extras:
# Write two different functions to do this - one using a loop and constructing a list, and another using sets.

def unique_by_set(source):
  return list(set(source))

def unique_by_loop(source):
  result = []
  for i in range(len(source)):
    if source[i] not in result:
      result.append(source[i])
  return result    

sample_list = [1, 1, 5, 9, 6, 5, 9, 2, 1, 4]

print("unique_by_set:", unique_by_set(sample_list))
print("unique_by_loop:", unique_by_loop(sample_list))
