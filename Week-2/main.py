import ChessBoard as CB

CB.ChessBoard.randomlyPositionQueens()

if not CB.ChessBoard.areQueensPositioned():

    CB.ChessBoard.positionWithBruteForce()

CB.ChessBoard.printQueens()