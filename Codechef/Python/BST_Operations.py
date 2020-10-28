class BST:
	def __init__(self, data, pos):
		self.data = data
		self.pos = pos
		self.left = None
		self.right = None
		
def insert(root, item, pos):
	if root is None:
		root =  BST(item, pos)
		print(pos)
	
	elif root.data > item:
		root.left = insert(root.left, item, 2*pos)
	else:
		root.right = insert(root.right, item, (2*pos)+1)
	return root
		
#Find the inorder successor
def minValueNode(root):
	current = root
	while current.left is not None:
		current = current.left
	return current
	
#Deleting a node
def delete(root, item):
	flag = 0
	#Return if the tree is empty
	if root is None:
		return root
	#Find the node to be delete
	if root.data > item:
		root.left = delete(root.left, item)
	elif(root.data < item):
		root.right = delete(root.right, item)
	else:
		
		#If the node is with only one child or no child
		if root.left and root.right:
			print("hey")
			print(root.pos)
			flag = 5
			temp = minValueNode(root.right)
			root.data = temp.data
			root.right = delete(root.right, temp.data)
		else:
			if flag != 5:
				print(root.pos)
			else:
				flag = 3

			if root.left:
				temp = root.left
			else:
				temp = root.right
			return temp
		
	return root
	
root = None		
cases = int(input())
for _ in range(cases):
    ch, b = input().split()
    item = int(b)
    if ch == 'i':
        root = insert(root,item,1)
    if ch == 'd':
        root = delete(root,item)