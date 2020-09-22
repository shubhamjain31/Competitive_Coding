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
				
def MergeLinkedList(head1, head2):
		dummy = Node(None)
		tail = dummy
		while True:
				if head1 is None:
					tail.next = head2
					break
				elif head2 is None:
					tail.next = head1
					break
				if head1.data <= head2.data:
				        tail.next = head1
				        head1 = head1.next
				else:
				        tail.next = head2
				        head2 = head2.next
				tail = tail.next
		return dummy.next
				
LL1 = LinkedList()
LL1.push(33)
LL1.push(24)
LL1.push(20)
LL1.push(12)
LL1.push(6)
LL1.push(4)
LL1.push(2)

print()

LL2 = LinkedList()
LL2.push(34)
LL2.push(27)
LL2.push(22)
LL2.push(15)
LL2.push(8)
LL2.push(5)
LL2.push(3)

print("Linked List 1 is:")
LL1.printList(LL1.head)

print("\n\nLinked List 2 is:")
LL2.printList(LL2.head)

LL3 = LinkedList()
print('\n')

print("Merged Linked List is: ")
LL3.head = MergeLinkedList(LL1.head, LL2.head)
LL3.printList(LL3.head)