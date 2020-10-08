#Mirror Tree or Invert Tree

#-----------1st Way------------
class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value
  def preorder(self):
    print(self.value, end=' ')
    if self.left: self.left.preorder()
    if self.right: self.right.preorder()

#function to swap left subtree with right subtree
def swap(node):
  if node is None:
  	return
  temp = node.left
  node.left = node.right
  node.right = temp

#Function to invert given binary Tree using preorder traversal
def invert(root):
	if root is  None:
		return
	swap(root)
	invert(root.left)
	invert(root.right)

root = Node('a') 
root.left = Node('b') 
root.right = Node('c') 
root.left.left = Node('d') 
root.left.right = Node('e') 
root.right.left = Node('f') 

root.preorder()
# a b d e c f 
print("\n")
invert(root)
root.preorder()

#-----------2nd Way------------
'''class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value
  def preorder(self):
    print(self.value, end=' ')
    if self.left: self.left.preorder()
    if self.right: self.right.preorder()

#Function to swp and invert given binary Tree using preorder traversal
def invert(root):
	if root is  None:
		return
	temp = root
	invert(root.left)
	invert(root.right)
	temp = root.left
	root.left = root.right
	root.right = temp

root = Node('a') 
root.left = Node('b') 
root.right = Node('c') 
root.left.left = Node('d') 
root.left.right = Node('e')
root.right.left = Node('f') 

root.preorder()
# a b d e c f 
print("\n")
invert(root)
root.preorder()'''