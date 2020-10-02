class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class LinkedList:
	def __init__(self):
		self.head = None
		
	def insert(self, item):
		newNode = Node(item)
		newNode.data = item
		newNode.next = self.head
		self.head = newNode
		
	def compareLinkedList(self,llist2):
		head1 = self.head
		head2 = llist2.head
		f = 0
		while head1 is not head2:
			if head1.data != head2.data:
				f = 1
			head1 = head1.next
			head2 = head2.next
		return f
		
	def linkedListPrint(self):
		while self.head is not None:
			print(self.head.data, end=' ')
			self.head = self.head.next
		
llist1 = LinkedList()
llist2 = LinkedList()

llist1.insert(1)
llist1.insert(51)
llist1.insert(36)

llist2.insert(1)
llist2.insert(51)
llist2.insert(36)

s = llist1.compareLinkedList(llist2)
if s>0:
	print("Both linked lists are not identical")
else:
	print("Both linked lists are identical")