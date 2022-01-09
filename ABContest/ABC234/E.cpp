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

set<ll> nums;

void precompute(){
    for(ll init = 1; init <= 9; init++){
        for(ll d = -9; d <= 8; d++){
            string curr;
            int diff = init;
            for(ll i = 1; i <= 18; i++){
                curr += (diff + '0');
                nums.insert(stoll(curr));
                diff += d;
                if(!(diff >= 0 && diff <= 9)) break;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    precompute();
    ll n; cin >> n;
    auto it = nums.lower_bound(n);
    cout << *it << endl;
}
