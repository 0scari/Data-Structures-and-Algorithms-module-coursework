<?php
/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 15:24
 */

require ("Controller.php");

try {

//    echo strtolower("Undergraduate") == "undergraduate" ;

    Controller::setNewInstance();

    Controller::addStudent("Jimmy", "28-10-1993", "Germany", "yesterday", "Undergraduate");

    Controller::addStudent("Bob", "28-10-1993", "UK", "-1 week", "Undergraduate");

    Controller::addStudent("Jack", "28-10-1993", "Bulgaria", "2 weeks ago", "Undergraduate");

    Controller::addStudent("Luke", "28-10-1991", "Uganda", "4 years ago", "Postgraduate");

    Controller::addStudent("Bob", "28-10-1991", "UK", "20 weeks ago", "Undergraduate");

    Controller::addStudent("Ted", "28-10-1993", "France", "5 years ago", "Postgraduate");


    $students = Controller::findStudent();
    $students = Controller::sortStudentsAsc($students);

    foreach ($students as $student)
        echo $student . "<br>";



} catch (\Exception $e) {
    echo $e->getMessage();
}