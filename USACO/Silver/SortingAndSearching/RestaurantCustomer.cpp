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

vector<pr> arr;
vector<ll> indicies;
vector<ll> interval(4e5+5);
vector<ll> diffArray(4e5+5);

ll compress(ll num){
    return lower_bound(indicies.begin(), indicies.end(), num) - indicies.begin();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        arr.push_back({a, b});
        indicies.push_back(a);
        indicies.push_back(b);
    }

    sort(indicies.begin(), indicies.end());
    indicies.erase(unique(indicies.begin(), indicies.end()), indicies.end());

    for(ll i = 0; i < n; i++){
        diffArray[compress(arr[i].first) + 1] += 1; 
        diffArray[compress(arr[i].second) + 2] -= 1; 
    }
    //print(indicies);

    //for(ll i = 0; i <= 15; i++){
        //cout << diffArray[i] << " ";
    //}
    //cout << endl;

    for(ll i = 1; i < indicies.size(); i++){
        interval[i] = interval[i-1] + diffArray[i];
    }

    //for(ll i = 0; i <= 15; i++){
        //cout << interval[i] << " ";
    //}
    
    ll res = 0;
    for(ll i = 0; i < indicies.size(); i++){
        res = max(res, interval[i]);
    }
    cout << res << endl;
}
