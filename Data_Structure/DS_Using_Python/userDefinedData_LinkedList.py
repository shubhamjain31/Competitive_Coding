class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class SinglyLinkedList:
	def __init__(self):
		self.head = None
		
	def printList(self):
		if self.head is None:
			print('\nList has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				
	def size(self):
		if self.head == None:
			return 0 
		else:
			temp = self.head
			c = 0
			while(temp is not None):
				c += 1
				temp = temp.next
			return c
	
	def insert(self, data):
		newNode = Node(data)
		newNode.next = self.head
		self.head = newNode
			
	def userDefineInsert(self):
	       nums = int(input("How many nodes do you want to create: "))
	       if nums == 0:
	       	return
	       for i in range(nums):
	           value = int(input("Enter the value for the node:"))
	           self.insert(value)
	     	
llist = SinglyLinkedList()

llist.userDefineInsert()
print('\nLinked list is')
llist.printList()

if llist.size() == 0:
	print('\nNo element found')
else:
	print('\n\nTotal number of elements in linked list is',llist.size())