from queue import Queue

class Stack:
    def __init__(self):
        # Two inbuilt queues
        self.q1 = Queue()
        self.q2 = Queue()
        # Current number of elements in the Stack
        self.curr_size = 0

    def push(self, x):
        # Push x first in empty first queue (q1)
        self.q1.put(x)
        # Increase the size of the Stack\
        self.curr_size += 1

    def pop(self):
        # If no elements are there in first queue (q1)
        if self.q1.empty():
            print("Stack is Empty, thus deletion cannot be performed")
            return -1
        # Leave one element in q1 and push all other elements in second queue (q2)
        while self.q1.qsize() != 1:
            self.q2.put(self.q1.get())
        data = self.q1.get()
        self.curr_size -= 1
        # Swap the names of the two Queues
        self.q = self.q1
        self.q1 = self.q2
        self.q2 = self.q
        return data

    def top(self):
        # If no elements are there in first queue (q1)
        if self.q1.empty():
            print("Stack is Empty, thus no Top Element is present")
            return -1
        while self.q1.qsize() != 1:
            self.q2.put(self.q1.get())
        # Last pushed element to Stack
        temp = self.q1.queue[0]
        # To empty the auxiliary queue after last operation
        self.q1.get()
        # Push last element to second queue(q2)
        self.q2.put(temp)
        # Swap the names of the two Queues
        self.q = self.q1
        self.q1 = self.q2
        self.q2 = self.q
        return temp

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
