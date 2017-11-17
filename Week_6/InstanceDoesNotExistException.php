<?php
/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 15:33
 */

/**
 * Thrown when the user attempts to work on non existent instance
 */
class InstanceDoesNotExistException extends \Exception
{
    public function __construct($message, $code = 0, Exception $previous = null) {

        parent::__construct($message, $code, $previous);
    }
}