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

ll n, m; 
vector<vector<pair<ll, char>>> G;
vector<bool> vis;
vector<ll> color;
bool imp = false;

void dfs(ll u, ll c){
    vis[u] = true;
    color[u] = c;

    for(auto v : G[u]){
       if(!vis[v.first]){
           if(v.second == 'S'){
               dfs(v.first, c);
           } else{
               dfs(v.first, !c);
           }
       } else{
           if(v.second == 'S' && color[v.first] != c){
               imp = true;
           }
           if(v.second == 'D' && color[v.first] == c){
               imp = true;
           }
       }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("revegetate");
    cin >> n >> m;
    G.resize(n);
    vis.resize(n, false);
    color.resize(n);
    for(ll i = 0; i < m; i++){
        char a;
        ll b, c;
        cin >> a >> b >> c;
        b--; c--;
        G[b].push_back({c, a});
        G[c].push_back({b, a});
    }

    ll component = 0;
    for(ll i = 0; i < n; i++){
        if(!vis[i]){
            component++;
            dfs(i, 0);
        }
    }

    if(imp){
        cout << 0 << endl;
    } else{
        cout << 1;
        while(component--){
            cout << 0;
        }
    }
}
