class ChessBoard:

    __queens = { 'a': {'cPos': 0, 'iPos': 0},
                 'b': {'cPos': 0, 'iPos': 0},
                 'c': {'cPos': 0, 'iPos': 0},
                 'd': {'cPos': 0, 'iPos': 0},
                 'e': {'cPos': 0, 'iPos': 0},
                 'f': {'cPos': 0, 'iPos': 0},
                 'g': {'cPos': 0, 'iPos': 0},
                 'h': {'cPos': 0, 'iPos': 0}
    }

    __rows   = {
        'a': [1, 2, 3, 4, 5, 6, 7, 8],
        'b': [1, 2, 3, 4, 5, 6, 7, 8],
        'c': [1, 2, 3, 4, 5, 6, 7, 8],
        'd': [1, 2, 3, 4, 5, 6, 7, 8],
        'e': [1, 2, 3, 4, 5, 6, 7, 8],
        'f': [1, 2, 3, 4, 5, 6, 7, 8],
        'g': [1, 2, 3, 4, 5, 6, 7, 8],
        'h': [1, 2, 3, 4, 5, 6, 7, 8]
    }

    ### PUBLIC ###

    def randomlyPositionQueens():

        import random

        for row, columns in ChessBoard.__rows.items():

            if len(ChessBoard.__rows[row]) > 0:

                ChessBoard.__queens[row]['cPos'] = random.choice(ChessBoard.__rows[row])

                ChessBoard.__resetAllRows()

                ChessBoard.__eliminateSquares()

            else:

                return


    def areQueensPositioned():
        return ChessBoard.__queens['h']['cPos'] != 0

    def positionWithBruteForce():

        while ChessBoard.__queens['h']['cPos'] == 0:

                # Position of the last randomly positioned queen
                lastQueensPos = ChessBoard.__findLastQueen()

                ChessBoard.__repositionQueen(lastQueensPos)

                nextRowIndx = chr(ord(list(lastQueensPos.keys())[0]) + 1 )

                ChessBoard.__queens[nextRowIndx]['cPos'] = ChessBoard.__rows[nextRowIndx][0]


    @staticmethod
    def print():

        resString = ""
        counter   = 1

        for row, column in ChessBoard.__queens.items():

            resString += "Queen" + str(counter) + ": " + row + str(column['cPos']) + "\n"

            counter   += 1

        print (resString)

    #################
    ###  PRIVATE  ###
    ### UTILITIES ###
    #################

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
    def __removeThreatenedSquares():
        ChessBoard.__resetAllRows()
        ChessBoard.__eliminateSquares()
        ChessBoard.__reposThreatenedQueens()

    @staticmethod
    def __eliminateSquares():

        # queen's Row and Column
        for qRow, qColumn in ChessBoard.__queens.items():

            remove = False
            depth  = 1 # used to calculate threatened squares in diagonal

            # do if and only if positioned queen encountered
            if qColumn["cPos"] != 0:

                # board's rows and columns
                for bRow, bColumns in ChessBoard.__rows.items():

                    if remove == True:

                        # columns where a queen can be positioned so that it is safe
                        safeColumns = [column for column in ChessBoard.__rows[bRow]
                                            if  column != qColumn["cPos"] + depth
                                            and column != qColumn["cPos"] - depth
                                            and column != qColumn["cPos"]]
                        depth += 1

                        ChessBoard.__rows[bRow] = safeColumns

                    if qRow == bRow:
                        remove = True

            else:
                return

    @staticmethod
    def __reposThreatenedQueens():

        for qRow in ChessBoard.__queens:

            if ChessBoard.__queens[qRow]['cPos'] not in ChessBoard.__rows[qRow]:

                if len(ChessBoard.__rows[qRow]) > 0:

                    ChessBoard.__queens[qRow]['cPos'] = ChessBoard.__rows[qRow][0]

                else:

                    ChessBoard.__queens[qRow]['cPos'] = 0


    @staticmethod
    def __findLastQueen ():

        for row, column in ChessBoard.__queens.items():

            if column["cPos"] == 0:

                return {prevRow: prevCol}

            else:
                prevRow = row
                prevCol = column


    @staticmethod
    def __repositionQueen (queen):

        for qRow, qColumn in queen.items():

            ChessBoard.__resetFollowingQueens(qRow)

            repositioningSuccess = False

            while (not repositioningSuccess):
                # compute next column number and store its index in the variable

                if len(ChessBoard.__rows[qRow]) > 0 and ChessBoard.__queens[qRow]['cPos'] != 0:

                    nextColumnIndx =  (ChessBoard.__rows[qRow].index(qColumn['cPos']) + 1) \
                                      % len(ChessBoard.__rows[qRow])

                    nextRow = chr(ord(qRow) + 1)  # get next alphabetic letter
                    repositioningSuccess = (len(ChessBoard.__rows[nextRow]) > 0) \
                                            and ChessBoard.__rows[qRow][nextColumnIndx] != queen[qRow]['iPos']


                # if the new column number is not the same as before nor the initial
                if repositioningSuccess :
                    ChessBoard.__registerQueensNewPosition(qRow, nextColumnIndx)
                    return
                else:

                    prevRow = chr(ord(qRow) - 1) # get previous alphabetic letter

                    # Reposition previous queen
                    ChessBoard.__repositionQueen({prevRow: ChessBoard.__queens[prevRow]})

            ChessBoard.__registerQueensNewPosition(qRow, nextColumnIndx)

    @staticmethod
    def __registerQueensNewPosition(row, columnIndx):

        # if the queen on this row is moved for the first time
        if ChessBoard.__queens[row]['iPos'] == 0:
            # then save the position where it started the repositioning
            if ChessBoard.__queens[row]['cPos'] in ChessBoard.__rows[row]:
                ChessBoard.__queens[row]['iPos'] = ChessBoard.__queens[row]['cPos']
            else:
                ChessBoard.__queens[row]['iPos'] = ChessBoard.__rows[row][columnIndx]

        ChessBoard.__queens[row]['cPos'] = ChessBoard.__rows[row][columnIndx]

        ChessBoard.__removeThreatenedSquares()

    @staticmethod
    def __resetFollowingQueens(row):
        """Reset the initial positions of queens that follow the specified row"""

        reset = False

        for iRow in ChessBoard.__queens.keys():

            if reset == True:
                ChessBoard.__queens[iRow]["iPos"] = 0

            if row == iRow:
                reset = True
