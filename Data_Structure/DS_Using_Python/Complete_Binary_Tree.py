""" Construct below tree
             1
           /   \
          /     \
         2       3
        / \     / \
       4   5   6   7
    """
class CompleteBinaryTree:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	#Count the number of nodes 
	def countNumNodes(self, root):
		if root is None:
			return 0
		return (1+self.countNumNodes(root.left) + self.countNumNodes(root.right))
		
	#Check if the tree is complete
	def isCompleteBinaryTree(self, tree, index ,countNumNodes):
		if tree is None:
			return True
		if index >= countNumNodes:
			return False
		return self.isCompleteBinaryTree(tree.left, 2*index+1, countNumNodes) and self.isCompleteBinaryTree(tree.right, 2*index+2, countNumNodes)
		
	#insert data in left child node
	def insertLeft(self, newNode):
		if self.left is None:
			self.left = CompleteBinaryTree(newNode)
		else:
			tree = CompleteBinaryTree(newNode)
			tree.left = self.left
			self.left = tree
		
	#insert data in right child node
	def insertRight(self, newNode):
		if self.right is None:
			self.right = CompleteBinaryTree(newNode)
		else:
			tree = CompleteBinaryTree(newNode)
			tree.right = self.right
			self.right = tree
		
root = CompleteBinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(4)
#root.insertRight(5)
#root.insertLeft(6)
#root.insertRight(7)

nodeCount = root.countNumNodes(root)
index = 0

if(root.isCompleteBinaryTree(root, index, nodeCount)):
	print("It is a Complete Binary Tree")
else:
	print("It is not a Complete Binary Tree")