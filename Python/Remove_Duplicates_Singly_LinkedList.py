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
				
	def removeDuplicates(self):
		ptr = self.head
		if ptr is None:
			return
		while ptr.next is not None:
			if ptr.data == ptr.next.data:
				temp = ptr.next.next
				ptr.next = temp
			else:
				ptr = ptr.next
			
llist = LinkedList()

llist.push(92)
llist.push(70)
llist.push(70)
llist.push(36)
llist.push(28)
llist.push(12)
llist.push(12)

print("Linked List before duplicate removal")
llist.printList(llist.head)

print("\n\nLinked List after duplicate removal")
result = llist.removeDuplicates()
llist.printList(llist.head)