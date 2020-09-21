#Solved this by Floyd's Cycle-Finding Algorithm or Fast and Slow Pointer method

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
			
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		self.head = newNode
		
	def printList(self):
		if self.head is None:
			print('List has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				
	def detectLoopInLinkedList(self):
				fast = self.head
				slow = self.head
				while(slow and fast and fast.next):
					slow = slow.next
					fast = fast.next.next
					if slow == fast:
						print("\n\nLinked list contains a loop\n")
						return
				print("\n\nNo loop in linked list\n")
				
llist = LinkedList()

llist.push(92)
llist.push(30)
llist.push(36)
llist.push(2)
llist.push(12)

print("Linked List is\n")
llist.printList()

#Create loop in linked list . Set next pointer of last node to second node from head
llist.head.next.next.next.next = llist.head.next

llist.detectLoopInLinkedList()