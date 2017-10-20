class ChessBoard:

    __queens = { 'a': 0,
                 'b': 0,
                 'c': 0,
                 'd': 0,
                 'e': 0,
                 'f': 0,
                 'g': 0,
    }

    __rows   = {
        'a' : [1,2,3,4,5,6,7,8],
        'b' : [1,2,3,4,5,6,7,8],
        'c' : [1,2,3,4,5,6,7,8],
        'd' : [1,2,3,4,5,6,7,8],
        'e' : [1,2,3,4,5,6,7,8],
        'f' : [1,2,3,4,5,6,7,8],
        'g' : [1,2,3,4,5,6,7,8]
    }

    ### PUBLIC ###

    def __init__ (self):
        return


    def randomlyPositionQueens():
        return

    def areQueensPositioned():
        return

    def positionWithBruteForce():

        lastQueenPos = ChessBoard.findRowWithLastQueen()

        ChessBoard.moveQueenFurther()

        ChessBoard.__rows[lastQueenPos]

    def __str__(self):
        return

    #################
    ###  PRIVATE  ###
    ### UTILITIES ###
    #################

    @staticmethod
    def __removeDiagonalCells(row, pos):
        return

    @staticmethod
    def __removeVerticalCells(row, pos):
        return

    def __findRowWithLastQueen ( ):
        return

    @staticmethod
    def __moveQueenFurther (queen):

        initialPos = ChessBoard.__queens[queen]


