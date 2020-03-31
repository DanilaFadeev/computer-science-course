# https://www.practicepython.org/exercise/2014/03/05/05-list-overlap.html

from random import randint

first_arr_len = randint(10, 20)
second_arr_len = randint(10, 20)

first_arr = []
second_arr = []

for i in range(first_arr_len):
  first_arr.append(randint(0, 100))

for i in range(second_arr_len):
  second_arr.append(randint(0, 100))

result = set(first_arr) & set(second_arr)

print(f"A = {first_arr},\nB = {second_arr}\nA & B = {result}")
