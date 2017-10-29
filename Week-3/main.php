<?php
/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 29/10/2017
 * Time: 13:35
 */

require 'CubeTower.php';
use Week3\CubeTower;

CubeTower::setCubes([
    ['colour' => "red",     'length' => 4],
    ['colour' => "grey",    'length' => 1],
    ['colour' => "red",     'length' => 2],
    ['colour' => "red",     'length' => 3],
    ['colour' => "grey",    'length' => 4],
    ['colour' => "purple",  'length' => 2]]);

CubeTower::sortCubes();

CubeTower::printCubes();

