// Adjacency List
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int v;
    list<int>* l;
public:
    Graph(int v) {
        this -> v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u = 0; u < v; u++) {
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool hasPathHelper(int src, int des, vector<bool> &vis) {
        if(src == des) {
            return true;
        }

        vis[src] = true;
        list<int> neightbour = l[src];

        for(int v : neightbour) {
            if(!vis[v]) {
                if(hasPathHelper(v, des, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int src, int des) {
        vector<bool> vis(v, false);
        return hasPathHelper(src, des, vis);
    }

};

int main() {
    Graph graph(7);

    // Undirected Graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    cout << graph.hasPath(0, 5) << endl;

    return 0;
}