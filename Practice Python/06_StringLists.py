# https://www.practicepython.org/exercise/2014/03/12/06-string-lists.html

string = input("Input some string: ")

string_reversed = list(string)
string_reversed.reverse()
string_reversed = "".join(string_reversed)

if string == string_reversed:
  print("String is a palindrome")
else:
  print("String is not a palindrome")
