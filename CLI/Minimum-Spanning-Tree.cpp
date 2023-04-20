#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int i, vector<int>& parent) {
    if (parent[i] == -1) {
        return i;
    }
    return findParent(parent[i], parent);
}

void unionVertices(int x, int y, vector<int>& parent) {
    int xset = findParent(x, parent);
    int yset = findParent(y, parent);
    parent[xset] = yset;
}

vector<Edge> minimumSpanningTree(int V, vector<Edge> edges) {
    vector<Edge> result;
    vector<int> parent(V, -1);
    sort(edges.begin(), edges.end(), compareEdges);
    int i = 0, count = 0;
    while (count < V - 1) {
        Edge next = edges[i++];
        int x = findParent(next.src, parent);
        int y = findParent(next.dest, parent);
        if (x != y) {
            result.push_back(next);
            unionVertices(x, y, parent);
            count++;
        }
    }
    return result;
}

// Example Input

// Enter the number of vertices: 4
// Enter the edges (src, dest, weight):
// 0 1 2
// 1 2 3
// 2 3 1

// Output
// The minimum spanning tree is:
// 2 - 3 : 1
// 0 - 1 : 2
// 1 - 2 : 3

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<Edge> edges;
    int src, dest, weight;
    cout << "Enter the edges (src, dest, weight):" << endl;
    for (int i = 0; i < V-1; i++) {
        cin >> src >> dest >> weight;
        edges.push_back({src, dest, weight});
    }
    vector<Edge> MST = minimumSpanningTree(V, edges);
    cout << "The minimum spanning tree is:" << endl;
    for (Edge e : MST) {
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
    }
    return 0;
}
