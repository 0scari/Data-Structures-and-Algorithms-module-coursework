<?php
/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 15:24
 */

require ("BinarySearchTree.php");

$bst = new BinarySearchTree(25);

$n1 = new BinarySearchNode(20);
$n2 = new BinarySearchNode(36);
$n3 = new BinarySearchNode(22);

$bst->insert($n1);
$bst->insert($n2);
$bst->insert($n3);

$bst->delete($n2);

var_dump($bst->getAllNodes());