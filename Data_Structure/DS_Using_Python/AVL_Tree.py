#Create a tree node
class createNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.height = 1
        
class AVL:
	def __init__(self):
		pass
		
	#Calculate height
	def height(self, root):
		if root is None:
			return 0
		return root.height
		
	#Function to get maximum of two integers
	#def max(self, a, b):
	#	return (a>b) ? a : b
		
	#Right rotate
	def rightRotation(self, y):
		x = y.left
		temp = x.right
		
		#Perform rotation
		x.right = y
		y.left = temp
		
		#Update heights
		y.height = max(self.height(y.left), self.height(y.right) +1)
		x.height = max(self.height(x.left), self.height(x.right) +1)
		return x
		
	#Left rotate
	def leftRotation(self, x):
		y = x.right
		temp = y.left
		
		#Perform rotation
		y.left = x
		x.right = temp
		
		#Update heights
		x.height = max(self.height(x.left), self.height(x.right) +1)
		y.height = max(self.height(y.left), self.height(y.right) +1)
		return y
		
	#Get the balance factor
	def getBalance(self, root):
		if root is None:
			return 0
		return self.height(root.left) - self.height(root.right)
		
	#Print the node in inorder format, when insertion is complete
	def traverse(self, root):
		if root is not None:
			self.traverse(root.left)
			print(root.data,end=' ')
			self.traverse(root.right)
			
	def insertNode(self, root, item):
			if root is None:
				return createNode(item)
			
			if root.data > item:
				root.left = self.insertNode(root.left, item)
			elif root.data < item:
				root.right = self.insertNode(root.right, item)
			else:
				return root
			#Update the balance factor of each node and Balance the tree
			root.height = 1+ max(self.height(root.left), self.height(root.right))
			
			#Get Balance factor of node root
			balance = self.getBalance(root)
			
			#LL case
			if(balance > 1 and item < root.left.data):
				return self.rightRotation(root)
			
			#RR case
			if(balance < -1 and item > root.right.data):
			 return self.leftRotation(root)
			 
			#LR case
			if(balance > 1 and item > root.left.data):
			     root.left = self.leftRotation(root.left)
			     return self.rightRotation(root)
			
			#RL case
			if(balance < -1 and item < root.right.data):
			     root.right = self.rightRotation (root.right)
			     return self.leftRotation(root)
			return root
		   
	#Find the inorder successor
	def getMinValueNode(self, root):
		current = root
		while current.left is not None:
			current = current.left
		return current
		
	#Deleting a node
	def deleteNode(self, root, item):
		#Find the node and delete it
		if(root is None):
		  return root
		if(item < root.data):
		  root.left = self.deleteNode(root.left, item)
		elif(item > root.data):
		  root.right = self.deleteNode(root.right, item)
		else:
			if root.left is None:
			             temp = root.right
			             root = None
			             return temp
			elif root.right is None:
			             temp = root.left
			             root = None
			             return temp
			temp = self.getMinValueNode(root.right)
			root.data = temp.data
			root.right = self.deleteNode(root.right, temp.data)
		if root is None:
			return root
		
		#Update the balance factor of each node and balance the tree
		root.height = 1 + max(self.height(root.left), self.height(root.right))
		balance = self.getBalance(root)
		if(balance > 1 and self.getBalance(root.eft) >= 0):
		  return self.rightRotation(root)
		if(balance > 1 and getBalance(root.left) < 0):
		      root.left = self.leftRotation(root.left)
		      return self.rightRotation(root)
		if(balance < -1 and getBalance(root.right) <= 0):
		  return self.leftRotation(root)
		  
		if(balance < -1 and self.getBalance(root.right) > 0):
		      root.right = self.rightRotation(root.right)
		      return self.leftRotation(root)
		return root
		
		
tree = AVL()
root = None
root = tree.insertNode(root, 60)
root = tree.insertNode(root, 40)
root = tree.insertNode(root, 80)
root = tree.insertNode(root, 140)
root = tree.insertNode(root, 120)
root = tree.insertNode(root, 160)

#printing the tree using inorder
print("Inorder traversal: ")
tree.traverse(root)
   
root = tree.deleteNode(root, 40)
    
print("\n\nAfter deletion: ")
tree.traverse(root)