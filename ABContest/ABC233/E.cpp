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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string input; cin >> input;
    ll sum = 0; ll carry = 0;
    for(char c : input){
        sum += c - '0';
    }
    string ans = "";
    for(ll i = input.size() - 1;; i--){
        carry += sum;
        ans.push_back((carry % 10) + '0');
        carry /= 10;
        if(i >= 0){
            sum -= input[i] - '0';
        }
        if(i <= 0 && carry == 0){
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
