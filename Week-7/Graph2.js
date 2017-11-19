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
    static addVertex(value, edges = [])
    {
        if (isPositiveInteger(value) && isArray(edges)) {

            edges.forEach(function (edge) {

                checkIfEdgeOK(edge)

            })

            Graph2.vertices[value] = edges
        }
    }

    /**
     * Edit the given vertex's neighbours
     * @param vertex
     * @param newNeighbours
     */
    static editVertex(vertex, newNeighbours = []) {

        if (Graph2.vertexExists(vertex) && isArray(newNeighbours)) {

            let oldNeighbours       = Graph2.vertices[vertex]
            Graph2.vertices[vertex] = newNeighbours

            $.each(newNeighbours, function (key, newNeighbour) {

                alert(newNeighbour)

                // new neighbour must be a registered vertex
                if ($.inArray(newNeighbour, getKeys(Graph2.vertices)) === -1)
                    throw new VertexNotIdentifiedException(newNeighbour)

                // if not in oldNeighbours
                if ($.inArray(newNeighbour, oldNeighbours) === -1)

                // register with the neighbour the edge to the vertex
                    Graph2.vertices[newNeighbour].push(vertex)

                else // remove
                    oldNeighbours.splice( $.inArray(newNeighbour, oldNeighbours), 1 );
                alert(oldNeighbours)
            })

            if (oldNeighbours.length) // if the old neighbours not present in new neighbours

            // remove the edge
                $.each(oldNeighbours, function (key, oldNeighbour) {

                    Graph2.vertices[oldNeighbour].splice($.inArray(vertex, Graph2.vertices[oldNeighbour]), 1);

                })
        }
    }

    static vertexExists(vertex)
    {
        if (isPositiveInteger(vertex))

            if ($.inArray(vertex, getKeys(Graph2.vertices)) != -1)
                return true

        throw new VertexNotIdentifiedException(vertex)

    }

    /**
     * Traverse through the vertices using DFT and return whether or not the quantity of visited vertices
     * is the same as the total quantity of vertices.
     * @returns {boolean}
     */
    static isConnectedDFT()
    {
        let v, vertices = getKeys(Graph2.vertices)

        if (v = vertices.pop()) {

            let neighbours = [];

            let visited = []

            neighbours.push(v)

            while (neighbours.length) {

                let neighbour = neighbours.pop()

                if ($.inArray(neighbour, visited) === -1) {

                    visited.push(neighbour);

                    Graph2.vertices[neighbour].forEach(function (edge) {

                        neighbours.push(edge)
                    })
                }
            }

            return visited.length === getKeys(Graph2.vertices).length

        } else

            return false
    }
}

/**
 * Static property of the class Graph2 that holds all the vertices
 * @type {Array}
 */
Graph2.vertices = []