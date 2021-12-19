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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("herding");
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll empty = 0;
    for(ll i = 1; i < n; i++){
        empty += arr[i] - arr[i-1] - 1;
    }
    ll minStep = INF;  
    if(arr[n-2] - arr[0] == n -2 && arr[n-1] - arr[n-2] > 2){
        minStep = 2;
    } else if(arr[n-1] - arr[1] == n -2 && arr[1] - arr[0] > 2){
        minStep = 2;
    } else{
        ll right = 0;
        for(ll left = 0; left < n; left++){
            while(right + 1 < n && arr[right+1] - arr[left] < n){
                right++;
            }
            minStep = min(minStep, n - (right - left + 1));
        }
    }
    ll maxStep = max(empty - (arr[1] - arr[0] - 1), empty - (arr[n-1] - arr[n-2] - 1));
    cout << minStep << endl;
    cout << maxStep << endl;
}
