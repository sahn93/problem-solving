#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int v, e, init;
vector< set<int> > graph;

void bfs(int start) {
    set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    set<int> adj;
    int e;
    while(!q.empty()) {
        e = q.front();
        q.pop();
        cout << e << " ";

        adj = graph[e-1];
        for (int a : adj) {
            // if not visited yet, check visited and add them into queue.
            if (visited.find(a) == visited.end()) {
                visited.insert(a);
                q.push(a);
                //cout << "push " << a << endl;
            }
        }
    }
    cout << endl;
}

void dfs(int start) {
    stack<int> s;
    s.push(start);

    set<int> visited;

    set<int> adj;
    int i;
    while(!s.empty()) {
        i = s.top();
        s.pop();
        if (visited.find(i) == visited.end()) {
            cout << i << " ";
            visited.insert(i);
            adj = graph[i-1];
            for (set<int>::reverse_iterator it = adj.rbegin(); it != adj.rend(); it++) {
                //cout << "pushed: " << *it << endl;
                s.push(*it);
            }
        }
    }
    cout << endl;
}
int main() {
    cin >> v >> e >> init;

    // initialize the graph to size v.
    graph.resize(v);

    // fill the adjacency list
    int from, to;
    for (int i=0; i<e; i++) {
        cin >> from >> to;
        // undirected graph, ascending order.
        graph[from-1].insert(to);
        graph[to-1].insert(from);
    }

    //for (int i=0; i<e; i++) {
        //for (int j: graph[i]) {
            //cout << j;
        //}
        //cout << endl;
    //}

    dfs(init);
    bfs(init);
}
