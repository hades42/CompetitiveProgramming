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

vector<string> arr;
ll n; 

void search(ll k, string curr){
    if(k == n + 1){
        arr.push_back(curr);
        return;
    } else{
        search(k + 1, curr);
        curr += (k + '0');
        search(k + 1, curr);
        curr.pop_back();
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll m; cin >> n >> m;
    //set<int> cannot;
    set<pair<ll, ll>> cannot;
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        //a--; b--;
        //ll combine = (1 << a) | (1 << b);
        cannot.insert({a, b});
    }
    search(1, "");
    for(auto s : arr){
        for(auto pi : cannot){
        }
    }
}
