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

bool cmp(pr a, pr b){
    if(a.first < b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("pairup");
    ll n; cin >> n;
    vector<pr> arr(n);
    for(ll i = 0; i < n; i++){
        ll num, milk;
        cin >> num >> milk;
        arr[i] = {milk, num}; 
    }
    sort(arr.begin(), arr.end());
    ll left = 0;
    ll right = n-1;
    ll ans = 0;
    while(left < right){
        if(arr[left].second && arr[right].second){
            ans = max(ans, arr[left].first + arr[right].first);
            arr[left].second -= 1;
            arr[right].second -= 1;
        } else if(arr[left].second <= 0){
            left++;
        } else if(arr[right].second <= 0){
            right--;
        }
    }
    cout << ans << endl;
}
