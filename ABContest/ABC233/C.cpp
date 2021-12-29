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

ll n, x; 
ll ans = 0;
vector<vector<ll>> G;

void dfs(ll pos, ll amount){
    if(pos == n){
        if(amount == x){
            ans++;
        }
        return;
    }

    for(auto num : G[pos]){
        if(amount > (x/num)) continue;    
        dfs(pos+1, amount * num);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> x;
    G.resize(n);
    for(ll i = 0; i < n; i++){
        ll L; cin >> L; 
        G[i].resize(L);
        for(ll j = 0; j < L; j++) cin >> G[i][j];
    }
    //print2d(G);
    dfs(0, 1);
    cout << ans << endl;
}
