class Queue:
    def __init__(self):
        self.s = []

    # Enqueue an item into the Queue
    def enQueue(self, x):
        # Push item into the stack (s)
        self.s.append(x)

    # Dequeue an item from the Queue
    def deQueue(self):
        # If first stack (s1) is empty, then exit
        if len(self.s) == 0:
            print("Queue is Empty, thus deletion cannot be performed")
            return -1
        # Pop an item from the stack
        x = self.s.pop()
        # If the stack becomes empty, then return the popped item
        if len(self.s) == 0:
            return x
        # Recursive call of Dequeue Function
        item = self.deQueue()
        # Push popped item back to the stack
        self.s.append(x)
        # Return the result of deQueue() function call
        return item

    # Current Size of the Queue
    def sizeQueue(self):
        return len(self.s)


if __name__ == '__main__':
    q = Queue()
    while True:
        print("Main Menu:")
        print("1. Insertion to Queue")
        print("2. Deletion from Queue")
        print("3. Size of Queue")
        print("4. Quit")
        x = int(input("Enter your choice (1-4): "))
        if x == 1:
            data = int(input("Enter the value to be inserted in Queue: "))
            q.enQueue(data)
        elif x == 2:
            data = q.deQueue()
            if data != -1:
                print("The deleted element is:", data)
        elif x == 3:
            print("The size of the Queue is:", q.sizeQueue())
        elif x == 4:
            break
        else:
            print("Wrong Choice Entered")
