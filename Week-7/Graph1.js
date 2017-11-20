/**
 * Created by oscar on 19/11/2017.
 */

/**
 * Graph2 Unweighted and undirected graph data structure
 * BONUS TO ASSESSOR: vertex editing function
 */
class Graph1
{
    /**
     * Add a vertex
     * @param vertex value
     * @param neighbours
     */
    static addVertex(vertex, neighbours = [])
    {
       if (isPositiveInteger(vertex) && isArray(neighbours)) {

           // check whether the neighbours are registered vertices
           neighbours.forEach(function (neighbour) {

               let vertices = getKeys(Graph1.vertices)

               // if not in array
               if ($.inArray(neighbour, vertices) === -1)

                   throw new VertexNotIdentifiedException(neighbour)

               else // register with the neighbour the edge to the vertex

                   if ($.inArray(vertex, Graph1.vertices[neighbour]) === -1)
                       Graph1.vertices[neighbour].push(vertex)

           })

           Graph1.vertices[vertex] = neighbours
       }
    }

    /**
     * BONUS!!!!
     * Edit the given vertex's neighbours
     * @param vertex
     * @param newNeighbours
     */
    static editVertex(vertex, newNeighbours = []) {

        if (Graph1.vertexExists(vertex) && isArray(newNeighbours)) {

            let oldNeighbours       = Graph1.vertices[vertex]
            Graph1.vertices[vertex] = newNeighbours

            $.each(newNeighbours, function (key, newNeighbour) {

                // new neighbour must be a registered vertex
                if ($.inArray(newNeighbour, getKeys(Graph1.vertices)) === -1)
                    throw new VertexNotIdentifiedException(newNeighbour)

                // if not in oldNeighbours
                if ($.inArray(newNeighbour, oldNeighbours) === -1)

                    // register with the neighbour the edge to the vertex
                    Graph1.vertices[newNeighbour].push(vertex)

                else // remove
                    oldNeighbours.splice( $.inArray(newNeighbour, oldNeighbours), 1 );
            })

            if (oldNeighbours.length) // if the old neighbours not present in new neighbours

                // remove the edge
                $.each(oldNeighbours, function (key, oldNeighbour) {

                    Graph1.vertices[oldNeighbour].splice($.inArray(vertex, Graph1.vertices[oldNeighbour]), 1);

                })
        }
    }

    static vertexExists(vertex)
    {
        if (isPositiveInteger(vertex))

            if ($.inArray(vertex, getKeys(Graph1.vertices)) != -1)
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
        let v, vertices = getKeys(Graph1.vertices)

        if (v = vertices.pop()) {

            let neighbours = [];

            let visited = []

            neighbours.push(v)

            while (neighbours.length) {

                let neighbour = neighbours.pop()

                if ($.inArray(neighbour, visited) === -1) {

                    visited.push(neighbour);

                    Graph1.vertices[neighbour].forEach(function (edge) {

                        neighbours.push(edge)
                    })
                }
            }

            return visited.length === getKeys(Graph1.vertices).length

        } else

            return false
    }
}

/**
 * Static property of the class Graph2 that holds all the vertices
 * @type {Array}
 */
Graph1.vertices = []