import unittest   as UT
import ChessBoard as CB

class TestChessBoard(UT.TestCase):

    def tearDown(self):

        CB.ChessBoard.setRows({
            'a': [1, 2, 3, 4, 5, 6, 7, 8],
            'b': [1, 2, 3, 4, 5, 6, 7, 8],
            'c': [1, 2, 3, 4, 5, 6, 7, 8],
            'd': [1, 2, 3, 4, 5, 6, 7, 8],
            'e': [1, 2, 3, 4, 5, 6, 7, 8],
            'f': [1, 2, 3, 4, 5, 6, 7, 8],
            'g': [1, 2, 3, 4, 5, 6, 7, 8],
            'h': [1, 2, 3, 4, 5, 6, 7, 8]

        })

    def test_ThrearenedSquareElimination(self):

        CB.ChessBoard.setQueens({
            'a': 1,
            'b': 3,
            'c': 5,
            'd': 2,
            'e': 4,
            'f': 0,
            'g': 0,
            'h': 0
        })

        CB.ChessBoard._ChessBoard__eliminateSquares()

        self.assertDictEqual(
            # Expected
            {'a': [1, 2, 3, 4, 5, 6, 7, 8],
            'b': [ 3, 4, 5, 6, 7, 8],
            'c': [ 5, 6, 7, 8],
            'd': [ 2, 7, 8],
            'e': [ 4, 8],
            'f': [ ],
            'g': [ ],
            'h': [ ]},

            # Actual
            CB.ChessBoard.getRows(),

            "Threatened square elimination went wrong"
        )

    def test_BruteForceRepositioning1(self):

        CB.ChessBoard.setQueens({
            'a': 8,
            'b': 6,
            'c': 1,
            'd': 3,
            'e': 5,
            'f': 7,
            'g': 4,
            'h': 0
        })

        CB.ChessBoard.positionWithBruteForce()

        self.assertDictEqual(
            # Expected
            {'a': 8,
            'b': 3,
            'c': 1,
            'd': 6,
            'e': 2,
            'f': 5,
            'g': 7,
            'h': 4},

             # Actual
             CB.ChessBoard.getQueens(),

             "Repositioning test 1 failed")

    def test_BruteForceRepositioning2(self):

        CB.ChessBoard.setQueens({
            'a': 4,
            'b': 8,
            'c': 5,
            'd': 2,
            'e': 6,
            'f': 1,
            'g': 7,
            'h': 0
        })

        CB.ChessBoard.positionWithBruteForce()

        self.assertDictEqual(
            # Expected
            {'a': 4,
             'b': 8,
             'c': 1,
             'd': 5,
             'e': 7,
             'f': 2,
             'g': 6,
             'h': 3},

            # Actual
            CB.ChessBoard.getQueens(),

            "Repositioning test 2 failed")

    def test_BruteForceRepositioning3(self):
        CB.ChessBoard.setQueens({
            'a': 4,
            'b': 7,
            'c': 5,
            'd': 8,
            'e': 2,
            'f': 0,
            'g': 0,
            'h': 0
        })

        CB.ChessBoard.positionWithBruteForce()

        self.assertDictEqual(
            # Expected
            {'a': 5,
             'b': 2,
             'c': 4,
             'd': 6,
             'e': 8,
             'f': 3,
             'g': 1,
             'h': 7},

            # Actual
            CB.ChessBoard.getQueens(),

            "Repositioning test 3 failed")

if __name__ == '__main__':
    UT.main()