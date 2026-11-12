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

    bool isBipartite() {
        queue<int> q;
        vector<bool> vis(v, false);
        vector<int> color(v, -1);

        q.push(0);
        vis[0] = true;
        color[0] = 0;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            list<int> neighbor = l[curr];

            for(int v : neighbor) {
                if(!vis[v]) {
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

};

int main() {
    Graph graph(7);

    // Undirected Graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    
    cout << graph.isBipartite() << endl;

    return 0;
}