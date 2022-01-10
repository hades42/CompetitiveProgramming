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

vector<vector<ll>> G;
vector<bool> visited;

void dfs(ll u, ll pu){
    visited[u] = true;
    for(ll v : G[u]){
        if(visited[v]){
            cout << v+1 << " ";
            return;
        }
        dfs(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    G.resize(n);
    for(ll i = 0; i < n; i++){
        ll num; cin >> num; num--;
        G[i].push_back(num);
    }

    for(ll i = 0; i < n; i++){
        vector<bool> temp(n, false);
        visited = temp; 
        dfs(i, -1);
    }
}
