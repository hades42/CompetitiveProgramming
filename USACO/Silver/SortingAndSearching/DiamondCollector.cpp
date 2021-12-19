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
    setIO("diamond");
    ll n, k; 
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //print(arr);
    vector<ll> canTakeFromLeft(n);
    ll right = 0;
    for(ll left = 0; left < n; left++){
        while(right < n && arr[right] - arr[left] <= k) right++;
        canTakeFromLeft[left] = right - left;
    }
    vector<ll> maxValueAfterI(n+1);
    for(ll i = n - 1; i >= 0; i--){
        maxValueAfterI[i] = max(maxValueAfterI[i + 1], canTakeFromLeft[i]);
    }
    //print(canTakeFromLeft);
    //print(maxValueAfterI);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans = max(ans, canTakeFromLeft[i] + maxValueAfterI[canTakeFromLeft[i] + i]);
    }
    cout << ans << endl;
}
