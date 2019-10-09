class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if len(self.items) == 0:
            print("Stack is Empty, thus element cannot be removed")
            return -1
        return self.items.pop(0)

    def size(self):
        return len(self.items)

    def isEmpty(self):
        return self.items == []


if __name__ == '__main__':
    q = Queue()
    while True:
        print("\nMain Menu:")
        print("1. Insertion to Queue")
        print("2. Deletion from Queue")
        print("3. Size of the Queue")
        print("4. Check whether Stack is empty or not")
        print("5. Quit")
        x = int(input("Enter your choice (1-5): "))
        if x == 1:
            data = int(input("Enter the value to be inserted in Queue: "))
            q.enqueue(data)
        elif x == 2:
            data = q.dequeue()
            if data != -1:
                print("The deleted element is:", data)
        elif x == 3:
            print("The size of the Queue is:", q.size())
        elif x == 4:
            if q.isEmpty() is True:
                print("Queue is Empty")
            else:
                print("Queue is Not Empty")
        elif x == 5:
            break
        else:
            print("Wrong Choice Entered")

