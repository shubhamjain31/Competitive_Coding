class BinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	def inOrder(self, tree):
		if tree is None:
			return
		self.inOrder(tree.left)
		print(tree.data, end=' ')
		self.inOrder(tree.right)
		
	def getHeight(self, root):
	       if root == None:
	       	return -1
	       else:
	       	return 1 + max( self.getHeight(root.left), self.getHeight(root.right) )
		
	def height(self):
		path = 0
		if root is None:
			return
		else:
			while self.right != None:
			     self = self.right
			     path = path +1
			     
			while self.left != None:
			     self = self.left
			     path1 = path1 +1
			     print(path1)
		
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = BinaryTree(newNode)
		else:
			tree = BinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	def insertRight(self, newNode):
		if self.right is None:
			self.right = BinaryTree(newNode)
		else:
			tree = BinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = BinaryTree(4)
root.insertLeft(8)
root.insertRight(5)
root.insertLeft(9)
root.insertRight(25)
root.insertLeft(29)
root.insertRight(45)

print('Inorder Traversal:')
root.inOrder(root)

print('\n')
treeHeight = root.getHeight(root)
print("Height of tree is:",treeHeight)