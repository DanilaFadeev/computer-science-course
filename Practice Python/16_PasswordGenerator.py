# https://www.practicepython.org/exercise/2014/05/28/16-password-generator.html

from string import ascii_lowercase, ascii_uppercase, digits, punctuation
from random import choice

class PasswordLevel:
  Weak, Normal, Strong = range(3)

def generate_password(length = 8, level = PasswordLevel.Normal):
  available_symbols = ascii_lowercase + ascii_uppercase

  if level == PasswordLevel.Normal or level == PasswordLevel.Strong:
    available_symbols += digits
  if level == PasswordLevel.Strong:
    available_symbols += punctuation

  return "".join([choice(available_symbols) for el in range(length)])

def main():
  print("Weak password (Length 8):    ", generate_password(length=8, level=PasswordLevel.Weak))
  print("Weak password (Length 12):   ", generate_password(length=12, level=PasswordLevel.Weak))
  print("Weak password (Length 16):   ", generate_password(length=16, level=PasswordLevel.Weak))

  print("Normal password (Length 8):  ", generate_password(length=8, level=PasswordLevel.Normal))
  print("Normal password (Length 12): ", generate_password(length=12, level=PasswordLevel.Normal))
  print("Normal password (Length 16): ", generate_password(length=16, level=PasswordLevel.Normal))

  print("Strong password (Length 8):  ", generate_password(length=8, level=PasswordLevel.Strong))
  print("Strong password (Length 12): ", generate_password(length=12, level=PasswordLevel.Strong))
  print("Strong password (Length 16): ", generate_password(length=16, level=PasswordLevel.Strong))

if __name__ == "__main__":
  main()