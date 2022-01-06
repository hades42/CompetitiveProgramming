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

vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;
ll k, v;
ll curr = INF;
ll sol;

void dfs(ll u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v.first]){
            if(v.second >= k){
                sol++;
                dfs(v.first);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("mootube");
    ll n, q; cin >> n >> q;
    adj.resize(n);
    visited.resize(n, false);
    for(ll i = 0; i < n - 1; i++){
        ll p, q, r; cin >> p >> q >> r;
        p--; q--;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    for(ll i = 0; i < q; i++){
        cin >> k >> v;
        v--;
        sol = 0;  
        vector<bool> temp(n);
        visited = temp;
        dfs(v);
        cout << sol << endl;
    }
}
