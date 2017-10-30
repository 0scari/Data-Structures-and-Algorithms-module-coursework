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
     private static $cubes = [];

     private static $lengthOrder = [];

    /**
     * Sorting function that uses the built-in quicksort and with the help of a callback
     * changes the representation of each entry's value that is sorted
     * @return void
     */

    /**
     * @param array $cubes
     */
    static function setCubes(array $cubes)
    {
        self::$cubes = $cubes;

    }

    static function sortCubes() {

        static::sortCubesByLength();

        static::setLengthOrder();

        static::$cubes = static::sortCubesByColour([], self::getPossibleCubes());

    }

    static function printCubes() {

        $output = "<!DOCTYPE html> <html> <body>";

        foreach (array_reverse(static::$cubes) as $cube) {

            $layer = str_pad(str_repeat("#", $cube['length']), 20, "_", STR_PAD_BOTH);

            $output .= '<p style="color:' . $cube['colour'] . ';">' . $layer . '</p>';

        }

        echo $output . "</body></html>";
    }

    private static function sortCubesByLength() {

        // built-in quick sort based on supplementary parameters
        // it moves the $b variable up or down in respect to the $a variable
        usort(static::$cubes, function($a, $b) {
            // a == b = 0 | a > b = 1 | a < b = -1
            return $b['length'] <=> $a['length'];
        });

    }


    private static function setLengthOrder()
    {

        $length          = static::$cubes[0]['length'];

        static::$lengthOrder[0] = $length;

        foreach (static::$cubes as $key => $cube) {

            if ($length != $cube['length']) {
                static::$lengthOrder[$length] = $cube['length'];
                $length = $cube['length'];
            }

            if ($key == count(static::$cubes) - 1)
                static::$lengthOrder[$length] = null;

        }
    }

    static private function sortCubesByColour($sorted, $cubes)
    {


        if (empty($cubes))
            $cubes = self::getPossibleCubes($sorted[count($sorted)-1]['length']);

        if (is_null($cubes)) {
            return $sorted;

        }

        count($sorted) > 0 ?
            $prevColour = $sorted[count($sorted) - 1]['colour'] :
            $prevColour = null;

        foreach ($cubes as $key => $cube) {

            if ($cube['colour'] != $prevColour) {

                $temp = $cubes;
                unset($temp[$key]);

                $sorted []= $cube;

                if ($isSorted = static::sortCubesByColour($sorted, $temp))
                    return $isSorted;
                else
                    array_pop($sorted);

            }
        }

        return false;

    }


    private static function getPossibleCubes($length = 0)
    {

        $length = static::$lengthOrder[$length];

        if (is_null($length))
            return null;

        return array_filter(static::$cubes, function($cube) use ($length) {

            return $cube['length'] == $length;

        });

    }

}