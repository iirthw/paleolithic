#include <utility>

namespace graph
{
    // ---------------------------------------------------------------------
    // Vertex
    // ---------------------------------------------------------------------
    template <typename VertexIndex, typename Data>
    class Vertex
    {
    public:
        Vertex(VertexIndex id, const Data& data)
        : m_id(id)
        , m_data(data)
        {}

        VertexIndex id() const { return m_id; }
        Data data() const { return m_data; }

    private:
        VertexIndex m_id;
        Data m_data;
    }; // class Vertex

    // ---------------------------------------------------------------------
    // Edge
    // ---------------------------------------------------------------------
    template <typename VertexIndex, typename EdgeAttribute>
    struct Edge
    {
        VertexIndex begin;
        VertexIndex end;
        EdgeAttribute attrib;
    }; // struct Edge
 
    // ---------------------------------------------------------------------
    // AdjacencyMatrix
    // ---------------------------------------------------------------------
    template <typename VertexIndex, typename EdgeAttribute, typename Directed>
    class AdjacencyMatrix
    {
    public:
        AdjacencyMatrix(size_t nodeCount);

        void addEdge(const Edge<VertexIndex, EdgeAttribute>& edge);
        bool exists(const Edge<VertexIndex, EdgeAttribute>& edge) const;
        bool exists(VertexIndex a, VertexIndex b) const;
    }; // class AdjacencyMatrix

    // ---------------------------------------------------------------------
    // Graph
    // ---------------------------------------------------------------------
    template <typename Vertex, typename VertexIndex,
        typename EdgeAttribute,  typename Directed>
    class Graph
    {
    public:
        Graph(size_t nodeCount);
        Graph(const AdjacencyMatrix<VertexIndex, EdgeAttribute, Directed>& adjMatrix);
    }; // class Graph
} // namespace paleo