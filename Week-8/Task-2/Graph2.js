/**
 * Created by oscar on 19/11/2017.
 */

"use strict"

/**
 * Graph2 Unweighted and undirected graph data structure
 */
class Graph2
{
    /**
     * The code base is taken from Week 7 task 2
     *
     * Set a vertex and its edges. The edges must have
     * existent vertices on the both side, or exception
     * is thrown.
     *
     * @param value value
     * @param edges
     */
    static setVertex(value, edges = [])
    {
        if (isPositiveInteger(value) && isArray(edges)) {

            edges.forEach(function (edge) {

                checkIfEdgeOK(edge)

            })

            Graph2.vertices[value]             = []

            Graph2.vertices[value]["edges"]    = edges
        }
    }

    /**
     * The method checks whether the input value is a valid vertex value
     * @param vertex
     * @returns {boolean}
     */
    static vertexExists(vertex)
    {
        if (isPositiveInteger(vertex))

            if ($.inArray(vertex, getKeys(Graph2.vertices)) != -1)
                return true

        throw new VertexNotIdentifiedException(vertex)

    }

    /**
     * Traverses over each vertex and follows the paths.
     * Then Graph2.followPath() recursively searches for
     * the longest path.
     *
     * @returns {{length: number, vertices: array}}
     */
    static findShortestHamiltonCycle()
    {
        let paths = []

        getKeys(Graph2.vertices).forEach( function (vertexValue) {

            let vertex = Graph2.vertices[vertexValue]

                vertex.edges.forEach(function (edge) {

                    paths = paths.concat( Graph2.followPath(edge.to,
                                                            edge.weight,
                                                            [vertexValue]))
                })
            }
        )

        return Graph2.shortestPathIn(paths)
    }

    /**
     * Recursively follows each path/edge of the vertex
     *
     * @param vertexValue original vertex value
     * @param totalLength
     * @param Array waypoints visited vertices in the path
     * @returns {*}
     */
    static followPath(vertexValue, totalLength, waypoints)
    {

        // clone the waypoints array, so that different recursion branches
        // use different copy of the array
        let waypoints1 = waypoints.slice()
        waypoints1.push(vertexValue)

        // get the satellite data of the vertex
        let vertex = Graph2.vertices[vertexValue]

        let visited = []

        if (vertex.edges.length){

            vertex.edges.forEach( function (edge) {


                if (! waypoints1.includes(edge.to)){

                    visited = visited.concat( Graph2.followPath(edge.to,
                                                                edge.weight + totalLength,
                                                                waypoints1))
                }
            })
        }

        return visited.length ?
                    visited :
                        {'length': totalLength, 'vertices': waypoints1}
    }

    /**
     * Find the path with the largest .length value
     * @param paths 2D array
     * @returns {{length: number, vertices: array}}
     */
    static shortestPathIn(paths)
    {
        if (isArray(paths)) {

            let minPath = paths[0];
            let found   = false;

            paths.forEach(function (path) {

                if (path.length < minPath.length && path.vertices.length === getKeys(Graph2.vertices).length) {

                    minPath = path
                    found = true;
                }
            })


            return minPath;
        }
    }
}

/**
 * Static property of the class Graph2 that holds all the vertices
 * @type {Array}
 */
Graph2.vertices = []