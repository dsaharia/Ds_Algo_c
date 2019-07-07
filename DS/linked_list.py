class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_back(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            next_node = self.head
            while next_node.next:
                next_node = next_node.next
            next_node.next = new_node
    def insert_front(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            new_node.next = self.head
            self.head = new_node
    def print_list(self):
        next_node = self.head
        while next_node:
            print(next_node.data, end=' --> ')
            next_node = next_node.next
        print('\n')


def main():
    linked_list = LinkedList()
    while True:
            choice = int(input("1. Insert data at end.\n2. Insert data at front.\n3. Print list\n4. Exit\n"))
            if choice == 1:
                data = int(input("Enter the data:"))
                linked_list.insert_back(data)
            elif choice == 2:
                data = int(input("Enter the data:"))
                linked_list.insert_front(data)
            elif choice == 3:
                linked_list.print_list()
            elif choice == 4:
                break

if __name__ == '__main__':
    main()