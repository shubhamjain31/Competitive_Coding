""" Construct below tree

             1 
            / 
          2 
         / 
        3     """

class SkewedBinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	#Check if the tree is skewed
	def isSkewedBT(self, tree):
		#check if node is None or is a leaf node
		if(tree is not None or (tree.left is None and tree.right is None)):
			return 1
			
			#check if node has two children 
			if tree.left and tree.right:
				return 0
			if tree.left:
				return isSkewedBT(tree.left)
			return isSkewedBT(tree.right)
		
	#insert data in left child node
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = SkewedBinaryTree(newNode)
		else:
			tree = SkewedBinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	#insert data in right child node
	def insertRight(self, newNode):
		if self.right is None:
			self.right = SkewedBinaryTree(newNode)
		else:
			tree = SkewedBinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = SkewedBinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(8)
root.insertRight(6)
#root.insertLeft(root,4)

print(root.isSkewedBT(root))