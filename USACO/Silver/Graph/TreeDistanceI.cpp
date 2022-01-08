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

vector<vector<ll>> G(200005);
vector<ll> firstDist(200005);
vector<ll> secondDist(200005);
vector<ll> child(200005);

void dfs(ll v, ll p){
    firstDist[v] = 0;
    secondDist[v] = 0;
    for(ll x : G[v]){
        if(x == p) continue;
        dfs(x, v);
        if(firstDist[x] + 1 > firstDist[v]){
            secondDist[v] = firstDist[v];
            firstDist[v] = firstDist[x] + 1;
            child[v] = x;
        } else if(firstDist[x] + 1 > secondDist[v]){
            secondDist[v] = firstDist[x] + 1;
        }
    }
}

void dfs2(ll v, ll p){
    for(auto x : G[v]){
        if(x == p) continue;
        if(child[v] == x){
            if(firstDist[x] < secondDist[v] + 1){
                secondDist[x] = firstDist[x];
                firstDist[x] = secondDist[v] + 1;
                child[x] = v;
            } else{
                secondDist[x] = max(secondDist[v] + 1, secondDist[x]);
            }
        } else{
            secondDist[x] = firstDist[x];
            firstDist[x] = firstDist[v] + 1;
            child[x] = v;
        }
        dfs2(x, v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, -1);
    dfs2(1, -1);

    for(ll i = 1; i <= n; i++){
        cout << firstDist[i] << " ";
    }
}
