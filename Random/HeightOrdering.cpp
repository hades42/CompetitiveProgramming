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

vector<ll> arr;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    arr.resize(20);

    for(ll i = 1; i <= t; i++){
        ll id; cin >> id;
        cout << id << " ";

        for(ll i = 0; i < 20; i++){
            cin >> arr[i];
        }
    
        ll count = 0;
        for(ll i = 0; i < arr.size() - 1; i++){
            for(ll j = i + 1; j < arr.size(); j++){
                if(arr[j] < arr[i]) count++;
            }
        }
        cout << count << endl;
    }
}
