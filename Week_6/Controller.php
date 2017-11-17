<?php

require("BinarySearchTree.php");

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 14:22
 */
class Controller
{
    /**
     * @var array
     */
    private static $sessions;
    static $INSTANCE_BST = null;

    /**
     * Create an instance of the system
     * @return void
     */
    public static function setNewInstance()
    {
        static::$INSTANCE_BST = new BinarySearchTree();
    }

    public static function addStudent($name, $dob, $address, $enrolmentDate, $status)
    {
        static::requireInstance();

            $student = new Student($name, $dob, $address, $enrolmentDate, $status);

            static::$INSTANCE_BST->create($student);

    }
    
    public static function findStudentById($id = 0) 
    {
        
    }

    public static function findGraduatedStudents()
    {

    }

    public static function updateStudentDetails($student)
    {

    }

    public static function findStudentsByClass($session)
    {

    }

    public static function sortStudentsByNameAsc(array $students)
    {

    }

    public static function listStudents(array $students)
    {

    }

    public static function deleteStudent($student)
    {
//        1st - find in BST
//        2nd - delete node
    }

    public static function deleteGraduates($students)
    {

    }

    public static function createSession($name)
    {
        if(is_string($name))
            static::$sessions []= new Session($name);

        else
            throw new UnexpectedValueException("Session name not string");
    }

    private static function findStudents($searchCallback)
    {
        if (is_callable($searchCallback))
            return [];
        
        else
            return 1;
        
    }


    /**
     * Throw an exception if no instance exists
     * @throws InstanceDoesNotExistException
     */
    private static function requireInstance()
    {
        if (static::$INSTANCE_BST === null)
            throw new InstanceDoesNotExistException("Instance not set");

    }


}