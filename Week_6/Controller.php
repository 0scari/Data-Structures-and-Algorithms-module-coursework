<?php

require("Tree.php");
require("Student.php");

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

        $student = new Student();
        $student->updateDetails($name, $dob, $address, $enrolmentDate, $status);

        $studentNode = new Node($student);
        static::$INSTANCE_BST->insert($studentNode);

        return $student->id;

    }
    
    public static function findStudent($id = null)
    {
        if ($id)

            if (is_int(intval($id)))
                return static::$INSTANCE_BST->findNode($id);

            else
                throw new UnexpectedValueException("Id $id has wrong format");

        else
            return static::$INSTANCE_BST->getAllStudents();
    }

    public static function findGraduatedStudents()
    {
        $students = static::$INSTANCE_BST->getAllStudents();

        $grads    = [];

        foreach ($students as $student)

            if (strtolower($student->status) === "postgraduate")
                $grads []= $student;

        return $grads;

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

    public static function sortStudentsAsc(array $students)
    {
        // built-in quick sort based on supplementary parameters
        // it moves the $b variable up or down in respect to the $a variable
        usort($students, function($a, $b) {
            // a == b = 0 | a > b = 1 | a < b = -1
            return static::lexicographicComparison($a->name, $b->name);
        });

        return $students;
    }

    private static function lexicographicComparison($word1, $word2)
    {
        for ($i = 0; $i < strlen(min($word1, $word2)); $i++) {

            if (ord($word1[$i]) > ord($word2[$i]))
                return 1;

            elseif (ord($word1[$i]) < ord($word2[$i]))
                return -1;
        }

        return 0;
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