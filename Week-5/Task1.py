from random import randint

class Task1:

    __m = 0     # size of the matrix
    __n = 0     # the n

    __matrix = []

    def __init__(self, m, n):

        Task1.__m = m
        Task1.__n = n


    def fillMatrix (self):
        """Fill the matrix with random elements from 0 - 9"""
        Task1.__matrix = []

        for i in range(0,Task1.__m):
            Task1.__matrix.append([])
            for j in range(0, Task1.__m):
                Task1.__matrix[i].append(randint(0,9))

    def getContiguousDiagonals(self):
        """Get an array of arrays that contain numbers aligned in parallel to the main diagonal and 
         and don't exceed the length of n"""

        diagonals = []

        # negative index will denote how many rows to skip in the matrix
        firstElementIndx = 0

        iterations = 1

        while (True):

            diagonal = []

            iterator = firstElementIndx

            for row in Task1.__matrix:

                # skip the row if the index is negative
                if (iterator < 0):
                    iterator += 1
                    continue

                if (iterator < len(row)):
                    diagonal.append(row[iterator])
                    # increment the index of the subsequent element in the next row
                    iterator += 1

                else:
                    break

            if (len(diagonal) >= Task1.__n):

                diagonals.append(set(diagonal))

                iterations += 1

                # check if the diagonal has the length
                # of n for the second time
                if (len(diagonal) == Task1.__n
                    and iterations % 2 == 0):

                        break

                if (iterations % 2 == 0):
                    # Decrement the index and make it positive
                    firstElementIndx = - (firstElementIndx - 1)

                else:
                    firstElementIndx = -firstElementIndx


        return diagonals

    def mergeElementsFromDiagonals(self, diagonals):

        output = set()

        for diagonal in diagonals:

            output = output.union(diagonal)

        return output

    def returnSumOfNSmallestElements (self, numbers):

        sum = 0

        for i in range(0, len(numbers)):

            if (i < Task1.__n):
                sum += numbers[i]

            else:
                return sum

