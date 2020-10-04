class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):

        self.items.append(item)

    def pop(self):
        if len(self.items) == 0:
            print("Stack is Empty, thus element cannot be popped")
            return -1
        return self.items.pop()

    def peek(self):
        if len(self.items) == 0:
            print("Stack is Empty, thus no TOP Element present")
            return -1
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

    def isEmpty(self):
        return self.items == []


if __name__ == '__main__':
    s = Stack()
    while True:
        print("\nMain Menu:")
        print("1. Insertion to Stack (Push Operation)")
        print("2. Deletion from Stack (Pop Operation)")
        print("3. Top Element of the Stack")
        print("4. Size of the Stack")
        print("5. Check whether Stack is empty or not")
        print("6. Quit")
        x = int(input("Enter your choice (1-6): "))
        if x == 1:
            data = int(input("Enter the value to be inserted in Stack: "))
            s.push(data)
        elif x == 2:
            data = s.pop()
            if data != -1:
                print("The deleted element is:", data)
        elif x == 3:
            data = s.peek()
            if data != -1:
                print("The top element present in stack is:", data)
        elif x == 4:
            print("The size of the Stack is:", s.size())
        elif x == 5:
            if s.isEmpty() is True:
                print("Stack is Empty")
            else:
                print("Stack is Not Empty")
        elif x == 6:
            break
        else:
            print("Wrong Choice Entered")
