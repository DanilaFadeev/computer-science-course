
def linar_generator(A, B, M):
  """Returns a pseudo value generator, based on A, B and M constants.
  Result will be in range: 0 <= Result < M
  """
  x = 0
  while True:
    x = (A * x + B) % M
    yield x

def randomizeArray(dataList = [], A = 11, B = 7):
  """Will mutate dataList argument and sort it's items
  in random way, based on linar_generator function.

  efficiency: O(N)
  """
  randomizer = linar_generator(A, B, len(dataList))

  for i in range(len(dataList)):
    j = next(randomizer)
    dataList[i], dataList[j] = dataList[j], dataList[i]

list_to_randomize = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

randomizeArray(list_to_randomize, A = 5, B = 2)
print(list_to_randomize)
