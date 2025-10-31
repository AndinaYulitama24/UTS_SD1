#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge {
    int dest, weight;   
    Edge(int d, int w) { dest = d; weight = w; }
};
void DFS(int node, vector< vector<Edge> >& graph, vector<bool>& visited, char kota[]) {
    visited[node] = true;       
    cout << kota[node];         
    for (int i = 0; i < graph[node].size(); i++) {
        Edge edge = graph[node][i];
        if (!visited[edge.dest]) { 
            cout << " -> ";
            DFS(edge.dest, graph, visited, kota);
        }
    }
}
void BFS(int start, int goal, vector< vector<Edge> >& graph, char kota[], string namaKota[]) {
    queue<int> q;               
    vector<int> parent(5, -1);  
    vector<bool> visited(5, false); 
    
    q.push(start);             
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == goal)    
            break;
            
        for (int i = 0; i < graph[current].size(); i++) {
            Edge edge = graph[current][i];
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                parent[edge.dest] = current;  
                q.push(edge.dest);
            }
        }
    }
    vector<int> path;
    int temp = goal;
    while (temp != -1) {
        path.push_back(temp);
        temp = parent[temp];   
    }
    reverse(path.begin(), path.end()); 
    
    int totalJarak = 0;
    
    cout << "\n\nJALUR TERCEPAT KAK PARUL (BFS):\n";
    for (int i = 0; i < path.size(); i++) {
        cout << namaKota[path[i]] << " (" << kota[path[i]] << ")";
        if (i != path.size() - 1) {
            for (int j = 0; j < graph[path[i]].size(); j++) {
                if (graph[path[i]][j].dest == path[i + 1]) {
                    cout << "\n" << graph[path[i]][j].weight << "m\n";
                    totalJarak += graph[path[i]][j].weight;
                    break;
                }
            }
        }
        cout << endl;
    }
    cout << "Jalur terpendek: ";
    for (int i = 0; i < path.size(); i++) {
        cout << kota[path[i]];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal langkah: " << path.size() - 1 << " edge";
    cout << "\nTotal jarak: " << totalJarak << " meter\n";
}

int main() {
    int n = 5; 
    char kota[] = {'A', 'B', 'C', 'D', 'E'};
    
    string namaKota[] = {
        "Ikan Bakar Pak Harry",    // A
        "Gudang Kaleng Bekas",     // B
        "Sushi Kucing Alya",       // C
        "Kedai IKLC",              // D
        "Pasar Ikan Tengah Malam"  // E
    };
    
    vector< vector<Edge> > graph(n);
    
    graph[0].push_back(Edge(1, 5)); 
    graph[1].push_back(Edge(0, 5));
    
    graph[0].push_back(Edge(2, 2)); 
    graph[2].push_back(Edge(0, 2));
    
    graph[1].push_back(Edge(3, 4)); 
    graph[3].push_back(Edge(1, 4));
    
    graph[2].push_back(Edge(3, 1)); 
    graph[3].push_back(Edge(2, 1));
    
    graph[3].push_back(Edge(4, 3)); 
    graph[4].push_back(Edge(3, 3));
    
    cout << "PENJELAJAHAN PARUL (DFS dari A):\n";
    vector<bool> visited(n, false);
    DFS(0, graph, visited, kota);
    BFS(0, 4, graph, kota, namaKota);
    
    return 0;
}