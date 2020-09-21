class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class findPointOfMerge:
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
		
	def pushData(self, data):
		newNode = Node(data)
		if self.head:
			temp = self.head
			while(temp.next):
				temp = temp.next
			temp.next = newNode
		else:
			self.head = newNode

def countNodes(head):
			cnt = 0
			while head is not None:
				cnt += 1
				head = head.next
			return cnt

def merge(head1, head2):
	cnt1 = countNodes(head1)
	cnt2 = countNodes(head2)
	if cnt1 > cnt2:
		for i in range(0,cnt1-cnt2):
			head1 = head1.next
	else:
		for i in range(0,cnt2-cnt1):
			head2 = head2.next
	while(head1 is not head2):
		head1 = head1.next
		head2 = head2.next
	return head1

#Linked list with even number
LL1 = findPointOfMerge()
LL1.pushData(2)
LL1.pushData(4)
LL1.pushData(6)
LL1.pushData(8)
p = LL1.head.next.next.next

print("Linked List 1 is")
LL1.printList()

#Linked list with odd number
LL2 = findPointOfMerge()
LL2.pushData(1)
LL2.pushData(3)
LL2.pushData(5)
LL2.pushData(7)
q = LL2.head.next.next.next

q.next = p

print("\n\nLinked List 2 is")
LL2.printList()

#Merge function
LL3  = findPointOfMerge()
LL3.head = merge(LL1.head, LL2.head)
print('\n')
if LL3.head is not None:
	print("Merge Point is ",LL3.head.data)
else:
	print("Not Merging")