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

    public $id;
    public $name;
    public $dob;
    public $address;
    public $enrolmentDate;
    public $status;
    public $session = "0";

    function __construct()
    {
        $this->id = static::$ID;
        static::$ID++;
    }

    function __toString()
    {
        return  "Student: ".    $this->name.
                "| id: ".       $this->id.
                "| dob: ".      $this->dob.
                "| address: ".  $this->address.
                "| enrolled: ". date("d-m-Y", $this->enrolmentDate).
                "| status: ".   $this->status.
                "| session: ".  $this->session->name;

    }

    function updateDetails($name, $dob, $address, $enrolmentDate, $status)
    {
        if ($name) {

            if (!is_string($name))
                throw new UnexpectedValueException("Student's name not string");

            $this->name     = $name;
        }

        if ($dob) {

            if (!$this->dob = strtotime($dob))
                throw new UnexpectedValueException("$name's date of birth not time");

            $this->dob      = $dob;

        }

        if ($address) {

            if (!is_string($address))
                throw new UnexpectedValueException("Student's address not string");

            $this->address  = $address;
        }


        if ($enrolmentDate)

            if (!$this->enrolmentDate = strtotime($enrolmentDate))
                throw new UnexpectedValueException("$name's enrolment date not time");

        if ($status)

            if (is_string($status)) {

                if (strtolower($status) != "undergraduate" and strtolower($status) != "postgraduate")
                    throw new UnexpectedValueException("Incorrect student status for $name");

                else
                    $this->status   = $status;

            } else
                throw new UnexpectedValueException("Student's status not string");

        return $this;
    }

    /**
     * @param mixed $session
     */
    public function setSession($session)
    {
        $this->session = $session;
    }
}