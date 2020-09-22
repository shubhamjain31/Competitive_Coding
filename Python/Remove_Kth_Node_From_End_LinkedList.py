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
				
	def removeNthNode(self, key):
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
		
		#remove the nth node from end
		p = self.head
		q = self.head.next
		while q.data != ptr.data and q.next != None:
				p = p.next
				q = q.next
		if q.data == ptr.data:
			p.next = q.next
		if self.head.data == ptr.data:
						self.head = self.head.next
		return
					
llist = LinkedList()

llist.push(92)
llist.push(70)
llist.push(36)
llist.push(28)
llist.push(12)

print("Linked List before removal")
llist.printList(llist.head)

print("\n\nLinked List after removal")
result = llist.removeNthNode(3)
llist.printList(result)