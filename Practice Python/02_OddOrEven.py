# https://www.practicepython.org/exercise/2014/02/05/02-odd-or-even.html

number = int(input("Input the number: "))

if number % 4 == 0:
  print(f"{number} is a multiply of 4")
elif number % 2 == 0:
  print(f"{number} is even")
else:
  print(f"{number} is odd")

def is_divides(num, check):
  return num % check == 0

num = int(input("Input number to check: "))
check = int(input("Input check number: "))

if is_divides(num, check):
  print("Divides 👍")
else:
  print("Not divides ❌")