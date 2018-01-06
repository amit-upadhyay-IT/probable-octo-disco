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

    l1, l2 = list1.head, list2.head
    temp = None  # used for pointing to the last updated node

    mainHead = None
    # setting head
    if l1.data < l2.data:
        mainHead = l1
        l1 = l1.link  # since we worked upon temp1, so incremening it
    else:
        mainHead = l2
        l2 = l2.link

    temp = mainHead

    while (l1 and l2):
        if l1.data < l2.data:
            temp.link = l1  # joining the smaller node
            l1 = l1.link
            temp = temp.link

        else:
            temp.link = l2
            l2 = l2.link
            temp = temp.link

    # appending the remaining part
    temp.link = l1 if l1 else l2

    return mainHead


if __name__ == '__main__':
    linkedList1 = LinkedList(None)
    linkedList1.insertAtBeginning(18)
    linkedList1.insertAtBeginning(7)
    linkedList1.insertAtBeginning(5)
    linkedList1.insertAtBeginning(3)

    # linkedList1 = 3->5->7

    linkedList2 = LinkedList(None)
    linkedList2.insertAtBeginning(14)
    linkedList2.insertAtBeginning(12)
    linkedList2.insertAtBeginning(8)
    linkedList2.insertAtBeginning(6)
    linkedList2.insertAtBeginning(4)
    linkedList2.insertAtBeginning(2)
    linkedList2.insertAtBeginning(1)

    # linkedList2 = 4->6->8

    mainHead = mergeSortedLinkedList(linkedList1, linkedList2)

    printME(mainHead)


# time complexity = O(n+m), n is size of ll1 and m is size of ll2
# space complexity = OO(1)
