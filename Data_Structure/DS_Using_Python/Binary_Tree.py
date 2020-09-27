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
		
	def preOrder(self, tree):
		if tree is None:
			return
		print(tree.data, end=' ')
		self.inOrder(tree.left)
		self.inOrder(tree.right)
		
	def postOrder(self, tree):
		if tree is None:
			return
		self.inOrder(tree.left)
		self.inOrder(tree.right)
		print(tree.data, end=' ')
		
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
root.insertRight(85)
root.insertLeft(29)
root.insertRight(45)


print('Inorder Traversal:')
root.inOrder(root)

print('\n')
print('Preorder Traversal:')
root.preOrder(root)

print('\n')
print('Postorder Traversal:')
root.postOrder(root)