#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
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


struct Cow{
    ll x;
    ll y;
    ll id;
};

vector<Cow> E;
vector<Cow> N;

bool cmpE(Cow &a, Cow &b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmpN(Cow &a, Cow &b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        string dir;
        ll x, y;
        cin >> dir >> x >> y;
        if(dir == "E"){
            E.push_back({x, y, i + 1});
        } else{
            N.push_back({x, y, i + 1});
        }
    }
    sort(E.begin(), E.end(), cmpN);
    sort(N.begin(), N.end(), cmpE);

    vector<bool> stop(2501);
    vector<ll> blame(2501);

    for(ll i = 0; i < E.size(); i++){
        for(ll j = 0; j < N.size(); j++){
            if(!stop[E[i].id] && !stop[N[j].id] && E[i].x <=  N[j].x && E[i].y >= N[j].y){
                ll diffx = N[j].x - E[i].x;
                ll diffy = E[i].y - N[j].y;
                
                if(diffx < diffy){
                    stop[N[j].id] = true;
                    blame[E[i].id] += 1 + blame[N[j].id];
                } else if(diffy < diffx){
                    stop[E[i].id] = true;
                    blame[N[j].id] += 1 + blame[E[i].id];
                }
            }
        }
    }

    for(ll i = 1; i <= n; i++){
        cout << blame[i] << endl;
    }
}
