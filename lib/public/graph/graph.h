#include <utility>
#include <vector>

namespace graph
{
    // -------------------------------------------------------------------------
    // Vertex
    // -------------------------------------------------------------------------
    template <typename VertexIndex, typename Data>
    class Vertex
    {
    public:
        Vertex(VertexIndex id, const Data& data)
        : mId(id)
        , mData(data)
        {}

        VertexIndex id() const { return mId; }
        Data data() const { return mData; }

    private:
        VertexIndex mId;
        Data mData;
    }; // class Vertex

    // -------------------------------------------------------------------------
    // Edge
    // -------------------------------------------------------------------------
    template <typename VertexIndex, typename EdgeAttribute>
    struct Edge
    {
        VertexIndex begin;
        VertexIndex end;
        EdgeAttribute attrib;
        int id;
    }; // struct Edge
 
    // -------------------------------------------------------------------------
    // AdjacencyMatrix
    // -------------------------------------------------------------------------
    template <typename VertexIndex, typename EdgeAttribute, typename Directed>
    class AdjacencyMatrix
    {
    public:
        AdjacencyMatrix(size_t nodeCount);

        void addEdge(const Edge<VertexIndex, EdgeAttribute>& edge);
        bool exists(const Edge<VertexIndex, EdgeAttribute>& edge) const;
        bool exists(VertexIndex a, VertexIndex b) const;

    private:
        std::vector<std::vector<bool>> mAdjMatrix;
    }; // class AdjacencyMatrix

    // -------------------------------------------------------------------------
    // Graph
    // -------------------------------------------------------------------------
    template <typename Vertex, typename VertexIndex,
        typename EdgeAttribute,  typename Directed>
    class Graph
    {
    public:
        Graph(size_t nodeCount);
        Graph(const AdjacencyMatrix<VertexIndex, EdgeAttribute, Directed>& adjMatrix);
    }; // class Graph
} // namespace paleo