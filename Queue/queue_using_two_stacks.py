class Queue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    # Enqueue an item into the Queue
    def enQueue(self, x):
        # Push item into the first stack (s1)
        self.s1.append(x)

    # Dequeue an item from the Queue
    def deQueue(self):
        # If both stacks are empty, then exit
        if len(self.s1) == 0 and len(self.s2) == 0:
            print("Queue is Empty, thus deletion cannot be performed")
            return -1

        # If second stack (s2) is empty, move elements from first stack (s1) to second stack (s2)
        if len(self.s2) == 0:
            while len(self.s1) != 0:
                self.s2.append(self.s1.pop())
        # Return the top item from second stack (s2)
        return self.s2.pop()

    def sizeQueue(self):
        return len(self.s1)+len(self.s2)


if __name__ == '__main__':
    q = Queue()
    while True:
        print("\nMain Menu:")
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
