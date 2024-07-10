class Node:
    def __init__(self, data=None, next=None):
        self.data=data
        self.next=next        

class LinkedList:
    def __init__(self):
        self.head=None
        self.next=None
    
    def is_empty(self):
        return self.head == None


    # Insertion Operations
    def insert_at_start(self, data):
        newNode = Node(data)

        newNode.next = self.head
        self.head = newNode

    def insert_at_end(self, data):
        newNode = Node(data)

        current = self.head

        if not self.is_empty():
            while current.next != None:
                current = current.next
    
            current.next = newNode
            return

        self.insert_at_start(data)

    def insert_after_value(self, value, data):            
        newNode = Node(data)
        current = self.head

        if not self.is_empty():
            
            while current and  current.data != value:
                current = current.next
            
            if current:
                newNode.next = current.next
                current.next = newNode
            else:
                return 'Value Not Found'

    def insert_after_index(self, index, data):
        ind = 0
        current = self.head
        new_node = Node(data)
        if not self.is_empty():
            while ind != index:
                ind += 1
                current = current.next

            new_node.next = current.next
            current.next = new_node

    # Deletion Operation

    def delete_at_start(self):
        if self.is_empty():
            return "Cannot Delete - Empty List"

        self.head = self.head.next

    def delete_at_last(self):
        if self.is_empty():
            return "Cannot Delete - Empty List"

        current = self.head
        if current.next == None:
            return self.delete_at_start()

        while current.next != None and current.next.next != None:
            current = current.next

        current.next = None

    def delete_value(self, value):
        if self.is_empty():
            return None

        current = self.head

        if self.head.data == value:
            return self.delete_at_start()

        while current.next and current.next.data != value:
            
            current = current.next
            
        if current.next == None:
                return 'Value Not Found in List'
            
        current.next = current.next.next

        

    def delete_at_index(self, index):

        if index < 0:
             return ("Index cannot be negative")

        if self.is_empty():
            return 'Empty list'

        if index == 0: return self.delete_at_start()

        current = self.head
        previous = None

        ind = 0
        while current and ind < index:
            if current.next == None:
                return 'Index Error'

            previous = current
            current = current.next
            
            ind += 1

        if current == None: return 'Index Error'

        if current.next == None:
            previous.next = None
            return

        previous.next = current.next
    


    # Searching (by value)
    def search(self, value):
        current = self.head
        index = 0
        
        while current != None:
            if current.data == value:
                return f'{value} found on index {index}'
            current = current.next
            index += 1            
        return -1
            
    # Traversal
    def traverse(self):
        current = self.head

        ans = ''
        while current != None:
            ans = ans + (str(current.data) + " -> ")
            current = current.next

        return ans[:-4]

    def __iter__(self):
        return LinkedListIterator(self.head)

    

        
        
class LinkedListIterator:
    def __init__(self, head):
        self.current = head
    def __iter__(self):
        return self
    def __next__(self):
        if not self.current:
            raise StopIteration
        data = self.current.data
        self.current = self.current.next
        return data