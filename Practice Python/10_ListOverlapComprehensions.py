# https://www.practicepython.org/exercise/2014/04/10/10-list-overlap-comprehensions.html

from random import sample

a = sample(range(100), 15)
b = sample(range(100), 18)

result = [item for item in set(a) if b.count(item) > 0]

print(f"A = {a},\nB = {b}\nA & B = {result}")
