infinity = float('inf')

graph = {
  'start': {
    'a': 6,
    'b': 2
  },
  'a': {
    'fin': 1
  },
  'b': {
    'a': 3,
    'fin': 5
  },
  'fin': {}
}

costs = {
  'a': 6,
  'b': 2,
  'fin': infinity
}

parents = {
  'a': 'start',
  'b': 'start',
  'fin': None
}

processed = []

def find_lowest_cost_node(costs, processed):
  min_cost = infinity
  node_key = None

  for key, value in costs.items():
    if key not in processed and value < infinity:
      min_cost = value
      node_key = key

  return node_key


node_key = find_lowest_cost_node(costs, processed)
while node_key is not None:
  cost = costs[node_key]
  neighbors = graph[node_key]

  for key in neighbors.keys():
    if cost + neighbors[key] < costs[key]:
      costs[key] = neighbors[key] + cost
      parents[key] = node_key

  processed.append(node_key)
  node_key = find_lowest_cost_node(costs, processed)

def print_path(parents, start = 'start', fin = 'fin'):
  def get_next_node_key(current_key):
    next_node_key = None
    for key, value in parents.items():
      if value == current_key:
        next_node_key = key
    return next_node_key

  path = []
  next_key = get_next_node_key(start)
  while next_key:
    path.append(next_key)
    next_key = get_next_node_key(next_key)   

  print(" -> ".join(path))

print_path(parents)      
