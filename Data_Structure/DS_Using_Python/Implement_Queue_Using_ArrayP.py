class Queue:
    def __init__(self, capacity):
        self.queue = [None]*capacity
        self.front = -1
        self.rear = -1
        self.capacity = capacity
        
     #Queue is full when size becomes equal to the capacity
    def isFull(self):
    	if self.rear == self.capacity-1:
    		return 1
    	return 0
    	
    #Queue is empty when size is 0 
    def isEmpty(self):
    	if self.front == self.rear:
    		return 1
    	return 0

    # Add an element
    def enqueue(self, item):
        if self.isFull():
        	print('Stack Overflow ! Cannot added new element\n')
        	return
        else:
        	self.rear += 1
        	self.queue[self.rear] = item

    # Remove an element
    def dequeue(self):
        if self.queue[0] is None:
           return None
        return self.queue.pop(0)

    # Display  the queue
    def display(self):
        if self.isEmpty():
        	print("Stack is empty !")
        else:
        	print(self.queue)

	#Size of queue
    def size(self):
        return len(self.queue)
        
    #find an element in queue
    def search(self, val):
    	for i in range(len(self.queue)):
    		   if self.queue[i] == val:
    		      print("\n\nElement found at {} position.".format(i))
    		      return
    	print("\n\nNo element found")
    	
    #top most element in queue
    def peek(self):
    	if self.queue :
    		print("\nPeek of queue is:", self.queue[0])

q = Queue(5)
q.enqueue(51)
q.enqueue(27)
q.enqueue(11)
q.enqueue(63)
q.enqueue(31)
q.enqueue(51)

print("Queue of elements is:")
q.display()

res = q.dequeue()
print("\nAfter removing an element:")
if res == None:
	 print('Element cannot be deleted')

q.display()

q.search(63)
q.peek()

sizeOfQueue = q.size()
print('\nSize of queue is', sizeOfQueue)