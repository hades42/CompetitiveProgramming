#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<ll>> graph;
vector<bool> visited;

void dfs(ll u){
    cout << u << " ";
    visited[u] = true;
    for(auto v : graph[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void bfs(ll u){
    queue<ll> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        ll curr = q.front();
        cout << curr << " ";
        q.pop();
        for(auto v : graph[curr]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    /*
     *     1
     *    / \
     *   5   2
     *       |
     *       3
     *       |
     *       4
     *
     * */
    ll node; ll edge;
    cin >> node >> edge;
    graph.resize(node + 1);
    visited.resize(node + 1, false);
    for(ll i = 0; i < edge; i++){
        ll a; ll b;
        cin >> a >> b;
        graph[a].push_back(b); 
        graph[b].push_back(a);
    }
    //dfs(1);
    //bfs(1);
}
