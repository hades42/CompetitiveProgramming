#include <bits/stdc++.h>
#include <sstream>
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

vector<ll> F;
vector<ll> C;

ll convert(ll num){
    return (num - 32) * 5 / 9;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string input;
    cin >> input;
    stringstream check1(input);
    string num;
    while (getline(check1, num, '/')) {
        F.push_back(stoll(num));
    }
    C.resize(2);
    bool neg = false;
    if(F[0] < 0 || F[1] < 0) neg = true;
    C[0] = convert(F[0]);
    C[1] = convert(F[1]);
    print(C);

    if(C[0] < 0){
        C[0] = -1 * C[0];
    }
    if(C[1] < 0){
        C[1] = -1 * C[1];
    }

    ll big = gcd(C[0], C[1]);
    if(neg) cout << "-";
    cout << C[0]/big << "/" << C[1]/big << endl;
}
