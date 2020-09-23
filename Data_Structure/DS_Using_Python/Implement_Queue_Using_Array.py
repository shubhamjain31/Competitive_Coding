class Queue:
    def __init__(self):
        self.queue = []

    # Add an element
    def enqueue(self, item):
        self.queue.append(item)

    # Remove an element
    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    # Display  the queue
    def display(self):
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
    	print("\nPeek of queue is:", self.queue[0])

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)

print("Queue of elements is:")
q.display()

q.dequeue()

print("\nAfter removing an element:")
q.display()

q.search(3)
q.peek()

sizeOfQueue = q.size()
print('\nSize of queue is', sizeOfQueue)