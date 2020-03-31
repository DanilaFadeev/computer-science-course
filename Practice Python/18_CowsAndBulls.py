from random import sample

def generate_number(length=4):
  digits = '123456789'
  return sample(digits, 4)

def check_guess(guessed_number, guess):
  bulls, cows = [], []

  # bulls count
  for index in range(len(guessed_number)):
    if guessed_number[index] == guess[index]:
      bulls.append(guess[index])

  # cows count
  for num in guess:
    if num not in bulls and num in guessed_number:
      cows.append(num)

  return len(bulls), len(cows)


def main():
  print("Welcome to Cows and Bulls game!")

  guessed_number = generate_number()
  bulls, cows = 0, 0

  while bulls != 4:
    guess = input("Enter your guess: ")
    bulls, cows = check_guess(guessed_number, guess)

    print(f"{bulls} bulls, {cows} cows")
  
  print("Your won! Guessed number is", "".join(guessed_number))
  

if __name__ == "__main__":
  main()
