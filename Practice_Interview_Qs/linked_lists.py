# Define Node and LinkedList classes

import sys

class Node:
    def __init__(self, val = 0):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self, head = Node()):
        self.head = head

    def insertFront(self, node = Node()):
        node.next = self.head
        self.head = node

    def insertBack(self, node = Node()):
        n = self.head
        while n.next != None:
            n = n.next
        n.next = node

    def remove(self, val):
        n = self.head
        if n.val == val:
            self.head = n.next
        else:
            while n.next != None and n.next.val != val:
                n = n.next
            if n.next != None:
                if n.next.val == val:
                    n.next = n.next.next

    def show(self):
        if self.head.val == None:
            print("[]")
        else:
            n = self.head
            sys.stdout.write("[")
            while n.next != None:
                sys.stdout.write(str(n.val) + ", ")
                n = n.next
            sys.stdout.write(str(n.val) + "]\n")

# Problem 2.1
def removeDuplicates(ll):
    if ll.head.next == None:
        return ll
    p1 = ll.head
    p2 = ll.head
    while p1.next != None:
        while p2.next != None:
            if p1.val == p2.next.val:
                p2.next = p2.next.next
            else:
                p2 = p2.next
        if p1.next != None:
            p1 = p1.next
            p2 = p1
    return ll

# Problem 2.2
def returnKthToLast(ll,k):
    n = ll.head
    count = 1
    while n.next != None:
        count += 1
        n = n.next
    i = count - k
    if i < 1:
        return None
    n = ll.head
    for j in xrange(i-1):
        n = n.next
    return n.val

# Problem 2.3
def removeNode(n):
    n.val = n.next.val
    n.next = n.next.next

# Problem 2.4
def partition(ll, x):
    ll_lower = LinkedList(Node(0))
    ll_upper = LinkedList(Node(0))
    lower_used = False
    upper_used = False
    curr_node = ll.head 
    lower_tail = None
    while curr_node != None:
        n = curr_node
        if curr_node.next == None:
            curr_node = None
        else:
            curr_node = curr_node.next
        if n.val < x:
            if lower_used == False:
                ll_lower.head.val = n.val
                lower_used = True
                lower_tail = ll_lower.head
            else:
                n.next = ll_lower.head
                ll_lower.head = n
        else:
            if upper_used == False:
                ll_upper.head.val = n.val
                upper_used = True
            else:
                n.next = ll_upper.head
                ll_upper.head = n
    lower_tail.next = ll_upper.head
    return ll_lower


def main():
    
    print("Running test cases for removeDuplicates:")
    ll = LinkedList()
    ll.show()
    removeDuplicates(ll).show()
    ll = LinkedList(Node(1))
    for i in xrange(10):
        ll.insertBack(Node(1))
    ll.show()
    removeDuplicates(ll).show()
    for i in xrange(10):
        ll.insertBack(Node(i))
        ll.insertBack(Node(i))
    ll.show()
    removeDuplicates(ll).show()
    print("")
    print("")

    print("Running test cases for returnKthToLast:")
    ll = LinkedList()
    assert(returnKthToLast(ll,1) == None)
    ll = LinkedList(Node(0))
    for i in xrange(9):
        ll.insertBack(Node(i+1))
    assert(returnKthToLast(ll,6) == 3)
    assert(returnKthToLast(ll,0) == 9)
    assert(returnKthToLast(ll,10) == None)
    assert(returnKthToLast(ll,9) == 0)
    print("all test cases passed!")
    print("")
    print("")

    print("Running test cases for partition:")
    ll = LinkedList(Node(10))
    for i in xrange(10):
        ll.insertBack(Node(10-i))
    ll.show()
    ll = partition(ll,5)
    ll.show()


    return 0

if __name__ == "__main__":
    main()
