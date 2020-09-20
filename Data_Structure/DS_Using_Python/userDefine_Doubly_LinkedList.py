class Node:
	def __init__(self, data):
		self.data = data
		self.prev = None
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
		
	def traverseData(self):
		temp = self.head
		while temp is not None:
			print(temp.data, end = ' ')
			temp = temp.next
			
	def insertFirst(self, data):
					ptr = Node(data)
					if self.head is None:
						ptr.data = data
						ptr.prev = None
						ptr.next = None
						self.head = ptr
					else:
						ptr.data = data
						ptr.prev = None
						ptr.next = self.head
						self.head = ptr
			
	def userDefineData(self):
		print("\nEnter the number of nodes:")
		noOfNode = int(input())
		print("\nEnter the item:")
		for i in range(noOfNode):
		  	 data = int(input())
		  	 self.insertFirst(data)
		
llist = LinkedList()

llist.userDefineData()
print("\nLinked List is")
llist.traverseData()