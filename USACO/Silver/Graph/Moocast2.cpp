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

ll n;
vector<ll> X;
vector<ll> Y;
vector<vector<ll>> G;
vector<bool> visited;

void dfs(ll u){
    visited[u] = true;
    for(ll v: G[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

bool work(ll dis){
    for(ll i = 0; i < n; i++){
        vector<ll> temp;
        G[i] = temp;
        visited[i] = false;
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == j) continue;
            ll curr = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            if(curr <= dis){
                G[i].push_back(j);
            }
        }
    }
    
    dfs(0);
    for(ll i = 0; i < n; i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    G.resize(n);
    X.resize(n);
    Y.resize(n);
    visited.resize(n, false);

    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        X[i] = a;
        Y[i] = b;
    }
    
    ll left = 1;
    ll right = 1e18;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(work(mid)){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << left << endl;
}
