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

ll maxN = 1e6;
vector<ll> maxDiv(maxN);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for(ll i = 2; i <= maxN; i++){
        if(maxDiv[i] == 0){
            for(ll j = i; j <= maxN; j+= i){
                maxDiv[j] = i;
            }
        }
    }

	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		int x;
		int div_num = 0;
		cin >> x;
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				div_num += i * i == x ? 1 : 2;
			}
		}
		cout << div_num << '\n';
	}
}
