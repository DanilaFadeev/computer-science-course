# the result have to include N! items

items = ['A', 'B', 'C', 'D']
results = []

def generate(items, prefix = ''):
  global results

  if len(items) == 1:
    results.append(prefix + items[0])
    return

  for i in range(len(items)):
    if prefix.find(items[i]) == -1:
      free_items = items.copy()
      free_items.remove(items[i])

      generate(free_items, prefix=prefix + items[i])


res = generate(items)
print(results)
print("Total items: ", len(results))
