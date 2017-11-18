<?php

require("Tree.php");
require("Student.php");
require("Session.php");

/**
 * Created by PhpStorm.
 * User: oscar
 * Date: 17/11/2017
 * Time: 14:22
 */
class Controller
{

    /**
     * All the registered session. 0: no-session
     * @var array
     */
    private static $sessions = [0];

    /**
     * BST with students
     * @var BinarySearchTree
     */
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
        self::requireInstance();

        $student = new Student();
        $student->updateDetails($name, $dob, $address, $enrolmentDate, $status);

        $studentNode = new Node($student);
        static::$INSTANCE_BST->insert($studentNode);

        return $student;
    }

    /**
     * @param int $id to specify a particular student
     * @return mixed
     */
    public static function findStudent($id)
    {
        self::requireInstance();

        if (is_int(intval($id)))
            return static::$INSTANCE_BST->findNode($id);

        else
            throw new UnexpectedValueException("Id $id has wrong format");

    }

    /**
     * @param int $studentId
     * @param array $details
     * @return Student
     */
    public static function updateStudentDetails($studentId, $details)
    {
        self::requireInstance();

        $student        = static::findStudents($studentId);

        $name           = null;
        $dob            = null;
        $address        = null;
        $enrolmentDate  = null;
        $status         = null;
        $session        = null;

        switch (true) {

            case array_key_exists("name", $details):
                $name = $details["name"];
                break;

            case array_key_exists("dob", $details):
                $dob = $details["dob"];
                break;

            case array_key_exists("address", $details):
                $address = $details["address"];
                break;

            case array_key_exists("enrolmentDate", $details):
                $enrolmentDate = $details["enrolmentDate"];
                break;

            case array_key_exists("status", $details):
                $status = $details["status"];
                break;

            case array_key_exists("session", $details):
                $session = $details["session"];
                break;
        }

        // only not null will be updated
        return $student->updateDetails($name, $dob, $address, $enrolmentDate, $status, $session);

    }

    /**
     * Student search based on various parameters such as course code and status.
     *
     * @param $sessionCodes
     * @param bool $undergrads
     * @param bool $postgrads
     * @return array whose keys are session codes and values students at those sessions, "": no-session
     */
    public static function findStudents($sessionCodes = [], $undergrads= true, $postgrads = true)
    {
        self::requireInstance();

        // If empty, search all sessions
        if (empty($sessionCodes))
            $sessionCodes = static::getAllSessionCodes();

        $studentTypes = [];

        if ($undergrads)
            $studentTypes []= "undergraduate";

        if ($postgrads)
            $studentTypes []= "postgraduate";

        // validate codes
        foreach ($sessionCodes as $sessionCode)
            static::findSession($sessionCode);

        // validator that determines what students will
        // be returned during the traversing of the BST
        $validator = function ($node) use ($sessionCodes, $studentTypes) {
            // if condition true, the value of the node is returned

            if (empty($studentTypes))
                return in_array($node->student->session->code, $sessionCodes);
            // if in session and status matched
            return  in_array($node->student->session->code, $sessionCodes)
                    and in_array(strtolower($node->student->status), $studentTypes);
        };

        $students = static::$INSTANCE_BST->getAllStudents($validator);

        return      static::sessionSort($students);
    }

    /**
     * Sort students by their names for every session in the input array
     * @param array $studentsInSessions ["session_code" => [students]]
     * @return array
     */
    private static function sessionSort(array $studentsInSessions)
    {
        foreach ($studentsInSessions as &$studentsInSession)
            static::sortStudentsAsc($studentsInSession);

        return $studentsInSessions;
    }

    public static function findStudentsPlainly()
    {
        $students = static::$INSTANCE_BST->getAllStudents();

        return      static::sortStudentsAsc($students);
    }

    private static function getAllSessionCodes()
    {
        $codes = [];

        foreach (static::$sessions as $session)
            $codes []= $session->code;

        return $codes;
    }

    public static function sortAllStudentsByNameAsc()
    {
        self::requireInstance();

        $students = Controller::findStudents();

        return      Controller::sortStudentsAsc($students);
    }

    public static function sortStudentsAsc(array &$students)
    {
        self::requireInstance();

        // built-in quick sort based on supplementary parameters
        // it moves the $b variable up or down in respect to the $a variable
        usort($students, function($a, $b) {
            // a == b = 0 | a > b = 1 | a < b = -1
            return static::lexicographicComparison($a->name, $b->name);
        });

        return $students;
    }

    /**
     * Compares whether word1 has higher, lower or same lexicographic value as word2
     * @param $word1
     * @param $word2
     * @return int
     */
    private static function lexicographicComparison($word1, $word2)
    {
        self::requireInstance();

        // for each letter in the word1
        for ($i = 0; $i < strlen($word1); $i++) {

            // if word2 is shorter
            if ($i == strlen($word2))
                return 1;

            elseif (ord($word1[$i]) > ord($word2[$i]))
                return 1;

            elseif (ord($word1[$i]) < ord($word2[$i]) )
                return -1;
        }

        // same words
        if (strlen($word1) == strlen($word2))
            return 0;

        // same initial letters but word1 was shorter
        return -1;
    }

    public static function deleteStudent($id)
    {
        self::requireInstance();

        static::$INSTANCE_BST->deleteNode($id);
    }

    public static function deleteGraduates()
    {
        self::requireInstance();

        $graduates = static::findGraduatedStudents();

        foreach ($graduates as $graduate)
            static::deleteStudent($graduate->id);
    }

    public static function addSession($code, $name)
    {
        self::requireInstance();

        if(is_string($name))
            static::$sessions []= new Session($code, $name);

        else
            throw new UnexpectedValueException("Session name not string");
    }

    public static function signInToSession($id, $sessionName)
    {
        self::requireInstance();

        $student = static::$INSTANCE_BST->findNode($id);

        $session = static::findSession($sessionName);

        $student->setSession($session);

    }

    public static function findSession($code)
    {
        foreach (static::$sessions as $session)

            if ($session->code === $code)
                return $session;

            // no-session
            elseif($code === "0")
                return true;

        throw new UnexpectedValueException("Session with code $code not found");
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