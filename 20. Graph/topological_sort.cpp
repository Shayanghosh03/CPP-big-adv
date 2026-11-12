#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class Graph {
    int v;
    list<int> *l;
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
            list<int> neighbor = l[u];
            cout << u << " ";
            for(int v : neighbor) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void topoSortHelper(int src, vector<bool> &vis, stack<int> & st) { // DFS based Topological Sort
        vis[src] = true;
        list<int> neighbor = l[src];

        for(int v : neighbor) {
            if(!vis[v]) {
                topoSortHelper(v, vis, st);
            }
        }
        st.push(src); // LIFO
    }

    void topoSort() {
        vector<bool> vis(v, false);
        stack<int> st;
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                topoSortHelper(i, vis, st);
            }
        }

        while(st.size() > 0) {
            cout << st.top() << " ";
            st.pop(); 
        }
        cout << endl;
    }

    void calcIndegree(vector<int> &indeg) {
        for(int u = 0; u < v; u++) {
            list<int> neighbor = l[u];
            for(int v : neighbor) {
                indeg[v]++;
            }
        }
    }

    void topoSort2() { // Khan's Algorithm (BFS Based)
        vector<int> indeg(v, 0);
        calcIndegree(indeg);
        queue<int> q;

        for(int i = 0; i < v; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> neighbor = l[curr];

            for(int v : neighbor) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort();
    cout << endl;

    graph.topoSort2();

    return 0;
}