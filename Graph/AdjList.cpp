#include <iostream>
#include <vector>
#include <queue>
class AdjList {
private:

    std::vector<std::vector<int>> adj;
    int n;

public:
    AdjList(int vertCount) : n{vertCount}, adj(vertCount) {}

    void addEdge(int v, int u) {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void dfsHelper(int start, std::vector<bool>& visited) {
        visited[start] = true;
        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfsHelper(neighbor,visited);
            }
        }
    }

    void dfsPrint(int start, std::vector<bool>& visited) {
        visited[start] = true;
        std::cout << start << " ";
        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfsPrint(neighbor,visited);
            }
        }
    }
    void dfs(int start) {
        std::vector<bool> visited(n,false);
        dfsPrint(start,visited);
    }

    void bfs(int start) {
        std::vector<bool> visited(n,false);
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()) {
            int node = q.front();
            std::cout << node << " ";
            q.pop();
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int getNumComponents() {
        std::vector<bool> visited(n,false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfsHelper(i,visited);
                ++count;
            }
        }
        return count;
    }
};

int main() {
    AdjList list1(6);
    list1.addEdge(0,1);
    list1.addEdge(1,2);
    list1.addEdge(2,3);
    list1.addEdge(4,5);
    list1.dfs(0);
    list1.dfs(4);
    std::cout << std::endl;
    list1.bfs(0);
    std::cout << "Number of components of the graph is " << list1.getNumComponents() << std::endl;

}
