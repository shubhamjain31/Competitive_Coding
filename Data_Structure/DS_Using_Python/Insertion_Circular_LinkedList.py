class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class CircularLinkedList:
	def __init__(self):
		self.head = None
		
	def printList(self):
		if self.head is None:
			print('List has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				if temp == self.head:
					break
	
	def linkedListLength(self):
				currNode = self.head
				length = 0
				while(currNode.next is not None):
					length += 1
					currNode = currNode.next
					if currNode == self.head:
						break
				return length
			
	#Insert a new node at the beginning	
	def push(self, data):
		newNode = Node(data)
		temp = self.head
		newNode.next = self.head
		if self.head is not None:
			while(temp.next != self.head):
				temp = temp.next
			temp.next = newNode
		else:
			newNode.next = newNode
		self.head = newNode
		
	#Inserting at the Beginning of the Linked List
	def insertAtFirst(self, val):
		if self.head is None:
		    print("List is empty")
		    return
		else:
		 	newNode = Node(val)
		 	temp = self.head
		 	while(temp.next != self.head):
		 		temp = temp.next
		 	temp.next = newNode
		 	newNode.next = self.head
		 	self.head = newNode
		 	
	#Inserting at the End of the Linked List
	def insertAtEnd(self, val):
		    if self.head is None:
		    	print("List is empty")
		    	return
		    else:
		    	newNode = Node(val)
		    	temp = self.head
		    	while(temp.next != self.head):
		    		temp = temp.next
		    	newNode.next = temp.next
		    	temp.next = newNode
	
	#Inserting in between two Data Nodes
	def insertAtIndex(self, val, index):
		if index < 0 or index > self.linkedListLength():
			print('\nThe index value is not correct')
			return
		else:
		 	newNode = Node(val)
		 	temp = self.head
		 	i = 0
		 	while(i != index-1):
		 		temp = temp.next
		 		i += 1
		 	newNode.next = temp.next
		 	temp.next = newNode
		 	
	#Searching an element
	def searchElement(self, key):
		temp = self.head
		q = self.head.next
		f = 0
		while(temp.next.next != self.head):
			if temp.data == key:
				f = 1
				break
			temp = temp.next
			q = q.next
			if q.next.data == key:
				f = 1
			if temp.next == self.head:
				break
		if f == 1:
		  print("\n{} is found".format(key));
		else:
		  print("\n{} is not found".format(key));

		 	
cllist = CircularLinkedList()

cllist.push(12) 
cllist.push(56) 
cllist.push(2) 
cllist.push(11) 

print('Linked list before insertion')
cllist.printList()

#cllist.insertAtFirst(62)
#print('\nLinked list after insertion')
#cllist.printList()

#cllist.insertAtEnd(57)
#print('\nLinked list after insertion')
#cllist.printList()

cllist.insertAtIndex(87, 3)
print('\nLinked list after insertion')
cllist.printList()

cllist.searchElement(162)