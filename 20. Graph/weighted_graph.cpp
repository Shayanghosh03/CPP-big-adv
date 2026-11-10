// Adjacency List
#include<iostream>
#include<list>
using namespace std;

class Graph {
    int v;
    list<pair<int, int>>* l;
public:
    Graph(int v) {
        this -> v = v;
        l = new list<pair<int, int>> [v];
    }

    void addEdage(int u, int v, int w) {
        l[u].push_back(make_pair(v, w));
        l[v].push_back(make_pair(u, w));
    }

    void print() {
        for(int u = 0; u < v; u++) {
            list<pair<int, int>> neighbour = l[u];
            cout << u << " : ";
            for(auto v : neighbour) {
                cout << "(" << v.first << ", " << v.second << ")" << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    // Weighted Graph
    graph.addEdage(0, 1, 5);
    graph.addEdage(1, 2, 1);
    graph.addEdage(1, 3, 3);
    graph.addEdage(2, 3, 1);
    graph.addEdage(2, 4, 2);

    graph.print();

    return 0;
}