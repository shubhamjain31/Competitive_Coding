""" Construct below tree
             1
           /   \
          /     \
         2       3
        / \     
       4   5  
    """

class FullBinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
	
	#Check if the tree is full
	def isFullBinaryTree(self, tree):
		if tree is None:
			return True
		if tree.left is None and tree.right is None:
			return True
		if tree.left and tree.right:
			return (self.isFullBinaryTree(tree.left) and self.isFullBinaryTree(tree.right))
		return False
		
	#insert data in left child node
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = FullBinaryTree(newNode)
		else:
			tree = FullBinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	#insert data in right child node
	def insertRight(self, newNode):
		if self.right is None:
			self.right = FullBinaryTree(newNode)
		else:
			tree = FullBinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = FullBinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(4)
root.insertRight(5)

if(root.isFullBinaryTree(root)):
	print("It is a Full Binary Tree")
else:
	print("It is not a Full Binary Tree")