INT_MAX = 4294967296
INT_MIN = -4294967296

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
		
	#function to determine if given binary tree is a BST or not
	def checkBST(self, root, min, max):
		if root is None:
			return 1
			
		if root.data<min or root.data>max:
			return 0
			
		return self.checkBST(root.left, min, root.data) and self.checkBST(root.right, root.data, max)
			
	def isBST(self, root):
		return self.checkBST(root, INT_MIN, INT_MAX)


root = BinaryTree(4) 
root.left = BinaryTree(2) 
root.right = BinaryTree(5) 
root.left.left = BinaryTree(1) 
root.left.right = BinaryTree(3)

print('Binary tree is:')
root.inOrder(root)

print('\n')
if root.isBST(root):
	print("This is a BST" )
else:
	print("This is not a BST" )