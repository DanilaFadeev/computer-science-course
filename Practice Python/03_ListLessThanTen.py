# https://www.practicepython.org/exercise/2014/02/15/03-list-less-than-ten.html

max_number = int(input("Input max number to filter: "))

source_list = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
processed_list = list(filter(lambda num: num < max_number, source_list))

print(processed_list)