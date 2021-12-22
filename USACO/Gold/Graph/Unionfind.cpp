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

struct DSU{
    vector<ll> e;
    DSU(ll N){
        e = vector<ll>(N, -1);
    }

    ll get(ll x){
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
 
    bool sameSet(ll x, ll y){
        return get(x) == get(y);
    };

    bool size(ll x){
        return -e[get(x)];
    }

    bool unite(ll x, ll y){
        x = get(x);
        y = get(y);
        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main(){
    ll nodes; ll query;
    cin >> nodes >> query;
    DSU dsu(nodes);
    for(ll i = 0; i < query; i++){
        ll type, a, b; cin >> type >> a >> b;
        if(type == 1){
            if(dsu.sameSet(a, b)){
                cout << 1 << endl;
            } else{
                cout << 0 << endl;
            }
        } else{
            dsu.unite(a , b);
        } 
    }
}
