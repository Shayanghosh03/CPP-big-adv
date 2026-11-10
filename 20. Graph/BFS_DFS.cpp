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

    void BFS() { // O(v + E)
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbour = l[u];
            for(int v : neighbour) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        cout << endl;
    }

    void DFS(int u, vector<int> &vis) {
        vis[u] = true;
        cout << u << " ";

        list<int> neighbour = l[u];
        for(int v : neighbour) {
            if(!vis[v]) {
                DFS(v, vis);
            }
        }
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

    graph.print();

    graph.BFS();

    cout << endl;

    vector<int> vis(7, false);
    graph.DFS(0, vis);

    return 0;
}