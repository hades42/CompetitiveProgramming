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

ll node, edge; 
vector<vector<pr>> G;
vector<bool> visited;
vector<ll> dis;

struct Edge{
    ll a;
    ll b;
    ll weight;
};

// O(nlogn)
void dijk(ll start){
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    dis[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        for(auto edge : G[curr.second]){
            ll b = edge.first;
            ll w = edge.second;
            if(dis[curr.second] + w < dis[b]){
                dis[b] = dis[curr.second] + w;
                pq.push({dis[b], b});
            }
        }
    }
} 

vector<Edge> allE;

//O(N*E)
void bellman(ll start){
    dis[start] = 0;
    for(ll i = 1; i <= node -1; i++){
        for(auto e : allE){
            ll a = e.a;
            ll b = e.b;
            ll w = e.weight;
            dis[b] = min(dis[b], dis[a] + w);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    /*
     *     1
     *  4 / \ 6
     *   5   2
     * 10 \  | 2
     *       3
     *       | 4 
     *       4
     *
     * */
    cin >> node >> edge;
    G.resize(node+1);
    visited.resize(node+1,false);
    dis.resize(node+1, INF);
    for(ll i = 0; i < edge; i++){
        ll u, v, weight;
        cin >> u >> v >> weight; 
        G[u].push_back({v, weight});
        G[v].push_back({u, weight});

        allE.push_back({u, v, weight});
        allE.push_back({v, u, weight});
    }

    //dijk(1);
    bellman(1);
    for(ll i = 1; i <= node; i++){
        cout << dis[i] << " ";
    }
}
