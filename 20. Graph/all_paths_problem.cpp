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

    void pathHelper(int src, int des, vector<bool> &vis, string &path) {
        if(src == des) {
            cout << path << des << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbor = l[src];

        for(int v : neighbor) {
            if(!vis[v]) {
                pathHelper(v, des, vis, path);
            }
        }

        path = path.substr(0, path.length() - 1);
        vis[src] = false;
    }

    void printAllPaths(int src, int des) {
        vector<bool> vis(v, false);
        string path = "";
        pathHelper(src, des, vis, path);
    }

};

int main() {
    Graph graph(6, false);

    // Undirected Graph
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);

    cout << endl;

    graph.print();

    return 0;
}