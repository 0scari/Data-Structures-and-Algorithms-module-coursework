"use strict"

var matrix = [];

const ROWS    = 6;
const COLUMNS = 8;

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

/**
 * This function outputs a multidimensional array with size based on the values in the parameters,
 * whose entries are arbitrary numbers in range 1..9
 *
 * @param i array
 * @param j array
 *
 * @returns [Array]
 */
function fillMatrix(rows, columns)
{
    var matrix = [];

    for (var i = 0; i < rows; i++) {

        matrix[i] = [];

        for (var j = 0; j < columns; j++)

             matrix[i].push(getRandomInt(1,9))
    }

    return matrix;
}

function findSequence(matrix, row, column, sequence = []) {

    var columnOnLeft = 0;
    if (column > 0)
        columnOnLeft = column - 1;

    var columnOnRight = COLUMNS;
    if (column < COLUMNS)
        columnOnRight = column + 1;

    var rowAbove = 0;
    if (row > 0)
        rowAbove = row - 1;

    var rowBelow = row;
    if (row < ROWS)
        rowBelow = row + 1;

    if (matrix[row][column] === matrix[row][columnOnLeft]
        && column !== columnOnLeft ) {
        findSequences(matrix, row, columnOnLeft, sequence)
    }

    matrix[row][column] = 0;
    sequence.unshift({"row": row, "column": column});
}

function findSequences(matrix, rows, columns) {

    var sequences = {};
    var sequence  = null;

    for (var i = 0; i < rows; i++) {

        for (var j = 0; j < columns; j++) {

            if (i === 0 && j === 0)
                continue;

            else
                sequence = findSequence(matrix, i, j);

                if (sequence)
                    if (sequences[matrix[i][j]] < sequence)
                        sequences[matrix[i][j]] = sequence;
        }
    }

}



matrix = fillMatrix(ROWS, COLUMNS);

// var workingMatrix = matrix.slice(0);





