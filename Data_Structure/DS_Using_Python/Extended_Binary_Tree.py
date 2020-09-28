""" Construct below tree
             1
           /   \
          /     \
         2       3
        / \     /  \
       4   5   6  -1
     /  \  /\ / \
   -1 -1-1 -1  -1
    """
class ExtendedBinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	#Check if the tree is complete
	def traverse(self, tree):
		if tree is not None:
			self.traverse(tree.left)
			print(tree.data,end=' ')
			self.traverse(tree.right)
		else:
			tree = ExtendedBinaryTree(-1)
			print(tree.data,end=' ')
		
	#insert data in left child node
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = ExtendedBinaryTree(newNode)
		else:
			tree = ExtendedBinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	#insert data in right child node
	def insertRight(self, newNode):
		if self.right is None:
			self.right = ExtendedBinaryTree(newNode)
		else:
			tree = ExtendedBinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = ExtendedBinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(4)
#root.insertRight(5)
#root.insertLeft(6)

root.traverse(root)