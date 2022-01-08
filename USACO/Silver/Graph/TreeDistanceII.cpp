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
vector<ll> dist;
vector<ll> dp;
ll n; 

void dfs(ll u, ll pu, ll depth){
    dist[0] += depth;
    dp[u] = 1;
    for(ll v : G[u]){
        if(v == pu) continue;
        dfs(v, u, depth+1);
        dp[u] += dp[v];
    }

};

void dfs2(ll u, ll pu){
    for(ll v : G[u]){
        if(v == pu) continue;
        dist[v] = dist[u] + n - 2* dp[v];
        dfs2(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    G.resize(n);
    dist.resize(n);
    dp.resize(n);
    for(ll i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1, 0);
    dfs2(0, -1);
    print(dist); 
}
