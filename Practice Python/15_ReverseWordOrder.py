# https://www.practicepython.org/exercise/2014/05/21/15-reverse-word-order.html

def reverse_words(string):
  words_list = string.split(" ")
  words_list.reverse()

  return " ".join(words_list)

string = input("Input string with a few words: ")
print(reverse_words(string))
