class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value

def findCeilingFloor(root_node, k, floor=None, ceil=None):
  if root_node is None:
  	return floor, ceil
  if root_node.value == k:
  	return root_node, root_node
  elif k < root_node.value:
  	return findCeilingFloor(root_node.left, k, floor, root_node)
  else:
  	return findCeilingFloor(root_node.right, k, root_node, ceil)

root = Node(8) 
root.left = Node(4) 
root.right = Node(12) 
root.left.left = Node(2) 
root.left.right = Node(6) 
root.right.left = Node(10) 
root.right.right = Node(14)

for i in range(16):
	floor, ceil = findCeilingFloor(root, i, None, None)
	print(i, end =' ')
	print('Floor is',floor.value if floor else None, end = ' and ')
	print('Ceil is',ceil.value if ceil else None)