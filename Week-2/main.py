import ChessBoard as CB

CB.ChessBoard.randomlyPositionQueens()
#
CB.ChessBoard.print()

if not CB.ChessBoard.areQueensPositioned():

    CB.ChessBoard.positionWithBruteForce()

CB.ChessBoard.print()

