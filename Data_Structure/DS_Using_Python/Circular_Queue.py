class Queue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None]*capacity
        self.head = 0
        self.tail = -1
        self.size = 0

    # Add an element
    def enqueue(self, item):
        if self.size == self.capacity:
        	print("Stack is full !!")
        else:
        	self.tail = (self.tail+1)%self.capacity
        	self.queue[self.tail] = item
        	self.size = self.size + 1

    # Remove an element
    def dequeue(self):
        if self.size == 0:
            print("Stack is empty !!")
            return
        else:
        	x = self.queue[self.head]
        	self.head = (self.head+1)%self.capacity
        self.size = self.size - 1
        print("\n\nDelete item is {}".format(x))

    # Display  the queue
    def display(self):
        if self.size == 0:
        	print("Stack is empty !!")
        else:
        	index = self.head
        	for i in range(self.size):
        		print(self.queue[index], end=' ')
        		index = (index+1)%self.capacity

	#Size of queue
    def Queuesize(self):
        return self.size
        
    #find an element in queue
    def search(self, val):
    	for i in range(len(self.queue)):
    		   if self.queue[i] == val:
    		      print("\n\nElement found at {} position.".format(i))
    		      return
    	print("\n\nNo element found")
    	
    #top most element in queue
    def peek(self):
    	print("\nPeek of queue is:", self.queue[0])

q = Queue(5)
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(34)
q.enqueue(5)

print("Queue of elements is:")
q.display()

q.dequeue()
print("\nAfter removing an element:")
q.display()

q.search(34)
q.peek()

sizeOfQueue = q.Queuesize()
print('\nSize of queue is', sizeOfQueue)