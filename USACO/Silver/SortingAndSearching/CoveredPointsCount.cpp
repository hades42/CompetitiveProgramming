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
    ll n; cin >> n;
    vector<pr> segment(n);
    set<ll> points;
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        segment[i] = {a, b};
        points.insert(a);
        points.insert(b+1);
    }
    map<ll,ll> compress;
    vector<ll> coords;
    ll curr = 0;
    for(auto &c : points){
        compress[c] = curr;
        coords.push_back(c);
        curr++;
    }

    vector<ll> freq(2 * n);
    for(ll i = 0; i < n; i++){
        freq[compress[segment[i].first]]++;
        freq[compress[segment[i].second + 1]]--;
    }

    //for(auto pi : compress){
        //cout << pi.first << " " << pi.second << endl; 
    //}

    //print(freq);
    
    for(ll i = 1; i <= 2 * n; i++){
        freq[i] += freq[i-1];
    }
    //print(freq);

    vector<ll> ans(n+1);
    for(ll i = 1; i < coords.size(); i++){
        ans[freq[i-1]] += coords[i] - coords[i-1];
    }

    for(ll i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
