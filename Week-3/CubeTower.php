<?php

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 29/10/2017
 * Time: 12:42
 */

namespace Week3;

class CubeTower
{
     static $cubes = [
        ['colour' => 2, 'length' => 4],
        ['colour' => 1, 'length' => 1],
        ['colour' => 2, 'length' => 2],
        ['colour' => 2, 'length' => 3],
        ['colour' => 1, 'length' => 4],
        ['colour' => 3, 'length' => 2],
    ];

    /**
     * Sorting function that uses the built-in quicksort and with the help of a callback
     * changes the representation of each entry's value that is sorted
     * @return void
     */
    private static function sortCubesByLength() {

        // built-in quick sort based on supplementary parameters
        // it moves the $b variable up or down in respect to the $a variable
        usort(static::$cubes, function($a, $b) {
            // a == b = 0 | a > b = 1 | a < b = -1
            return $a['length'] <=> $b['length'];
        });

    }

    static function printCubes() {

        static::sortCubesByLength();

        return static::$cubes;

    }

}