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
    string in1;
    string in2;
    cin >> in1 >> in2;
    ll k;
    if(in1[0] > in2[0]){
        k = 26 - (in1[0]) + in2[0];
    } else{
        k = in2[0] - in1[0];
    }
    //cout << k << endl;
    for(ll i = 1; i < in1.size(); i++){
        ll temp;
        if(in1[i] > in2[i]){
            temp = 26 - (in1[i]) + in2[i];
        } else{
            temp = in2[i] - in1[i];
        }
        if(temp != k) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
