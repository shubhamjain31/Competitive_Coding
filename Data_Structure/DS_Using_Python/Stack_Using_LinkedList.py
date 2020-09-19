class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class Stack:
	def __init__(self):
		self.head = None
		
	def isEmpty(self):
		if self.head == None:
			return 1
		else:
			return 0
		
	def peek(self):
		if self.isEmpty():
			print('Stack is empty')
			return
		return self.head.data
	
	def traversal(self):
		if self.isEmpty():
			print("Stack Underflow")
		else:
			temp = self.head
			while(temp):
				print(temp.data,end = ' ')
				temp = temp.next
			print()
		
	def push(self, data):
	   if self.head == None:
	   	self.head = Node(data)
	   else:
	   	newNode = Node(data) 
	   	newNode.next = self.head 
	   	self.head = newNode
	
	def pop(self):
	  	if self.isEmpty():
	  		print('Stack is empty')
	  	else:
	  		temp = self.head
	  		self.head = self.head.next
	  		temp.next = None
	  		return temp.data
		
st = Stack()

st.push(52)
st.push(16)
st.push(91)
st.traversal()

#Delete top element of stack
print("\nPopped element is ", st.pop())
st.traversal()

#Print top element of stack  
print("\nTop element is ",st.peek())