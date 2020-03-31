# https://www.practicepython.org/exercise/2014/04/30/13-fibonacci.html

numbers_count = int(input("How many Fibonnaci numbers do you want to get: "))

def fibonnaci(count):
  fibonnaci_list = [1, 1]

  for i in range(count - 2):
    list_len = len(fibonnaci_list)
    fibonnaci_list.append(fibonnaci_list[list_len - 2] + fibonnaci_list[list_len - 1])

  return fibonnaci_list

def fibonnaci_resursive(count, fibonnaci_list = []):
  if count == 0:
    return fibonnaci_list

  if len(fibonnaci_list) == 0:
    return fibonnaci_resursive(count - 2, [1, 1])

  list_len = len(fibonnaci_list)
  fibonnaci_list.append(fibonnaci_list[list_len - 2] + fibonnaci_list[list_len - 1])

  return fibonnaci_resursive(count - 1, fibonnaci_list)  


print("Loop solution:     ", fibonnaci(numbers_count))
print("Recursive solution:", fibonnaci_resursive(numbers_count))
