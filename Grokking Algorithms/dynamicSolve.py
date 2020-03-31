item_names = ['Water', 'Book', 'Eat', 'Jaket', 'Camera']
item_capacity = [3, 1, 2, 2, 1]
item_cost = [10, 3, 9, 5, 6]

capacity_table = range(1, 7) # 6 is the maximum bag capacity
dynamicTable = [[None for i in range(len(capacity_table))] for i in range(len(item_names))]

for i in range(len(dynamicTable)):
  for j in range(len(dynamicTable[i])):
    if i == 0 and item_capacity[i] <= capacity_table[j]: # simple check for the first item
      dynamicTable[i][j] = item_cost[i]
      continue

    if item_capacity[i] > capacity_table[j]: # not enought space
      dynamicTable[i][j] = dynamicTable[i-1][j]

    elif item_capacity[i] == capacity_table[j]: # fit all the space
      if item_cost[i] >= (dynamicTable[i-1][j] or 0):
        dynamicTable[i][j] = item_cost[i]
      else:
         dynamicTable[i][j] = dynamicTable[i-1][j]

    else: # fit not all the space
      free_space = capacity_table[j] - item_capacity[i]
      free_index = capacity_table.index(free_space)
      free_cost = dynamicTable[i - 1][free_index] or 0

      if free_cost + item_cost[i] > (dynamicTable[i - 1][j] or 0):
        dynamicTable[i][j] = free_cost + item_cost[i]
      else:
        dynamicTable[i][j] = dynamicTable[i - 1][j]

for i in range(len(dynamicTable)):
  table_row = f'{item_names[i]: <8}'
  for j in range(len(dynamicTable)):
    table_row += str(dynamicTable[i][j] or '-') + ' '

  print(table_row)  
