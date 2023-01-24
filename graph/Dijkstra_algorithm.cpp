// #include <iostream>
// using namespace std;
// #define VERTEX_NUM 9

// void printArray(int* array, int length){
//     cout << "Vertex\t\t Distance from source" << endl;
//     for (int i = 0; i < length; i++) {
//         cout << i << "\t\t\t\t" << array[i] << endl;
//     }
// }

// int findMin(int min_path_from_start[VERTEX_NUM], bool visited[VERTEX_NUM]) {
//     int min_index;
//     int min_val = INT_MAX;
//     for (int i = 0; i < VERTEX_NUM; i++) {
//         if (visited[i]) {
//             continue;
//         }
//         if (min_path_from_start[i] < min_val) {
//             min_val = min_path_from_start[i];
//             min_index = i;
//         }
//     }
//     return min_index;
// }

// void dijkstra(int graph[VERTEX_NUM][VERTEX_NUM], int start) {
//     bool visited[VERTEX_NUM];
//     int min_path_from_start[VERTEX_NUM];
//     for (int i = 0; i < VERTEX_NUM; i++) {
//         visited[i] = false;
//         min_path_from_start[i] = INT_MAX;
//     }
//     min_path_from_start[start] = 0;
    
//     for (int count = 0; count < VERTEX_NUM; count++){
//         int visiting = findMin(min_path_from_start, visited);

//         for (int j = 0; j < VERTEX_NUM; j++) {
//             if (graph[visiting][j]) {
//                 min_path_from_start[j] = min(min_path_from_start[j], min_path_from_start[visiting] + graph[visiting][j]);
//             }
//         }

//         visited[visiting] = true;
//     }

//     printArray(min_path_from_start, VERTEX_NUM);
// }

// int main () {
//     int graph[VERTEX_NUM][VERTEX_NUM] = 
//     { {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
//       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
//       {0, 8, 0, 7, 0, 0, 0, 0, 2}, 
//       {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
//       {0, 0, 0, 9, 0, 10, 0, 0, 0},
//       {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
//       {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
//       {8, 0, 0, 0, 0, 0, 1, 0, 7}, 
//       {0, 0, 2, 0, 0, 0, 6, 7, 0} };

//      dijkstra(graph, 0);
//      return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define VERTEX_NUM 9

// bool comp = [](pair<int, int> a, pair<int, int> b){return a.first < b.first;};

void printArray(int* array, int length){
    cout << "Vertex\t\t Distance from source" << endl;
    for (int i = 0; i < length; i++) {
        cout << i << "\t\t\t\t" << array[i] << endl;
    }
}

void dijkstra(int graph[VERTEX_NUM][VERTEX_NUM], int start) {
    vector<int> dist(VERTEX_NUM, INT_MAX);
    vector<bool> visited(VERTEX_NUM, false);
    // priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> pq(comp);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        for (int v = 0; v < VERTEX_NUM; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printArray(dist.data(), VERTEX_NUM);
}

int main() {
    int graph[VERTEX_NUM][VERTEX_NUM] = 
    { {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
      {0, 8, 0, 7, 0, 0, 0, 0, 2}, 
      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
      {0, 0, 0, 9, 0, 10, 0, 0, 0},
      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
      {8, 0, 0, 0, 0, 0, 1, 0, 7}, 
      {0, 0, 2, 0, 0, 0, 6, 7, 0} };

    dijkstra(graph, 0);
    return 0;
}