class Stack:
	#Constructor to initialize stack
	def __init__(self, size):
		self.stack = [None]*size
		self.capacity = size
		self.top = -1
	
	def size(self):
		return self.top+1
	
	#Function to check if the stack is empty or not
	def isEmpty(self):
		return self.size() == 0
	
	#Function to check if the stack is full or not
	def isFull(self):
		return self.size() == self.capacity
	
	#Function to return top element in a stack
	def peek(self):
		return self.stack[self.top]
	
	#Function to add an element x in the stack
	def push(self, data):
		if self.isFull():
			print('Stack Overflow !')
			return
		else:
			self.top = self.top + 1
			self.stack[self.top] = data
	
	#Function to pop top element from the stack
	def pop(self):
		if self.isEmpty():
			print('Stack Underflow !')
			return
		else:
			top = self.stack[self.top]
			self.top -= 1
		return top
		
	#Traversing the stack
	def traversal(self):
		while not self.isEmpty():
			print(st.pop(), end = ' ')
		
st = Stack(6)

st.push(6)
st.push(56)
st.push(97)
st.push(24)
st.push(60)
st.pop()
st.pop()
st.push(66)
st.push(7)
	
print('\nTop element of stack is ', st.peek())
print('Stack size is ', st.size())

# check if stack is empty
if st.isEmpty():
	print("Stack is empty")
else:
	print("Stack is not empty")

# check if stack is full
if st.isFull():
	print("Stack is full")
else:
	print("Stack is not full")
	
st.traversal()