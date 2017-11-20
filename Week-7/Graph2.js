/**
 * Created by oscar on 19/11/2017.
 */
/**
 * Created by oscar on 19/11/2017.
 */

/**
 * Graph2 Unweighted and undirected graph data structure
 */
class Graph2
    // TODO create vertex validation
{
    /**
     * Add a value
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

            // indicates how many times the vertex has been
            // visited while seeking the longest path
            Graph2.vertices[value]["visited"]  = 0
        }
    }

    static vertexExists(vertex)
    {
        if (isPositiveInteger(vertex))

            if ($.inArray(vertex, getKeys(Graph2.vertices)) != -1)
                return true

        throw new VertexNotIdentifiedException(vertex)

    }
    
    
    static findLongestSimplePath()
    {
        //TODO reset visited properties

        paths = []

        $.each(Graph2.vertices, function (vertex) {

            // if all the paths of vertex already have been followed
            if (vertex.nVisited == vertex.edges.length)
                return

            else {

                $.each(vertex.edges, function (edge) {

                    paths[vertex] = [Graph2.followPath(edge.to, edge.weight, [vertex])]
                })
            }
        })

        return Graph2.longestPathIn(paths)
    }
    
    static followPath(vertex, totalLength, waypoints = [])
    {
        // register followed path
        vertex.visited += 1

        let visited = []

        if (vertex.edges.length){

            $.each(vertex.edges, function (edge) {

                if (!edge.to in waypoints)

                    visited[edge.to] = Graph2.followPath(edge.to,
                                                         edge.length + totalLength,
                                                         waypoints.push(vertex))
            })
        }

        return visited.length ?
                  Graph2.longestPathIn(visited) :
                    {'length': totalLength, 'vertices': waypoints}
    }

    /**
     *
     * @param paths 2D array
     * @returns {{length: number, vertices: array}}
     */
    static longestPathIn(paths)
    {
        if (isArray(paths)) {

            let startingVertices = getKeys(paths)

            let maxPath = {'length': 0};

            startingVertices.forEach(function (sVertex) {

                if (paths[sVertex].length > maxPath.length)
                    maxPath = paths[sVertex]
            })
            return maxPath
        }
    }
}

/**
 * Static property of the class Graph2 that holds all the vertices
 * @type {Array}
 */
Graph2.vertices = []