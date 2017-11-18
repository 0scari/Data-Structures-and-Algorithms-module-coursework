<?php

class BinarySearchTree {

    private $root;

    public function __construct($student = null)
    {
        if ($student instanceof Student)
            $this->root = new Node($student);
    }

    public function getRoot()
    {
        return $this->hasNode() ? $this->root : null;
    }

    public function insert(Node $node)
    {
        $this->root ?
            $this->root->insert($node):
            $this->root = $node;
    }

    public function findNode($id)
    {
        if ($this->hasNode())
            return $this->root->find($id);

    }

    public function deleteNode($id)
    {
        return $this->hasNode() ? $this->root->delete($id, $this->root, 'right') : false;
    }

    public function hasNode()
    {
        if(isset($this->root))
            return true;

        else
            throw new Exception("No registered students");

    }

    /**
     * BST traversal that returns visited nodes. If callback $validator present, will also evaluate
     * nodes to output against a condition.
     *
     * @param null $validator a bool output callback to return nodes that match the criterion.
     * @param null $node
     * @param array $nodes
     * @return array
     */
    public function getAllStudents($validator = null, $node = null, $nodes = [])
    {
        if (is_null($node))
            $node = $this->root;

        if($node->left)
            $nodes = $this->getAllStudents($validator, $node->left, $nodes);


        if (is_callable($validator)) {

            if ($validator($node))
                $nodes[$node->student->session->code] []= $node->student;

        } else
            $nodes [] = $node->student;

        if($node->right)
            $nodes = $this->getAllStudents($validator, $node->right, $nodes);

        return $nodes;
    }


}
class Node {

    public $student;
    public $left = null;
    public $right = null;

    public function __construct($student)
    {
        if ($student instanceof Student)
            $this->student = $student;

        else
            throw new UnexpectedValueException("Node constructed with not Student type");
    }


    /**
     * @param int $id searched
     * @param Node|null $parent of the searched node
     * @param string $left_right indicator of whether this node is left or right child of the parent
     * @return bool
     */
    public function delete($id, Node $parent = null, $left_right='')
    {
        if ($id > $this->student->id) {

            if ($this->right)
                return $this->right->delete($id, $this, 'right');

        } elseif ($id < $this->student->id) {

            if ($this->left)
                return $this->left->delete($id, $this, 'left');

        } elseif ($id === $this->student->id) {

            if ($this->left) {

                $parent->$left_right = $this->left;
                $this->left->insert($this->right);

            } elseif ($this->right) {

                $parent->$left_right = $this->right;
                $this->right->insert($this->left);

            } else
                $parent->$left_right = null;

            return true;
        }

        throw new UnexpectedValueException("Student with id $id not found");
    }

    public function find($id)
    {
        if ($id > $this->student->id) {

            if ($this->right)
                return $this->right->find($id);

        } elseif ($id < $this->student->id) {

            if ($this->left)
                return $this->left->find($id);

        } elseif ($id === $this->student->id)
            return $this->student;

        throw new UnexpectedValueException("Searched student id $id not found");
    }

    public function insert($node)
    {
        if ($node->student->id > $this->student->id)

            $this->right ?
                $this->right->insert($node) :
                $this->right = $node;

        elseif ($node->student->id < $this->student->id)

            $this->left ?
                $this->left->insert($node) :
                $this->left = $node;

        else
            throw new UnexpectedValueException("Duplicate student id " . $node->student->id);

    }
}
