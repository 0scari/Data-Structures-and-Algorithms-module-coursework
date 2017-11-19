/**
 * Created by oscar on 19/11/2017.
 */

class Vertex
{
    constructor(value, edges)
    {
        this.valueOf = value

        this.edges = []

        $.each(edges, function (edge) {

            if(Graph2.vertexExists(edge.to))

                this.edges.push(edge)
        })
    }


}