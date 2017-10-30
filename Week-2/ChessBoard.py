class ChessBoard:

    # cPos: current position
    # iPos: the initial position of a queen when repositioning starts
    __queens = { 'a': {'cPos': 0, 'iPos': 0},
                 'b': {'cPos': 0, 'iPos': 0},
                 'c': {'cPos': 0, 'iPos': 0},
                 'd': {'cPos': 0, 'iPos': 0},
                 'e': {'cPos': 0, 'iPos': 0},
                 'f': {'cPos': 0, 'iPos': 0},
                 'g': {'cPos': 0, 'iPos': 0},
                 'h': {'cPos': 0, 'iPos': 0}
    }

    # Board rows, and the square numbers not threatened by the queens
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

    ##############
    ### PUBLIC ###

    def randomlyPositionQueens():
        """Randomly pick an entry from the __rows array for each queen"""

        import random

        for row, columns in ChessBoard.__rows.items():

            if len(ChessBoard.__rows[row]) > 0:

                ChessBoard.__queens[row]['cPos'] = random.choice(ChessBoard.__rows[row])

                ChessBoard.__resetAllSquares()

                ChessBoard.__eliminateSquares()

            else:

                return


    def areQueensPositioned():
        return ChessBoard.__queens['h']['cPos'] != 0

    def positionWithBruteForce():
        """This method repositions the queens until the last queen has been given a position"""

        # at least the 1st queen must be postioned
        if ChessBoard.__queens['a']['cPos'] not in range(1, 9):
            ChessBoard.__queens['h']['cPos'] = " Queens set incorrectly"

        while ChessBoard.__queens['h']['cPos'] == 0:

                # {Row: column} of the last randomly positioned queen
                lastQueensPos = ChessBoard.__findLastQueen()

                # Recursive quenns' index shifting until the row after the last queen has a place to put a queen
                ChessBoard.__repositionQueen(lastQueensPos)

                nextRowIndx = chr(ord(list(lastQueensPos.keys())[0]) + 1 )

                # Assign the first square to the queen's position with the respective row
                ChessBoard.__queens[nextRowIndx]['cPos'] = ChessBoard.__rows[nextRowIndx][0]


    @staticmethod
    def printQueens():

        resString = ""
        counter   = 1

        for row, column in ChessBoard.__queens.items():

            resString += "Queen" + str(counter) + ": " + row + str(column['cPos']) + "\n"

            counter   += 1

        print (resString)

    ### SETTERS & GETTERS ###

    @staticmethod
    def getQueens ():

        queens = {}

        for row, column in ChessBoard.__queens.items():

            queens[row] = column['cPos']

        return queens

    @staticmethod
    def setQueens(queens):

        if not isinstance(queens, dict):
            return []

        # rows that were set
        output = []

        for row in queens:

            if row in ChessBoard.__queens.keys() \
               and queens[row] in range(9):

                ChessBoard.__queens[row]['cPos'] = queens[row]

                ChessBoard.__queens[row]['iPos'] = 0

                output.append(row)

        ChessBoard.__eliminateSquares()

        return output

    @staticmethod
    def getRows():
        return ChessBoard.__rows

    @staticmethod
    def setRows(rows):
        ChessBoard.__rows = rows

    #################
    ###  PRIVATE  ###

    @staticmethod
    def __resetAllSquares():
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
        ChessBoard.__resetAllSquares()
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

                # if the row has available square assign the first one to the queen's position
                if len(ChessBoard.__rows[qRow]) > 0:

                    ChessBoard.__queens[qRow]['cPos'] = ChessBoard.__rows[qRow][0]

                # else remove from the board
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
        """Recursive function to reposition a queen until the next row has available squares.
           If during repositioning of a single queen it finds itself on the same square twice,
           work with the queen a row above.
        """
        for qRow, qColumn in queen.items():

            ChessBoard.__resetIPosOfFollowingQueens(qRow)

            repositioningSuccess = False

            while (not repositioningSuccess):

                # if row has available squares
                if len(ChessBoard.__rows[qRow]) > 0:

                    # get the index of the current square number, add 1, perform modulo with the total length
                    nextColumnIndx        = (ChessBoard.__rows[qRow].index(qColumn['cPos']) + 1) \
                                            % len(ChessBoard.__rows[qRow])

                    nextRow               = chr(ord(qRow) + 1)  # get next alphabetic letter

                    # whether or not next row would have a free square
                    # and queen has returned to the initial position
                    repositioningSuccess  = ChessBoard.__doesNextRowHasSquare(nextRow, ChessBoard.__rows[qRow][nextColumnIndx]) \
                                            and ChessBoard.__rows[qRow][nextColumnIndx] != queen[qRow]['iPos']

                if repositioningSuccess :
                    ChessBoard.__registerQueensNewPosition(qRow, nextColumnIndx)
                    return

                else:

                    prevRow = chr(ord(qRow) - 1) # get previous alphabetic letter

                    # Reposition previous queen
                    ChessBoard.__repositionQueen({prevRow: ChessBoard.__queens[prevRow]})

    @staticmethod
    def __doesNextRowHasSquare(row, newQueensColumn):
        """Imitate queens positioning with the data in the parameters 
           and return whether or not the following row would have
           available squares under these settings."""

        prevRow = chr(ord(row) - 1)  # get previous alphabetic letter

        rows    = ChessBoard.__rows.copy()

        currentQueensColumn                  = ChessBoard.__queens[prevRow]['cPos']

        ChessBoard.__queens[prevRow]['cPos'] = newQueensColumn

        ChessBoard.__eliminateSquares()

        output = False

        if len(ChessBoard.__rows[row]) > 0:

            output = True

        ChessBoard.__queens[prevRow]['cPos'] = currentQueensColumn

        ChessBoard.__rows = rows

        return output



    @staticmethod
    def __registerQueensNewPosition(row, columnIndx):

        # if the queen on this row is moved for the first time
        if ChessBoard.__queens[row]['iPos'] == 0:

            # then save the position where it started the repositioning
            # if it's not threatened there
            if ChessBoard.__queens[row]['cPos'] in ChessBoard.__rows[row]:
                ChessBoard.__queens[row]['iPos'] = ChessBoard.__queens[row]['cPos']
            # else use the first safe square
            else:
                ChessBoard.__queens[row]['iPos'] = ChessBoard.__rows[row][columnIndx]


        ChessBoard.__queens[row]['cPos'] = ChessBoard.__rows[row][columnIndx]

        ChessBoard.__removeThreatenedSquares()

    @staticmethod
    def __resetIPosOfFollowingQueens(row):
        """Reset the initial positions of queens that follow the specified row"""

        reset = False

        for iRow in ChessBoard.__queens.keys():

            if reset == True:
                ChessBoard.__queens[iRow]["iPos"] = 0

            if row == iRow:
                reset = True
