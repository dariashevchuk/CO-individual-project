#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    graph.reserve(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int D;
    cin >> D;  

    vector<bool> covered(N, false);

    vector<int> frogShops;
    frogShops.reserve(N);  

    for (int start = 0; start < N; start++) {
        if (!covered[start]) {
            frogShops.push_back(start);

            vector<int> dist(N, -1);
            queue<int> q;

            dist[start] = 0;
            covered[start] = true;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (dist[u] < D) {
                    for (int w : graph[u]) {
                        if (!covered[w]) {
                            covered[w] = true;
                            dist[w] = dist[u] + 1;
                            q.push(w);
                        }
                    }
                }
            }
        }
    }

    cout << (int)frogShops.size() << "\n";
    for (int i = 0; i < (int)frogShops.size(); i++) {
        cout << frogShops[i];
        if (i + 1 < (int)frogShops.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
