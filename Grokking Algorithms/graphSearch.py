from collections import deque

graph = {
  "you": ["Egor", "Dasha", "Vitya"],
  "Egor": ["Nastya", "Bogdan", "Nikita", "Liza"],
  "Dasha": ["Nadya", "Egor", "Olya"],
  "Vitya": ["Konstantin", "Tanya"],
  "Konstantin": ["Vitya", "Vlad"]
}

def check_if_seller(name):
  return True if name == "Vlad" else False

def search_in_graph(graph, start_index = "you"):
  queue = deque()
  queue += graph.get(start_index)

  checked = set()
  while queue:
    name = queue.popleft()
    if name not in checked:
      checked.add(name)
      if check_if_seller(name):
        return name
      if graph.get(name):
        queue += graph[name]

saller = search_in_graph(graph, "you")
print(saller)
