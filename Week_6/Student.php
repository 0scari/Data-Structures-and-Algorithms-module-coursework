<?php

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 14:44
 */
class Student
{
    static  $ID = 1;

    private $id;
    private $name;
    private $dob;
    private $address;
    private $enrolmentDate;
    private $status;
    private $session;

    function __construct()
    {
        $this->id = static::$ID;

        static::$ID ++;
    }

    public function setDetails($name, $dob, $address, $enrolmentDate, $status)
    {
        if (!is_string($name))
            throw new UnexpectedValueException("Student's name not string");

        if (!$this->$dob = strtotime($dob))
            throw new UnexpectedValueException("Student's date of birth not time");

        if (!is_string($address))
            throw new UnexpectedValueException("Student's address not string");

        if (!$this->enrolmentDate = strtotime($enrolmentDate))
            throw new UnexpectedValueException("Student's name not time");

        if (!is_string($status))
            throw new UnexpectedValueException("Student's status not string");

    }

    /**
     * @param mixed $session
     */
    public function setSession($session)
    {
        $this->session = $session;
    }
}