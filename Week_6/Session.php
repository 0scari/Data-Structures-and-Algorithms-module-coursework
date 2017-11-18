<?php

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 14:35
 */
class Session
{
    public $id;
    public $name;
    public $code;

    private static $ID = 1;

    public function __construct($code, $name)
    {

        if(is_string($name) && is_string($code)) {
            $this->name = $name;
            $this->code = $code;

        } else
            throw new UnexpectedValueException("Session name or code not string");

        $this->id = static::$ID;
        static::$ID ++;
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return string
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = $name;
    }





}