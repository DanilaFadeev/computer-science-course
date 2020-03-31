# https://www.practicepython.org/exercise/2014/04/02/09-guessing-game-one.html

from random import randint

rand_number = randint(1, 9)
guesses_count = 0

guess_number = None
while guess_number != rand_number:
  guess_number = int(input("Guess number: "))
  guesses_count += 1
  
  if guess_number > rand_number:
    print("Rand number is lower")
  elif guess_number < rand_number:
    print("Rand number is higher") 
  

print(f"Right! Correct answer is {rand_number}. Guesses count: {guesses_count}")