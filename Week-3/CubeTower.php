<?php

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 29/10/2017
 * Time: 12:42
 */

namespace Week3;

/**
 * Class with static interaction to sort elements based on
 * a) Any two neighbouring elements must be of different colours.
 * b) The length of an element is lower than the length of the element positioned before it.
 *
 * 1 - Set elements using CubeTower::setCubes($cubes) setter
 * 2 - Call CubeTower::sortCubes() method to perform the sorting
 * 3 - Echo the status of the cube order by calling CubeTower::printCubes
 *
 * Class CubeTower
 * @package Week3
 */
class CubeTower
{
    /**
     * Cubes that will be sorted
     * @var array
     */
    private static $cubes = [];

    /**
     * Contains the sequence of of cube lengths in decreasing order. Where key is length of a cube and its value is
     * the length of the next cube.
     * @var array
     */
     private static $lengthOrder = [];

    ##############
    ### PUBLIC ###

    /**
     * @param array $cubes
     */
    static function setCubes(array $cubes)
    {
        self::$cubes = $cubes;

    }

    /**
     * This method is intended to combine the cube sorting functionality under one abstraction.
     */
    static function sortCubes() {

        static::sortCubesByLength();

        static::setLengthOrder();

        static::$cubes = static::sortCubesByColour([], self::getPossibleCubes());

    }

    /**
     * This function prepares an HTML format text string about the current position of the cubes.
     * SIDE EFFECT: it echoes the string.
     */
    static function printCubes() {

        $output = "<!DOCTYPE html> <html> <body>";

        foreach (array_reverse(static::$cubes) as $cube) {

            $layer = str_pad(str_repeat("#", $cube['length']), 20, "_", STR_PAD_BOTH);

            $output .= '<p style="color:' . $cube['colour'] . ';">' . $layer . '</p>';

        }

        echo $output . "</body></html>";
    }

    ###############
    ### PRIVATE ###

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
            return $b['length'] <=> $a['length'];
        });

    }

    /**
     * CubeTower::lengthOrder attribute setter
     * @return void
     */
    private static function setLengthOrder()
    {

        $length          = static::$cubes[0]['length'];

        // the first (0) element's value is the largest cube's length
        static::$lengthOrder[0] = $length;

        // change the captured length, which is written to the array, each time
        // it doesn't match anymore with the length of the current element during the iteration
        foreach (static::$cubes as $key => $cube) {

            if ($length != $cube['length']) {
                static::$lengthOrder[$length] = $cube['length'];
                $length = $cube['length'];
            }
        }

        // set the last length's corresponding value in the sequence to null
        // in order to recognise that there will be no more cubes
        static::$lengthOrder[$length] = null;
    }

    /**
     * This function works collecting a set of cubes of the same size and inserting them into the array $sorted
     * so that their colors don't match. When the set of cubes is empty, the next set of cubes of a smaller length
     * in the CubeTower::lengthOrder sequence will be prepared and the process is repeated.
     *
     * @param $sorted array of cubes that have been sorted based on the colour differentiation criterion
     * @param $cubes  array of cubes that qualify for insertion in the array $sorted
     * @return array|bool
     */
    static private function sortCubesByColour($sorted, $cubes)
    {

        if (empty($cubes))
            // get next possible cubes based on the length of the previously sorted element
            $cubes = self::getPossibleCubes($sorted[count($sorted)-1]['length']);

        # BASE CASE 1
        // if null was returned - it means the end of the length sequence
        if (is_null($cubes))
            return $sorted;

        count($sorted) > 0 ?
            $prevColour = $sorted[count($sorted) - 1]['colour'] :
            $prevColour = null;

        foreach ($cubes as $key => $cube) {
        // trying to match every cube, in the current cube set, to the $sorted array
            if ($cube['colour'] != $prevColour) {

                // pluck the matched cube from the current cube set
                $temp = $cubes;
                unset($temp[$key]);

                $sorted []= $cube;

                // repeat the process
                if ($isSorted = static::sortCubesByColour($sorted, $temp))
                    return $isSorted;
                else
                    array_pop($sorted);

            }
        }

        # BASE CASE 2
        // no cube in the current set can be matched
        return false;

    }


    /**
     * Get the set of cubes that correspond to the next (smaller) length provided in the parameter.
     * @param int $length
     * @return array|null
     */
    private static function getPossibleCubes($length = 0)
    {

        $length = static::$lengthOrder[$length];

        if (is_null($length))
            return null;

        // Filter and return cubes corresponding to the $length
        return array_filter(static::$cubes, function($cube) use ($length) {

            return $cube['length'] == $length;

        });

    }

}