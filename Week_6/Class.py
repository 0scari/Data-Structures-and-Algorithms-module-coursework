class Class:

    __id = 1

    def __init__(self):

        self.id     = Class.__id
        Class.__id += 1

    def setName(self, name):

        self.__name = name

    def getName(self):

        return self.__name