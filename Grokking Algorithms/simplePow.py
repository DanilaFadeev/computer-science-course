from time import time

iterations_count = 0

num = 26
power = 124

start_time = time()

# print(num**power, start_time)

# result = 1
# for i in range(power):
#   result *= num

# print(result)  

def simplePow(n, p):
  global iterations_count
  iterations_count += 1

  if p == 0 or p == 1:
    return n
  if p % 2 == 0:
    return simplePow(n * n, p / 2)
  return n * simplePow(n, p - 1)

print(simplePow(26, 124))  

end_time = time()
print("Spend time: {:f}".format(end_time - start_time))

print("Iterations: ", iterations_count)