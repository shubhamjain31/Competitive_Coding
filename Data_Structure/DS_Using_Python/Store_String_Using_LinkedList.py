class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class LinkedList:
	def __init__(self):
		self.head = None
		
	def display(self, ptr):
		while ptr is not None:
			print(ptr.data,end=' ')
			ptr = ptr.next
		
	def createNode(self, data):
		ptr = Node(data)
		ptr.data = data
		ptr.next = self.head
		return ptr
		
	def stringToLinkedList(self, s):
		ptr = self.head
		ptr = self.createNode(s[0])
		curr = ptr
		
		for i in range(1, len(s)):
			curr.next = self.createNode(s[i])
			curr = curr.next
		return ptr
		
llist = LinkedList()
print("Enter a string:")
s = input()

d = llist.stringToLinkedList(s)
print()
print("Linked List is")
llist.display(d)