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
				
	def findNthNode(self, key):
		#find the nth node from end
		ptr = self.head
		n = 0
		if ptr is None:
			return
		while(ptr):
		      ptr = ptr.next
		      n += 1
		if n >= key:
			ptr = self.head
			for i in range(0, n-key):
				ptr = ptr.next
		return ptr
					
llist = LinkedList()

llist.push(92)
llist.push(70)
llist.push(36)
llist.push(28)
llist.push(12)

print("Linked List is")
llist.printList(llist.head)

result = llist.findNthNode(3)
print("\n\nKth node from the end is", result.data)