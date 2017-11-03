"use strict"

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
    if (column < COLUMNS - 1)
        columnOnRight = column + 1;

    var rowAbove = 0;
    if (row > 0)
        rowAbove = row - 1;

    var rowBelow = row;
    if (row < ROWS - 1)
        rowBelow = row + 1;

    var recursions = [];

    if (matrix[row][column] === matrix[row][columnOnLeft]
        && column !== columnOnLeft )
        recursions.push({"row":row, "column":columnOnLeft});

    if (matrix[row][column] === matrix[row][columnOnRight]
        && column !== columnOnRight )
        recursions.push({"row":row, "column":columnOnRight});

    if (matrix[row][column] === matrix[rowAbove][column]
        && row !== rowAbove)
        recursions.push({"row":rowAbove, "column":column});

    if (matrix[row][column] === matrix[rowBelow][column]
        && row !== rowBelow )
        recursions.push({"row":rowBelow, "column":column});

    if (recursions.length) {

        matrix[row][column] = 0;
        sequence.push({"row": row, "column": column});

        recursions.forEach( function (recursion) {

            sequence.concat(findSequence(matrix, recursion["row"], recursion["column"], sequence));
            matrix[recursion["row"]][recursion["column"]] = 0;
        })

    } else if (sequence.length)
        sequence.push({"row": row, "column": column});

    return sequence;
}

function findSequences(matrix, rows, columns) {

    var sequences = {};
    var sequence  = []; //TODO change initial type

    for (var i = 0; i < rows; i++) {

        for (var j = 0; j < columns; j++) {

            if (matrix[i][j] === 0)
                continue;

            else
                var number = matrix[i][j];
                sequence   = findSequence(matrix, i, j);

                if (sequence.length > 0)
                    if(sequences.hasOwnProperty(number)) {
                        if (Object.keys(sequences[number]).length < sequence.length)
                            sequences[number] = sequence;
                    } else
                        sequences[number] = sequence;
        }
    }

    return sequences;
}

function checkIfWithinTheLongestSequence(row, column, longestSequence) {

    var match = false;

    longestSequence.forEach(function (rowColumnPair) {

        console.log(rowColumnPair["row"] === row);
        console.log(rowColumnPair["column"] === column);

        if ((rowColumnPair["row"] === row)
            && (rowColumnPair["column"] === column)) {
            match = true;
            return;
        }
    });

    return match;

}

function getLongestSequence(sequences) {

    var longest = [];
    
    for (var attrib in sequences) {
        // skip loop if the property is from prototype
        if (!sequences.hasOwnProperty(attrib)) continue;

        if (sequences[attrib].length > longest.length)
            longest = sequences[attrib]

    }

    return longest;
}


var matrix = fillMatrix(ROWS, COLUMNS);

var matrix1 = matrix.map(function (row) {
    return row.slice(0);
});

var sequences       = findSequences(matrix1, ROWS, COLUMNS);

var longestSequence = getLongestSequence(sequences);