#include <utility>

namespace graph
{
    template <typename Index, typename Data>
    class Vertex
    {
    public:
        Vertex(Index id, const Data& data)
        : m_id(id)
        , m_data(data)
        {}

        Index id() const { return m_id; }
        Data data() const { return m_data; }

    private:
        Index m_id;
        Data m_data;
    }; // class Vertex

    template <typename Index>
    using Edge = std::pair<Index, Index>;

    template <typename Index, Directed>
    class AdjacencyMatrix
    {
    public:
        AdjacencyMatrix(size_t nodeCount);

        void addEdge(const Edge<Index>& edge);
        bool exists(const Edge<Index>& edge) const;
        bool exists(Index a, Index b) const;
    }; // class AdjacencyMatrix


    template <typename Vertex, Index, Directed>
    class Graph
    {
    public:
        Graph(size_t nodeCount);
        Graph(const AdjacencyMatrix<Index, Directed>& adjMatrix);
    }; // class Graph
} // namespace paleo