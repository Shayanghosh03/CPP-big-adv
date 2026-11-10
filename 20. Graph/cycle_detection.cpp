// Adjacency List
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

    bool isCycleHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour) {
            if(!vis[v]) {
                if(isCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if(v != par) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(v, false);
        return isCycleHelper(0, -1, vis);
    }

};

int main() {
    Graph graph(7);

    // Undirected Graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    
    cout << graph.isCycleUndir() << endl;

    return 0;
}