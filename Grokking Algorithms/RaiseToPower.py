from time import time

def raise_to_power(number, power):
  if power == 0:
    return 1
  if power % 2 == 0:
   return raise_to_power(number * number, power / 2)
  return number * raise_to_power(number, power - 1)

  