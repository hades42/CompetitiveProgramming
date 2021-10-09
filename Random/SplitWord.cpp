#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <utility>
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

ll minCut(vector<ll> cutList, ll n) {
  if (cutList.size() == 0) {
    return 0;
  }
  if (cutList.size() == 1) {
    if (cutList[0] > n || cutList[0] < 1)
      return 0;
  }
  ll minCost = INT_MAX;
  for (auto k : cutList) {
    vector<ll> leftSplit, rightSplit;
    for (auto x : cutList) {
      if (x < k) {
        leftSplit.push_back(x);
      } else if (x > k) {
        rightSplit.push_back(x - k);
      }
    }
    cout << "This is k: " << k << endl;
    print(leftSplit);
    print(rightSplit);
    ll lcost = minCut(leftSplit, k);
    ll rcost = minCut(rightSplit, n - k);
    ll cost = n + lcost + rcost;
    if (cost < minCost) {
      minCost = cost;
    }
  }
  return minCost;
}

ll minCut2(vector<ll> cutList, ll n) {
  print(cutList);
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INT_MAX));
  for (ll gap = 1; gap <= n; gap++) {
    cout << endl;
    for (ll i = 0, j = i + gap; j <= n; j++, i++) {
      cout << i << " " << j << endl;
      if (gap == 1) {
        dp[i][j] = 0;
      } else {
        ll min = INT_MAX;
        for (ll m = 0; m < cutList.size(); m++) {
          if (cutList[m] < j && cutList[m] > i) {
            ll cost = (j - i) + dp[i][cutList[m]] + dp[cutList[m]][j];
            if (cost < min) {
              min = cost;
              cout << cutList[m] << " " << i << " " << j << endl;
            }
          }
        }
        if (min >= INT_MAX) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = min;
        }
        cout << "dp[" << i << "]"
             << "[" << j << "]"
             << "= " << dp[i][j] << endl;
      }
    }
  }
  print2d(dp);
  cout << endl;
  ll curr = dp[0][n];
  vector<ll> res;
  queue<pair<ll, ll>> q;
  q.push(make_pair(0, n));
  while (!q.empty()) {
    pair<ll, ll> curr = q.front();
    cout << curr.second << " " << curr.first << endl;
    q.pop();
    for (auto cut : cutList) {
      if (dp[curr.first][cut] + dp[cut][curr.second] +
              (curr.second - curr.first) ==
          dp[curr.first][curr.second]) {
        res.push_back(cut);
        cout << curr.first << " " << cut << endl;
        cout << cut << " " << curr.second << endl;
        q.push(make_pair(curr.first, cut));
        q.push(make_pair(cut, curr.second));
      }
    }
    cout << endl;
  }
  for (auto &num : res) {
    num--;
  }
  if (res.size() == cutList.size() * 2) {
    for (int i = 0; i < res.size() / 2; i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  } else {
    print(res);
  }
  return dp[0][n];
}

ll minCut3(vector<ll> cutList, ll n) {
  print(cutList);
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INT_MAX));
  for (ll gap = 0; gap < n; gap++) {
    cout << endl;
    for (ll i = 1, j = i + gap; j <= n; j++, i++) {
      cout << i << " " << j << endl;
      if (gap == 0) {
        dp[i][j] = 0;
      } else {
        ll min = INT_MAX;
        for (ll m = 0; m < cutList.size(); m++) {
          cout << i << " " << j << " " << cutList[m] << endl;
          if (cutList[m] < j && cutList[m] >= i) {
            ll cost = (j - i + 1) + dp[i][cutList[m]] + dp[cutList[m] + 1][j];
            cout << cutList[m] << " " << i << " " << j << endl;
            if (cost < min) {
              min = cost;
              cout << (j - i + 1) << " " << dp[i][cutList[m]] << " "
                   << dp[cutList[m] + 1][j] << endl;
              cout << cutList[m] << " " << i << " " << j << endl;
            }
          }
        }
        if (min >= INT_MAX) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = min;
        }
        cout << "dp[" << i << "]"
             << "[" << j << "]"
             << "= " << dp[i][j] << endl;
      }
    }
  }
  print2d(dp);

  // cout << endl;
  ll curr = dp[1][n];
  vector<ll> res;
  queue<pair<ll, ll>> q;
  q.push(make_pair(1, n));
  while (!q.empty()) {
    pair<ll, ll> curr = q.front();
    q.pop();
    for (auto cut : cutList) {
      if (dp[curr.first][cut] + dp[cut + 1][curr.second] +
              (curr.second - curr.first + 1) ==
          dp[curr.first][curr.second]) {
        res.push_back(cut);
        q.push(make_pair(curr.first, cut));
        q.push(make_pair(cut + 1, curr.second));
      }
    }
  }
  for (auto &num : res) {
    num--;
  }
  if (res.size() == cutList.size() * 2) {
    for (int i = 0; i < res.size() / 2; i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  } else {
    print(res);
  }
  return dp[1][n];
}

ll minCut4(vector<ll> cutList, ll n) {
  print(cutList);
  vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));
  for (ll gap = 0; gap < n; gap++) {
    cout << endl;
    for (ll i = 0, j = i + gap; j < n; j++, i++) {
      cout << i << " " << j << endl;
      if (gap == 0) {
        dp[i][j] = 0;
      } else {
        ll min = INT_MAX;
        for (ll m = 0; m < cutList.size(); m++) {
          // cout << i << " " << j << " " << cutList[m] << endl;
          if (cutList[m] < j && cutList[m] >= i) {
            ll cost = (j - i + 1) + dp[i][cutList[m]] + dp[cutList[m] + 1][j];
            cout << cutList[m] << " " << i << " " << j << endl;
            if (cost < min) {
              min = cost;
              cout << (j - i + 1) << " " << dp[i][cutList[m]] << " "
                   << dp[cutList[m] + 1][j] << endl;
              cout << cutList[m] << " " << i << " " << j << endl;
            }
          }
        }
        if (min >= INT_MAX) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = min;
        }
        cout << "dp[" << i << "]"
             << "[" << j << "]"
             << "= " << dp[i][j] << endl;
      }
    }
  }
  print2d(dp);

  cout << endl;
  ll curr = dp[0][n - 1];
  vector<ll> res;
  queue<pair<ll, ll>> q;
  q.push(make_pair(0, n - 1));
  while (!q.empty()) {
    pair<ll, ll> curr = q.front();
    q.pop();
    for (auto cut : cutList) {
      if (cut >= curr.first && cut < curr.second) {
        if (dp[curr.first][cut] + dp[cut + 1][curr.second] +
                (curr.second - curr.first + 1) ==
            dp[curr.first][curr.second]) {
          res.push_back(cut);
          q.push(make_pair(curr.first, cut));
          q.push(make_pair(cut + 1, curr.second));
        }
      }
    }
  }
  if (res.size() == cutList.size() * 2) {
    for (int i = 0; i < res.size() / 2; i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  } else {
    print(res);
  }
  return dp[0][n - 1];
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // string input;
  ll length;
  cin >> length;
  ll n;
  // cin >> input >> n;
  cin >> n;
  vector<ll> cut;
  for (ll i = 0; i < n; i++) {
    ll num;
    cin >> num;
    // cut.push_back(num + 1);
    cut.push_back(num);
  }
  cout << minCut4(cut, length) << endl;
}
