#include <utility>

namespace graph
{
    using Edge = std::pair<int, int>;

    class AdjacencyMatrix
    {
    public:
        AdjacencyMatrix(size_t nodeCount);

        void addEdge(const Edge& edge);
    }; // class AdjacencyMatrix


    template <typename T>
    class Graph
    {
    public:
        Graph(size_t nodeCount);
        Graph(const AdjacencyMatrix& adjMatrix);
    }; // class Graph
} // namespace paleo