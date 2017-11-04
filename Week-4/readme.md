## WEEK 4

1. Consider a n x m matrix, with elements decimal digits (natural numbers between 1 and 9), representing
colours. A connected set associated to an element is the set of elements that may be reached from this
element, by successive moves on a same row or column preserving the same color. It is to determine
the size and the colour of the biggest connected set. In case of multiple solutions, display them all.

    Input: n = 5 m = 6 and the values within the matrix are randomised, between 1 and 9)

    1 3 5 6 6 6

    8 8 5 2 2 2

    2 8 8 3 4 1

    7 1 8 5 9 9

    9 8 3 4 2 2

    Output: The size of the biggest set is 5 and the colour is whichever colour you represented by 8.
2. Adapt the Quick Sort algorithm to find the mth smallest element out of a list of n integers, where m is
read from the standard input.
    
    For example, when m = 5, your version of Quick Sort will output the 5th smallest element out of your
    input list.