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

vector<ll> sum;
vector<vector<ll>> G;
ll color0 = 0, color1 = 0;
ll sum0 = 0, sum1 = 0;

void dfs(ll u, ll pu, ll color){
    if(color == 0){
        color0++;
        sum0 += sum[u];
    } else if(color == 1){
        color1++;
        sum1 += sum[u];
    }

    for(ll v : G[u]){
        if(v == pu) continue;
        dfs(v, u, 1 - color);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("clocktree");
    ll n; cin >> n;
    G.resize(n);
    sum.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> sum[i];
    }

    for(ll i =  0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1, 0);

    if((sum0 % 12) == (sum1 % 12)){
        cout << n << endl;
    } else if((sum0 + 1) % 12 == (sum1 % 12)){
        cout << color1 << endl;
    } else if((sum0 % 12) == (sum1 + 1) % 12){
        cout << color0 << endl;
    } else{
        cout << 0 << endl;
    }
}
