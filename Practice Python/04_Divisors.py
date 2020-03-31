# https://www.practicepython.org/exercise/2014/02/26/04-divisors.html

num = int(input("Input simple number: "))

divisors = []
for i in range(1, round(num / 2) + 1):
  if num % i == 0:
    divisors.append(i)

divisors.append(num) # number is always own divisor

print(divisors)