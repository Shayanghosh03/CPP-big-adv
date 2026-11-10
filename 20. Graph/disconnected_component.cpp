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

    void BFSHelper(int u, vector<bool> &vis) {
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            list<int> neighbour = l[curr];
            for(int v : neighbour) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        cout << endl;
    }

    void BFS() { // O(v + E)
        vector<bool> vis(v, false);
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                BFSHelper(i, vis);
            }
        }
        cout << endl;
    }

    void DFSHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;
        list<int> neighbour = l[u];

        for(int v : neighbour) {
            if(!vis[v]) {
                DFSHelper(v, vis);
            }
        }
    }

    void DFS() {
        vector<bool> vis(v, false);
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                DFSHelper(i, vis);
            }
        }
        cout << endl;
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

    cout << endl;

    return 0;
}