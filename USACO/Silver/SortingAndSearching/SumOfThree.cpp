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
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, target; cin >> n >> target;
    vector<pr> arr(n);
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        arr[i] = {num, i};
    }
    sort(arr.begin(), arr.end(), cmp);
    for(ll i = 0; i < n -2; i++){
        ll left = i + 1;
        ll right = n - 1;
        while(left < right){
            if(arr[i].first + arr[left].first + arr[right].first == target){
                cout << arr[i].second + 1 << " " << arr[left].second + 1 << " " << arr[right].second + 1 << endl;
                return 0;
            } else if( arr[i].first + arr[left].first + arr[right].first > target){
                right--;
            } else if(arr[i].first + arr[left].first + arr[right].first < target){
                left++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
