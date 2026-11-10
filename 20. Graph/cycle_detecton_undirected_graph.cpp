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
    bool isUndir;
public:
    Graph(int v, bool isUndir = true) {
        this -> v = v;
        l = new list<int> [v];
        this -> isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);

        if(isUndir) 
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

    bool isCycleDirHelper(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour) {
            if(!vis[v]) {
                if(isCycleDirHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;

        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(v, false);
        vector<bool> recPath(v, false);

        for(int i = 0; i < v; i++) {
            if(isCycleDirHelper(i, vis, recPath)) {
                return true;
            }
        }

        return false;
    }

};

int main() {
    Graph graph(7, false);

    // Undirected Graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    
    cout << graph.isCycleDir() << endl;

    return 0;
}