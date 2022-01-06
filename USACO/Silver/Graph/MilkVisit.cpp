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
ll num = 0;
vector<vector<ll>> roads;
vector<bool> visited;
string milk;
vector<ll> comp;

void dfs(ll start){
    if(comp[start]) return;
    comp[start] = num;
    for(ll v : roads[start]){
        if(milk[start] == milk[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("milkvisits");
    cin >> n >> m;
    cin >> milk;
    roads.resize(n);
    comp.resize(n);
    for(ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    for(ll i = 0; i < n; i++){
        if(!comp[i]){
            num++;
            dfs(i);
        }
    }

    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        char c; cin >> c;
        if(milk[a] == c || comp[a] != comp[b]){
            cout << 1;
        } else{
            cout << 0;
        }
    }
}
