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

        $.each(Graph2.vertices, function (vertex, satelliteData) {

            // if all the paths have been followed
            if (vertex.nVisited == vertex.edges.length)
                return

            paths.push(Graph2.followPath(vertex))

        })
    }
    
    static followPath(vertex, pathLength = 0)
    {
        vertex.visited += 1

        if (vertex.edges.length){

            let visited = []

            $.each(vertex.edges, function (edge) {

                visited[edge.to] = followPath(edge.to)

            })
        } else
            return pathLength
    }

}

/**
 * Static property of the class Graph2 that holds all the vertices
 * @type {Array}
 */
Graph2.vertices = []