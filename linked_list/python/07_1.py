class Node:
    data = 0
    link = None

    def __init__(self, data):
        self.data = data
        self.link = None


class LinkedList:
    head = None

    def __init__(self, head):
        self.head = head

    def insertAtBeginning(self, data):
        # need new node
        newNode = Node(data)
        newNode.link = self.head
        self.head = newNode

    def printThisLL(self):
        print
        temp = self.head
        while (temp is not None):
            print temp.data,
            temp = temp.link
        print

    def printLL(self, head):
        print
        temp = head
        while (temp is not None):
            print temp.data,
            temp = temp.link
        print

    def alternatingSplit(self):
        # checking if linked list has one element or not element, because then we can't split it
        if not self.head or not self.head.link:
            return
        p = self.head
        q = self.head.link
        temp = None
        while (self.head is not None):
            temp = self.head.link
            self.head.link = temp.link if temp else temp
            self.head = temp

        # now p and q are separate linked list
        self.printLL(p)
        self.printLL(q)


if __name__ == '__main__':

    linkedList = LinkedList(None)
    linkedList.insertAtBeginning(5)
    linkedList.insertAtBeginning(15)
    linkedList.insertAtBeginning(25)
    linkedList.insertAtBeginning(35)

    linkedList.printThisLL()

    linkedList.alternatingSplit()
