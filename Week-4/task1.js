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
 * @param rows array
 * @param columns array
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

    // ### Determine positions of left, right, upper, lower elements
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

    // ##############################################################

    // Will contain (row, column) positions of contiguous numbers that match each other
    var recursions = [];


    // ### Check whether the contiguous numbers match the current one

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

    // ################################################################


    if (recursions.length) {

        // mark as done
        matrix[row][column] = 0;

        sequence.push({"row": row, "column": column});

        recursions.forEach( function (recursion) {

            sequence.concat(findSequence(matrix, recursion["row"], recursion["column"], sequence));
            matrix[recursion["row"]][recursion["column"]] = 0;
        })

    } else if (sequence.length) // lateral element in the sequence
        // won't have anything in $recursions, but still belongs to the sequence
        sequence.push({"row": row, "column": column});

    return sequence;
}

/**
 * It iterates over the matrix and applies the recursive function to check
 * if the contiguous elements have the same value. If so,
 * (row, column) pairs of the sequence will be returned and added to the array
 * comprising all the sequences which is returned by this function at the end.
 *
 * @param matrix [[]]
 * @param rows int
 * @param columns int
 * @returns {{}}
 */
function findSequences(matrix, rows, columns) {

    var sequences = {};
    var sequence  = [];

    for (var i = 0; i < rows; i++) {

        for (var j = 0; j < columns; j++) {

            // if value 0, it means the original value belonged to a sequence and was rewritten
            if (matrix[i][j] === 0)
                continue;

            else

                // capture the value
                var number = matrix[i][j];

                // check if a sequence can be formed
                sequence   = findSequence(matrix, i, j);

                if (sequence.length > 0)

                    // if a sequence with this number already exists
                    if(sequences.hasOwnProperty(number)) {

                        if (sequences[number].length < sequence.length)
                            sequences[number] = sequence;
                    } else
                        sequences[number] = sequence;
        }
    }

    return sequences;
}

/**
 * Function used during creation of the table in the HTML document. It checks if the (row, column) numbers
 * belong to the longest sequence in order to make it bold if it does.
 * @param row
 * @param column
 * @param longestSequence
 * @returns {boolean}
 */
function checkIfWithinTheLongestSequence(row, column, longestSequence) {

    var match = false;

    longestSequence.forEach(function (rowColumnPair) {

        if ((rowColumnPair["row"] === row)
            && (rowColumnPair["column"] === column)) {
            match = true;
            return;
        }
    });

    return match;

}

/**
 * Find the longest sequence among all the sequences
 * @param sequences
 * @returns {Array}
 */
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

// Create a duplicate matrix to work with
var matrix1 = matrix.map(function (row) {
    return row.slice(0);
});

var sequences       = findSequences(matrix1, ROWS, COLUMNS);

var longestSequence = getLongestSequence(sequences);