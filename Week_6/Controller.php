<?php

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 14:22
 */
class Controller
{
    
    private $studentBST = null;
    
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

    public static function addStudent()
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

    private static function findStudents($searchCallback)
    {
        if (is_callable($searchCallback))
            return [];
        
        else
            return 1;
        
    }

}