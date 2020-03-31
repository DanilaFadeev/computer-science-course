# https://www.practicepython.org/exercise/2014/04/16/11-check-primality-functions.html

# Ask the user for a number and determine whether the number is prime or not.
# (For those who have forgotten, a prime number is a number that has no divisors.).
# You can (and should!) use your answer to Exercise 4 to help you.
# Take this opportunity to practice using functions, described below.

def get_integer(input_msg):
  return int(input(input_msg))

def is_prime(num):
  for i in range(2, round(num / 2) + 1):
    if num % i == 0:
      return False
  return True

number = get_integer("Input any number: ")
print("Prime" if is_prime(number) else "Not prime")