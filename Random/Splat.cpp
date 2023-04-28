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

struct Color {
    double x, y, v;
    string color; 
};

void solve(){
    ll n; cin >> n;
    vector<Color> arr(n); 
    for(ll i = 0; i < n; i++){
        double x, y, v; string color;
        cin >> x >> y >> v >> color;
        arr[i].x = x;
        arr[i].y = y;
        arr[i].v = v;
        arr[i].color = color;
    }
    ll m; cin >> m;
    for(ll i = 0; i < m; i++){
        double x, y; cin >> x >> y;
        string curr = "white";
        for(ll j = 0; j < n; j++){
            double diff = (x - arr[j].x) * (x - arr[j].x) + (y - arr[j].y) * (y - arr[j].y);
            double radi = (arr[j].v) / (M_PI);
            if(diff <= radi){
                curr = arr[j].color;
            }
        }
        cout << curr << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
