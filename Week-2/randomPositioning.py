class ChessBoard:

    __queens = { 'a': {'cPos': 1, 'iPos': 0},
                 'b': {'cPos': 3, 'iPos': 0},
                 'c': {'cPos': 5, 'iPos': 0},
                 'd': {'cPos': 7, 'iPos': 0},
                 'e': {'cPos': 2, 'iPos': 0},
                 'f': {'cPos': 0, 'iPos': 0},
                 'g': {'cPos': 0, 'iPos': 0},
                 'h': {'cPos': 0, 'iPos': 0}
    }

    __rows   = {
        'a': [],
        'b': [],
        'c': [],
        'd': [],
        'e': [],
        'f': [],
        'g': [],
        'h': [],
    }

    ### PUBLIC ###

    

    def areQueensPositioned():
        return ChessBoard.__queens['h']['cPos'] != 0

    def positionWithBruteForce():

        while ChessBoard.__queens['h']['cPos'] == 0:

            # Position of the last randomly positioned queen
            lastQueensPos = ChessBoard.__findLastQueen()

            ChessBoard.__removeThreatenedSquares()

            ChessBoard.__moveQueenFurther(lastQueensPos)

            nextRowIndx = chr(ord(list(lastQueensPos.keys())[0]) + 1 )

            ChessBoard.__queens[nextRowIndx]['cPos'] = ChessBoard.__rows[nextRowIndx][0]




    def __str__(self):
        return

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
        ChessBoard.__removeDiagonalSquares()
        ChessBoard.__removeVerticalSquares()
        ChessBoard.__reposThreatenedQueens()

    @staticmethod
    def __removeDiagonalSquares():

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
                                            if column != qColumn["cPos"] + depth and column != qColumn["cPos"] - depth]
                        depth += 1

                        ChessBoard.__rows[bRow] = safeColumns

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
    def __moveQueenFurther (queen):

        # # saving queen's position (cPos) before it is moved
        # queensPrevPos = list(queen.values())[0]

        for qRow, qColumn in queen.items():

            ChessBoard.__resetFollowingQueens(qRow)

            repositioningSuccess = False

            while (not repositioningSuccess):
                # compute next column number and store its index in the variable
                print(qRow, ChessBoard.__rows[qRow])


                if len(ChessBoard.__rows[qRow]) > 0 and ChessBoard.__queens[qRow]['cPos'] != 0:
                    print(qColumn['cPos'])
                    nextColumnIndx =  (ChessBoard.__rows[qRow].index(qColumn['cPos']) + 1) \
                                      % len(ChessBoard.__rows[qRow])

                    nextRow = chr(ord(qRow) + 1)  # get next alphabetic letter
                    repositioningSuccess = (len(ChessBoard.__rows[nextRow]) > 0) \
                                            and ChessBoard.__rows[qRow][nextColumnIndx] != queen[qRow]['iPos']

                    print("row:", qRow, " | next index:",ChessBoard.__rows[qRow].index(qColumn['cPos']) + 1, " | len:", len(ChessBoard.__rows[qRow]))

                    print("not same square:", ChessBoard.__rows[qRow][nextColumnIndx] != queen[qRow]['cPos'],
                          " not initial pos:", ChessBoard.__rows[qRow][nextColumnIndx] != queen[qRow]['iPos'])
                    print(queen[qRow]['iPos'])



                # if the new column number is not the same as before nor the initial
                if repositioningSuccess :
                    ChessBoard.__registerQueensNewPosition(qRow, nextColumnIndx)
                    return
                else:

                    prevRow = chr(ord(qRow) - 1) # get previous alphabetic letter

                    # Reposition previous queen
                    ChessBoard.__moveQueenFurther({prevRow: ChessBoard.__queens[prevRow]})

            ChessBoard.__registerQueensNewPosition(qRow, nextColumnIndx)

    @staticmethod
    def __registerQueensNewPosition(row, columnIndx):

        # if the queen on this row is moved for the first time
        if ChessBoard.__queens[row]['iPos'] == 0:
            # then save the position where it started the repositioning
            print("ci: ", columnIndx, "row:", ChessBoard.__rows[row])


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


    @staticmethod
    def test():

        ChessBoard.positionWithBruteForce()

        for qRow, qColumn in ChessBoard.__queens.items():
            print(qRow + ': ' + str(qColumn))

    @staticmethod
    def test2():
        ChessBoard.__resetAllRows()
        ChessBoard.__removeDiagonalSquares()
        ChessBoard.__removeVerticalSquares()
        print(ChessBoard.__rows)


print("Started")


