#
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

		
	def push(self, data):
		new_node = Node(data)
		h = self.head
		if self.head is None:
		       self.head = new_node
		       return
		else:
		           while h.next!=None:
		           	h = h.next
		           h.next = new_node
		
	def printList(self):
		if self.head is None:
			print('List has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				
	def remove_zeros_from_linkedlist(self, head):
	    stack = []
	    curr = head
	    list = []
	    while (curr):
	            if curr.data >= 0:
	            	stack.append(curr)
	            else:
	            	temp = curr
	            	sum = temp.data
	            	flag = False
	            	while (len(stack) != 0):
	            	   temp2 = stack.pop()
	            	   sum += temp2.data
	            	   if sum == 0:
	            	       flag = True
	            	       list = []
	            	       break
	            	   elif sum > 0:
	            	       list.append(temp2)
	            	if not flag:
	            	       if len(list) > 0:
	            	           for i in range(len(list)):
	            	           	stack.append(list.pop())
	            	       stack.append(temp)
	            curr = curr.next
	    return [i.data for i in stack]
				
llist = LinkedList()

llist.push(6)
llist.push(-6)
llist.push(6)
llist.push(8)
llist.push(4)
llist.push(-12)
llist.push(9)
llist.push(8)
llist.push(-8)

print("Linked List is")
llist.printList()

print()
print(llist.remove_zeros_from_linkedlist(llist.head))