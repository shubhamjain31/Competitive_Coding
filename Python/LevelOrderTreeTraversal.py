class BinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	def levelOrderTraversal(self, root):
		if root is None:
			return
			
		queue = []
		
		#Enqueue Root and initialize height
		queue.append(root)

		while(len(queue)>0):
			print(queue[0].data, end=' ')
			temp = queue.pop(0)
			
			#Enqueue left child 
			if temp.left is not None:
				queue.append(temp.left)
				
			#Enqueue right child
			if temp.right is not None:
				queue.append(temp.right)
		
	"""def insertLeft(self, newNode):
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
root.insertRight(12)
root.insertLeft(16)
root.insertRight(20)
root.insertLeft(24)
root.insertRight(28)"""

root = BinaryTree(1) 
root.left = BinaryTree(2) 
root.right = BinaryTree(3) 
root.left.left = BinaryTree(4) 
root.left.right = BinaryTree(5)

print('Level Order Traversal of binary tree is:')
root.levelOrderTraversal(root)