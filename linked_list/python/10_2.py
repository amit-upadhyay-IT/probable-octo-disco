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


def printME(head):
    print
    while head:
        print head.data,
        head = head.link
    print


def mergeSortedLinkedList(list1,  list2):
    # function should return one pointer which should be head of sorted ll

    temp1, temp2 = list1.head, list2.head

    mainHead = None
    # setting head
    if temp1.data < temp2.data:
        mainHead = temp1
    else:
        mainHead = temp2

    while (temp1 and temp2):
        if temp1.data < temp2.data:
            v = temp1.link
            temp1.link = temp2
            temp2 = v
            temp1 = temp1.link

        else:
            v = temp2.link
            temp2.link = temp1
            temp1 = v
            temp2 = temp2.link

    return mainHead


if __name__ == '__main__':
    linkedList1 = LinkedList(None)
    linkedList1.insertAtBeginning(7)
    linkedList1.insertAtBeginning(5)
    linkedList1.insertAtBeginning(3)

    # linkedList1 = 3->5->7

    linkedList2 = LinkedList(None)
    linkedList2.insertAtBeginning(8)
    linkedList2.insertAtBeginning(6)
    linkedList2.insertAtBeginning(4)

    # linkedList2 = 4->6->8

    mainHead = mergeSortedLinkedList(linkedList1, linkedList2)

    printME(mainHead)


# time complexity = O(n+m), n is size of ll1 and m is size of ll2
# space complexity = OO(1)
