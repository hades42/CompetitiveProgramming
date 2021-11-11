#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n;
  cin >> n;
  vector<ll> shop(n);
  for (ll i = 0; i < n; i++) {
    cin >> shop[i];
  }
  ll q;
  cin >> q;
  vector<ll> price;
  vector<ll> ans;
  for (ll i = 0; i < q; i++) {
    ll num;
    cin >> num;
    price.push_back(num);
    ans.push_back(num);
  }

  sort(shop.begin(), shop.end());
  sort(price.begin(), price.end());
  vector<ll> buy(q + 1);
  buy[0] = 0;
  ll track = 0;
  for (ll i = 1; i <= q; i++) {
    buy[i] += buy[i - 1];
    ll canBuy = 0;
    for (; track < n; track++) {
      if (price[i - 1] >= shop[track]) {
        canBuy++;
      } else {
        break;
      }
    }
    buy[i] += canBuy;
  }
  map<ll, ll> m;
  for (ll i = 0; i < q; i++) {
    m[price[i]] = buy[i + 1];
  }

  for (ll i = 0; i < q; i++) {
    cout << m[ans[i]] << endl;
  }
}
