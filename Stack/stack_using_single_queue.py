from queue import Queue

class Stack:
    def __init__(self):
        # Two inbuilt queues
        self.q = Queue()
        # Current number of elements in the Stack
        self.curr_size = 0

    def push(self, x):
        # Get previous size of queue
        s = self.q.qsize()
        # Push current element to queue
        self.q.put(x)
        # Dequeue all previous elements and Enqueue them after current element
        for _ in range(s):
            # This will move element from front of queue to the rear of queue
            self.q.put(self.q.get())
        self.curr_size += 1

    def pop(self):
        # If no elements are there in queue (q)
        if self.q.empty():
            print("Stack is Empty, thus deletion cannot be performed")
            return -1
        self.curr_size -= 1
        return self.q.get()

    def top(self):
        if self.q.empty():
            print("Stack is Empty, thus no Top Element is present")
            return -1
        return self.q.queue[0]

    def sizeStack(self):
        return self.curr_size


if __name__ == '__main__':
    s = Stack()
    while True:
        print("\nMain Menu:")
        print("1. Insertion to Stack (Push Operation)")
        print("2. Deletion from Stack (Pop Operation)")
        print("3. Top Element of the Stack")
        print("4. Size of the Stack")
        print("5. Quit")
        x = int(input("Enter your choice (1-5): "))
        if x == 1:
            data = int(input("Enter the value to be inserted in Stack: "))
            s.push(data)
        elif x == 2:
            data = s.pop()
            if data != -1:
                print("The deleted element is:", data)
        elif x == 3:
            data = s.top()
            if data != -1:
                print("The top element in stack is:", data)
        elif x == 4:
            print("The size of the Stack is:", s.sizeStack())
        elif x == 5:
            break
        else:
            print("Wrong Choice Entered")
