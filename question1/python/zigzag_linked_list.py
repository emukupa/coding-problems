class Node:
    data = None
    next = None

    def __init__(self, data):
        self.data = data


class LinkedList:
    head = None

    def __init__(self, data):
        if isinstance(data, list):
            for value in data:
                self.add_node(value)
        else:
            self.add_node(data)

    def add_node(self, value):
        node = Node(value)

        if self.head is None:
            self.head = node

        else:
            current = self.head
            while current.next is not None:
                current = current.next

            current.next = node

    def print_list(self):
        print("head -> ", end="")
        current = self.head
        while current is not None:
            print(str(current.data) + " -> ", end="")
            current = current.next
        print("*null")

    def zigzag(self, flag=True):
        # start with flag True
        # if flag is True then expect current.next.data > current.data
        # else flag is False expect current.next.data < current.data
        # otherwise swap
        current = self.head
        while current.next is not None:
            if flag and current.next.data < current.data:
                current.next.data, current.data = current.data, current.next.data
            elif not flag and current.next.data > current.data:
                current.next.data, current.data = current.data, current.next.data

            flag = not flag
            current = current.next

        self.print_list()


LL = LinkedList([1, 2, 3, 4, 5, 6, 7, 8, 9])

LL.print_list()
LL.zigzag(False)
