class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class List(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, n, x):
        # Not actually perfect: how do we prepend to an existing list?
        if n != None:
            x.next = n.next
            n.next = x
            x.prev = n
            if x.next != None:
                x.next.prev = x
        if self.head == None:
            self.head = x
            x.prev = x.next = None
        elif self.tail == n:
            self.tail = x

    def display(self, length):
        values = []
        n = self.head
        while n != None:
            values.append(str(n.value))
            n = n.next
        print(length, ",".join(values))


if __name__ == '__main__':

    words     = str(input()).split()

    # A dictionary whose keys will be integers representing
    # the lengths of the words and the value will be a list
    # containing the words of the corresponding length
    wordLists = {}

    for word in words:

        if len(word) in wordLists:

            wordList = wordLists[len(word)]

            wordList.insert(wordList.head, Node(word))

        else:

            wordLists[len(word)] = List()

            wordLists[len(word)].insert(None, Node(word))

    for length, wordList in wordLists.items():

        wordList.display(length)

