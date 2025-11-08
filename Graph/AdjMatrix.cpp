#include <iostream>
#include <vector>
#include <queue>
class AdjMatrix {
private:

    std::vector<std::vector<int>> matrix;
    int n;

public:
    AdjMatrix(int vertCount) : n{vertCount}, matrix(vertCount, std::vector<int> (5,0)) {}

    void addEdge(int v, int u) {
        matrix[v][u] = matrix[u][v] = 1;
    }

    void dfsHelper(int start, std::vector<bool>& visited) {
        visited[start] = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[start][j] && !visited[j]) {
                dfsHelper(j,visited);
            }
        }
    }

    void dfsPrint(int start, std::vector<bool>& visited) {
        visited[start] = true;
        std::cout << start << " ";
        for (int j = 0; j < n; ++j) {
            if (matrix[start][j] && !visited[j]) {
                dfsPrint(j,visited);
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
            for (int j = 0; j < n; ++j) {
                if (matrix[node][j] && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
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
    AdjMatrix list1(6);
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