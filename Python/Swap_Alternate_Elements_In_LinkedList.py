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
				
	def SwapAlternateElements(self):
			ptr = self.head
			while ptr is not None and ptr.next is not None:
				x = ptr.data
				ptr.data = ptr.next.data
				ptr.next.data = x
				ptr = ptr.next.next
				
llist = LinkedList()

llist.push(9)
llist.push(24)
llist.push(30)
llist.push(15)
llist.push(28)
llist.push(12)
llist.push(1)

print("Linked List before swapping")
llist.printList(llist.head)

print("\n\nLinked List after swapping")
llist.SwapAlternateElements()
llist.printList(llist.head)