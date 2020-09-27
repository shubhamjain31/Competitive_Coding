""" Construct below tree
             1
           /   \
          /     \
         2       3
        / \     / \
       4   5   6   7
    """
class PerfectBinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	#Calculate the depth
	def depth(self, node):
		d = 0
		while node is not None:
			d = d+1
			node = node.left
		return d
		
	#Check if the tree is perfect
	def isPerfectBinaryTree(self, tree, d, level):
		if tree is None:
			return True
		if tree.left is None and tree.right is None:
			d  = level+1
			return d
		if tree.left is None or tree.right is None:
			return False
		return self.isPerfectBinaryTree(tree.left, d ,level+1) and self.isPerfectBinaryTree(tree.right, d, level+1)
		
	def isPerfect(self, root):
		d = self.depth(root)
		return self.isPerfectBinaryTree(root, d, 0)
	
	#insert data in left child node
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = PerfectBinaryTree(newNode)
		else:
			tree = PerfectBinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	#insert data in right child node
	def insertRight(self, newNode):
		if self.right is None:
			self.right = PerfectBinaryTree(newNode)
		else:
			tree = PerfectBinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = PerfectBinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(4)
root.insertRight(5)
root.insertLeft(6)
root.insertRight(7)

if(root.isPerfect(root)):
	print("It is a Perfect Binary Tree")
else:
	print("It is not a Perfect Binary Tree")