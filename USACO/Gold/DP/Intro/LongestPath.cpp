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
ll ans = 0;

ll dfs(ll u){
    ll curr = -1;
    for(auto v : G[u]){
        if(dist[v] == -1){
            curr = max(curr, dfs(v));
        } else{
            curr = max(curr, dist[v]);
        }
    }
    return dist[u] = curr + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    //setIO("longpath");
    ll n, m; cin >> n >> m;
    G.resize(n);
    dist.resize(n, -1);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    for(ll i = 0; i < n; i++){
        if(dist[i] == -1){
            dfs(i);
        }
    }
    //print(dist);
    ans = *max_element(dist.begin(), dist.end());
    if(ans == -1){
        cout << 0 << endl;
    } else{
        cout << ans << endl;
    }
}
