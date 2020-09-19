class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None
		
class DoublyLinkedList:
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
	
	def linkedListLength(self):
				currNode = self.head
				length = 0
				while(currNode.next is not None):
					length += 1
					currNode = currNode.next
				return length
			
	#Insert a new node at the beginning	
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		if self.head is not None:
			self.head.prev = newNode
		self.head = newNode
		
	#Inserting at the Beginning of the Linked List
	def insertAtFirst(self, val):
		if self.head is None:
		    print("List is empty")
		    return
		else:
		 	newNode = Node(val)
		 	#newNode.prev = 
		 	newNode.next = self.head
		 	self.head.prev = newNode
		 	self.head = newNode
		 	
	#Inserting at the End of the Linked List
	def insertAtEnd(self, val):
		    if self.head is None:
		    	print("List is empty")
		    	return
		    else:
		    	newNode = Node(val)
		    	temp = self.head
		    	while(temp.next != None):
		    		temp = temp.next
		    	temp.next = newNode
		    	newNode.prev = temp
	
	#Inserting Item after another Item
	def insertAfterItem(self, prevNode, data):
		if self.head is None:
		    	print("List is empty")
		    	return
		else:
		    	temp = self.head
		    	while temp is not None:
		    	             if temp.data == prevNode:
		    	             	break
		    	             temp = temp.next
		    	if temp is None:
		    		print("\nItem not in the list")
		    	else:
		    	         newNode = Node(data)
		    	         newNode.prev = temp
		    	         newNode.next = temp.next
		    	         if temp.next is not None:
		    	         	temp.next.prev = newNode
		    	         temp.next = newNode
	
	#Inserting Item before another Item
	def insertBeforeItem(self, nextNode, data):
		if self.head is None:
		    	print("List is empty")
		    	return
		else:
		    	temp = self.head
		    	while temp is not None:
		    	             if temp.data == nextNode:
		    	             	break
		    	             temp = temp.next
		    	if temp is None:
		    		print("\nItem not in the list")
		    	else:
		    	         newNode = Node(data)
		    	         newNode.next = temp
		    	         newNode.prev = temp.prev
		    	         if temp.prev is not None:
		    	         	temp.prev.next = newNode
		    	         temp.prev = newNode
		    	         	
	#Searching an element
	def searchElement(self, key):
		temp = self.head
		f = 0
		while(temp.next != None):
			if temp.data == key:
				f = 1
				break
			temp = temp.next
			#q = q.next
		if temp.data == key and temp.next is None:
			f = 1
		if f == 1:
		  print("\n{} is found".format(key));
		else:
		  print("\n{} is not found".format(key));

		 	
dllist = DoublyLinkedList()

dllist.push(12) 
dllist.push(56) 
dllist.push(2) 
dllist.push(11) 

print('Linked list before insertion')
dllist.printList()

#dllist.insertAtFirst(62)
#print('\nLinked list after insertion')
#dllist.printList()

#dllist.insertAtEnd(57)
#print('\nLinked list after insertion')
#dllist.printList()

#dllist.insertAfterItem(12, 3)
#print('\nLinked list after insertion')
#dllist.printList()

dllist.insertBeforeItem(2, 38)
print('\nLinked list after insertion')
dllist.printList()

#dllist.searchElement(56)