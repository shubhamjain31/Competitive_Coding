""" Construct below tree
             1
           /   \
          /     \
         2       3
        / \     
       4   5 
            /
           6
    """
  
# CreateNode creation
class CreateNode:
    def __init__(self, item):
        self.item = item
        self.left = self.right = None
    
    #insert data in left child node
    def insertLeft(self, newNode):
    	if self.left is None:
    		self.left = CreateNode(newNode)
    	else:
    		tree = CreateNode(newNode)
    		tree.left = self.left
    		self.left = tree
    
    #insert data in right child node
    def insertRight(self, newNode):
    	if self.right is None:
    		self.right = CreateNode(newNode)
    	else:
    		tree = CreateNode(newNode)
    		tree.right = self.right
    		self.right = tree

#Calculate height
class CalculateHeight:
    def __init__(self):
        self.CalculateHeight = 0

#Check height balance
def isBalancedBinaryTree(root, CalculateHeight):

    left_height = CalculateHeight
    right_height = CalculateHeight
    if root is None:
        return True
        
    l = isBalancedBinaryTree(root.left, left_height)
    r = isBalancedBinaryTree(root.right, right_height)
    CalculateHeight.CalculateHeight = max(
        left_height.CalculateHeight, right_height.CalculateHeight) + 1

    if abs(left_height.CalculateHeight - right_height.CalculateHeight) <= 1:
        return l and r

    return False
		
CalculateHeight = CalculateHeight()
root = CreateNode(1)
root.insertLeft(2)
root.insertRight(3)
root.insertLeft(4)
root.insertRight(5)
root.insertRight(6)
root.insertRight(6)

if(isBalancedBinaryTree(root,CalculateHeight)):
	print("It is a Balanced Binary Tree")
else:
	print("It is not a Balanced Binary Tree")