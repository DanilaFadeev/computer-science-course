# https://www.practicepython.org/exercise/2014/01/29/01-character-input.html

from datetime import datetime

user_name = input("Your name: ")
user_age = int(input("Your age: "))
copies_count = int(input("How many copies to output: "))

current_year = datetime.now().year

output_message = f"{user_name}, your age is better than 100 years!"

if user_age < 100:
  difference_with_hungreed = 100 - user_age
  final_year = current_year + difference_with_hungreed - 1

  output_message = f"{user_name}, you will turn 100 years old on {final_year}!"

for i in range(copies_count):
  print(output_message)
