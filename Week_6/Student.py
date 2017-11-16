class Student:
    __id = 1

    def __init__(self):

        self.id = Student.__id
        Student.__id += 1

    def setDetails(self, name, dob, address, enrolmentDate, status):
        pass

    def changeCurrentClass(self, newClass):
        self.currentClass = newClass