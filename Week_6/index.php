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

    Controller::addStudent("Bobby", "28-10-1991", "UK", "20 weeks ago", "Undergraduate");

    Controller::addStudent("Ted", "28-10-1993", "France", "5 years ago", "Postgraduate");

    Controller::addSession("220CT", "Programming");
    Controller::addSession("210CT", "Data retrieval");
    Controller::addSession("290CT", "Something weird");
    Controller::addSession("121COM", "Computing");
    Controller::addSession("104KM", "Enterprise sys");

    $jimmy = Controller::findStudent(1);
    $luke  = Controller::findStudent(4);
    $ted   = Controller::findStudent(6);

    Controller::signInToSession($jimmy->id, "220CT");
    Controller::signInToSession($luke->id, "210CT");
    Controller::signInToSession($ted->id, "220CT");




//    Controller::deleteStudent(2);

//    Controller::deleteGraduates();

//    $students = Controller::sortStudentsAsc($students);

    $students = Controller::findStudents();

//    foreach ($students as $student)
//        echo $student . "<br>";

    echo json_encode($students);

} catch (\Exception $e) {
    echo $e->getMessage();
}