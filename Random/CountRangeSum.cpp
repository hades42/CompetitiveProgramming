#include <bits/stdc++.h>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using rb_tree = tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>;

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
    vector<ll> arr(n+1);
    for(ll i = 1; i <= n; i++){
        ll num; cin >> num;
        arr[i] = arr[i-1] + num;
    }
    print(arr);
    ll lower, upper; cin >> lower >> upper;
    rb_tree s;
    s.insert(0);
    ll res = 0;
    for(auto val : arr){
        ll right = s.order_of_key(val - lower);
        ll left = s.order_of_key(val - upper);
        res += (right - left);
        s.insert(val);
    }
    cout << res << endl;
}
