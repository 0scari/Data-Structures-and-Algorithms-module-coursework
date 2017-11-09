from random import randint

class Task1:
    __m = 0
    __n = 0

    __matrix = []

    def __init__(self, m, n):

        Task1.__m = m
        Task1.__n = n


    def fillMatrix (self):

        Task1.__matrix = []

        for i in range(0,Task1.__m):
            Task1.__matrix.append([])
            for j in range(0, Task1.__m):
                Task1.__matrix[i].append(randint(0,9))

    def getContiguousDiagonals(self):

        diagonals = []
        y = 0

        w = 1

        while (True):

            diagonal = []

            x = y

            for row in Task1.__matrix:

                if (x < 0):
                    x += 1
                    continue

                if (x < len(row)):
                    diagonal.append(row[x])
                    x += 1

                else:
                    break

            if (len(diagonal) >= Task1.__n):

                diagonals.append(diagonal)

                w += 1

                if (w % 2 == 0):
                    y = - (y - 1)

                else:
                    y = -y

                if (len(diagonal) == Task1.__n
                    and w % 2 == 0):

                        break

        return diagonals

    def mergeElementsFromDiagonals(self, diagonals):

        x = []

        for diagonal in diagonals:

            x += [element for element in set(diagonal) if element not in x]

        return x

    def returnSumOfNSmallestElements (self, numbers):

        sum = 0

        for i in range(0, len(numbers)):

            if (i < Task1.__n):
                sum += numbers[i]

        return sum









