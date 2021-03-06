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

string convert(ll k){
    string res;
    while(k > 0){
        res += ((k % 2) + '0');
        k /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void read(string num){
    for(ll i = 0; i < num.size(); i++){
        if(num[i] == '1') cout << "2";
        else cout << "0";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll k; cin >> k;
    string bi = convert(k);
    read(bi);
    return 0;
}
