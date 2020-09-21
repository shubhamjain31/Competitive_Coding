class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

class LinkedList:
	def __init__(self):
		self.head = None
			
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		self.head = newNode
		
	def printList(self, ptr):
		ptr = self.head
		if ptr is None:
			print('List has no element')
			return
		else:
			temp = ptr
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				
	def sortedNodeLinkedList(self, item):
				newNode = Node(item)
				if self.head is None:
					newNode.data = item
					newNode.next = self.head
					newNode.prev = None
					self.head.prev = newNode
					self.head = newNode
				elif self.head.data >= item:
					newNode.data = item
					newNode.next = self.head
					newNode.next.prev = newNode
					self.head = newNode
				else:
					temp = self.head
					while((temp.next is not None) and (temp.next.data < item)):
						temp = temp.next
					newNode.data = item
					newNode.next = temp.next
					if temp.next is not None:
						newNode.next.prev = newNode
					temp.next = newNode
					newNode.prev = temp
				
llist = LinkedList()

llist.push(92)
llist.push(70)
llist.push(36)
llist.push(28)
llist.push(12)

print("Linked List is")
llist.printList(llist.head)

print("\n\nNew Linked List")
llist.sortedNodeLinkedList(3)
llist.sortedNodeLinkedList(156);
llist.sortedNodeLinkedList(23);
llist.printList(llist.head)