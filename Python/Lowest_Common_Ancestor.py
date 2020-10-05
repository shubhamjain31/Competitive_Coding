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
		
	def lca(self, root, n1, n2):
		if root is None:
			return None
			
		# If both n1 and n2 are smaller than root, then LCA lies in left 
		if(root.data > n1 and root.data > n2):
			return self.lca(root.left, n1, n2) 
			
		# If both n1 and n2 are greater than root, then LCA lies in right  
		if(root.data < n1 and root.data < n2):
			return self.lca(root.right, n1, n2) 
		return root 


root = BinaryTree(1) 
root.left = BinaryTree(2) 
root.right = BinaryTree(3) 
root.left.left = BinaryTree(4) 
root.left.right = BinaryTree(5)

print('Binary tree is:')
root.inOrder(root)

print('\n')
n1 = 3; n2 = 4
t = root.lca(root, n1, n2) 
print("LCA of %d and %d is %d" %(n1, n2 , t.data) )
