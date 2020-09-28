""" Construct below tree
           100
           /   \
         /       \
       60      40
      /  \      /   \
 80  140 120 160
    """
class BST:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
	#Print the node in inorder format, when insertion is complete
	def traverse(self, root):
		if root is not None:
			self.traverse(root.left)
			print(root.data,end=' ')
			self.traverse(root.right)
			
	def insert(self, root, item):
			if root is None:
				return BST(item)
			
			if root.data > item:
				root.left = self.insert(root.left, item)
			else:
				root.right = self.insert(root.right, item)
			return root
			
	#Function to check if a given node exists in a BST or not
	def search(self, root, item):
		while(root is not None):
			#Checking condition and passing right subtree & recusing
			if(item > root.data):
				root = root.right
			
			#Checking condition and passing left subtree & recusing
			elif(item < root.data):
				root = root.left
			else:
				#if the value is found return 1
				return 1
		return 0
		
	#Find the inorder successor
	def minValueNode(self, root):
		current = root
		while current.left is not None:
			current = current.left
		return current
		
	#Deleting a node
	def delete(self, root, item):
		#Return if the tree is empty
		if root is None:
			return root
		#Find the node to be delete
		if root.data > item:
			root.left = self.delete(root.left, item)
		elif(root.data < item):
			root.right = self.delete(root.right, item)
		else:
			
			#If the node is with only one child or no child
			if root.left is None:
				temp = root.right
				return temp
			elif root.right is None:
				temp = root.left
				return temp
			temp = minValueNode(root.right)
			root.data = temp.data
			root.right = delete(root.right, temp.data)
		return root
		
		
root = BST(100)
root.insert(root, 60)
root.insert(root, 40)
root.insert(root, 80)
root.insert(root, 140)
root.insert(root, 120)
root.insert(root, 160)

#printing the tree using inorder
print("Inorder traversal: ")
root.traverse(root)

print('\n\n')
item = 40

#Function to find item in the tree
found = root.search(root, item);
if found:
    print("{} value is found in the tree".format(item))
else:
   print("{} value is not found".format(item))
   
root = root.delete(root, 80)
    
print("\n\nInorder traversal: ")
root.traverse(root)