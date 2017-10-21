class ChessBoard:

    __queens = { 'a': {'cPos': 1, 'iPos': 0},
                 'b': {'cPos': 3, 'iPos': 0},
                 'c': {'cPos': 5, 'iPos': 0},
                 'd': {'cPos': 7, 'iPos': 0},
                 'e': {'cPos': 2, 'iPos': 0},
                 'f': {'cPos': 4, 'iPos': 0},
                 'g': {'cPos': 6, 'iPos': 0},
                 'h': {'cPos': 0, 'iPos': 0}
    }

    __rows   = {
        'a': [1, 2, 3, 4, 5, 6, 7, 8],
        'b': [3, 4, 5, 6, 7, 8],
        'c': [5, 6, 7, 8],
        'd': [2, 7, 8],
        'e': [2, 4],
        'f': [4],
        'g': [6],
        'h': [],
    }

    a = 4 in [1,2,3]


    ### PUBLIC ###

    def __init__ (self):
        return


    def randomlyPositionQueens():
        return

    def areQueensPositioned():
        return

    def positionWithBruteForce():

        # Position of the last randomly positioned queen
        lastQueensPos = ChessBoard.__findLastQueen()

        ChessBoard.__moveQueenFurther(lastQueensPos)


    def __str__(self):
        return

    #################
    ###  PRIVATE  ###
    ### UTILITIES ###
    #################

    @staticmethod
    def __removeThreatenedSquares():
        ChessBoard.__resetAllRows()
        ChessBoard.__removeDiagonalSquares()
        ChessBoard.__removeVerticalSquares()

    @staticmethod
    def __resetAllRows():
        ChessBoard.__rows = {
            'a': [1, 2, 3, 4, 5, 6, 7, 8],
            'b': [1, 2, 3, 4, 5, 6, 7, 8],
            'c': [1, 2, 3, 4, 5, 6, 7, 8],
            'd': [1, 2, 3, 4, 5, 6, 7, 8],
            'e': [1, 2, 3, 4, 5, 6, 7, 8],
            'f': [1, 2, 3, 4, 5, 6, 7, 8],
            'g': [1, 2, 3, 4, 5, 6, 7, 8],
            'h': [1, 2, 3, 4, 5, 6, 7, 8]
        }

    @staticmethod
    def __removeDiagonalSquares():

        for qRow, qColumn in ChessBoard.__queens.items():

            remove = False
            depth  = 1

            if qColumn["cPos"] != 0:

                for bRow, bColumns in ChessBoard.__rows.items():

                    if remove == True:
                        secureColumns = [column for column in ChessBoard.__rows[bRow]
                                            if column != qColumn["cPos"] + depth and column != qColumn["cPos"] - depth]
                        depth += 1

                        ChessBoard.__rows[bRow] = secureColumns

                    if qRow == bRow:
                        remove = True


            else:
                return

    @staticmethod
    def __removeVerticalSquares():

        for qRow, qColumn in ChessBoard.__queens.items():

            remove = False

            if qColumn["cPos"] != 0:

                for bRow, bColumns in ChessBoard.__rows.items():

                    if remove == True:
                        secureColumns = [column for column in ChessBoard.__rows[bRow] if column != qColumn["cPos"]]
                        ChessBoard.__rows[bRow] = secureColumns

                    if qRow == bRow:
                        remove = True


            else:
                return

    @staticmethod
    def __findLastQueen ():

        for row, column in ChessBoard.__queens.items():

            if column["cPos"] == 0:

                return {prevRow: prevCol}

            else:
                prevRow = row
                prevCol = column


    @staticmethod
    def __moveQueenFurther (queen):

        # # saving queen's position (cPos) before it is moved
        # queensPrevPos = list(queen.values())[0]

        for qRow, qColumn in queen.items():

            ChessBoard.__resetFollowingQueens(qRow)

            # compute next column number and store its index in the variable
            queensColIndx = (ChessBoard.__rows[qRow].index(qColumn['cPos']) + 1) % len(ChessBoard.__rows[qRow])

            # if the new column number is not the same as before nor the initial
            if  ChessBoard.__rows[qRow][queensColIndx] != queen[qRow]['cPos'] \
            and ChessBoard.__rows[qRow][queensColIndx] != queen[qRow]['iPos']:

                ChessBoard.__registerQueensNewPosition(qRow, queensColIndx)

            else:
                prevRow = chr(ord(qRow) - 1) # get previous alphabetic letter
                # Reposition previous queen
                ChessBoard.__moveQueenFurther({prevRow: ChessBoard.__queens[prevRow]})
                ChessBoard.__registerQueensNewPosition(qRow, queensColIndx)


    @staticmethod
    def __registerQueensNewPosition(row, columnIndx):

        # if the queen on this row is moved for the first time
        if ChessBoard.__queens[row]['iPos'] == 0:
            # then save the position where it started
            ChessBoard.__queens[row]['iPos'] = ChessBoard.__queens[row]['cPos']

        ChessBoard.__queens[row]['cPos'] = ChessBoard.__rows[row][columnIndx]

        ChessBoard.__removeDiagonalCells(row)

        ChessBoard.__removeVerticalCells(row)

    @staticmethod
    def __resetFollowingQueens(row):
        """Reset the initial positions of queens that follow the specified row"""

        reset = False

        for iRow in ChessBoard.__queens:

            if reset == True:
                ChessBoard.__queens[iRow]["iPos"] = 0

            if row == iRow:
                reset = True

            # stop if unset queen encountered
            if ChessBoard.__queens[iRow]["iPos"] == 0:
                break

    @staticmethod
    def test():
        # Position of the last randomly positioned queen
        lastQueensPos = ChessBoard.__findLastQueen()

        ChessBoard.__moveQueenFurther(lastQueensPos)

        for qRow, qColumn in ChessBoard.__queens.items():
            print(qRow + ': ' + str(qColumn))

    @staticmethod
    def test2():
        ChessBoard.__resetAllRows()
        ChessBoard.__removeDiagonalSquares()
        ChessBoard.__removeVerticalSquares()
        print(ChessBoard.__rows)


print("Started")


