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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll C, n; cin >> C >> n;
    vector<vector<ll>> arr(n, vector<ll>(3));
    //0 : in;
    //1 : leave;
    //0 : stay;
    for(ll i = 0;i < n; i++){
        for(ll j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    ll curr = 0;
    for(ll i = 0; i < n; i++){
        // left
        curr -= arr[i][0];
        if(curr < 0){
            cout << "impossible" << endl;
            return 0;
        } 
        // go in
        curr += arr[i][1];
        if(curr > C){
            cout << "impossible" << endl;
            return 0;
        }
        // stay
        if(arr[i][2] > 0 && curr < C){
            cout << "impossible" << endl;
            return 0;
        }
    }
    if(curr > 0){
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    return 0;
}
