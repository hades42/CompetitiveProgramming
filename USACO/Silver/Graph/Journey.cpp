#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> roads;

unordered_map<int, bool> visited;

double dfs(int pos) {
    double distance = 0;
    int num_path = 0;
    for (int city : roads[pos]) {
        if (!visited[city]) {
            visited[city] = true;
            distance += dfs(city) + 1;
            num_path++;
        }
    }

    if (num_path > 0){
        cout << distance << " " << num_path << endl;
        return distance / num_path;
    }
    else return 0.0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }

    visited[1] = true;
    double distance = dfs(1);

    cout.precision(numeric_limits<double>::max_digits10);
    cout << distance << '\n';
}
