#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
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

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

vector<ll> indicies;
vector<pair<pair<ll, ll>, ll>> updates(1e5 + 5);
vector<pair<ll, ll>> query(1e5 + 5);
vector<ll> diffArray(2e5 + 5);
vector<ll> width(2e5 + 5);
vector<ll> interval(2e5 + 5);
vector<ll> prefixSum(2e5 + 5);

ll getCompress(ll num) {
  return lower_bound(indicies.begin(), indicies.end(), num) - indicies.begin();
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll N, Q;
  cin >> N >> Q;
  for (ll i = 0; i < N; i++) {
    ll l, r, v;
    cin >> l >> r >> v;
    indicies.push_back(l);
    indicies.push_back(r);
    updates[i] = {{l, r}, v};
  }

  for (ll i = 0; i < Q; i++) {
    ll l, r;
    cin >> l >> r;
    indicies.push_back(l);
    indicies.push_back(r);
    query[i] = {l, r};
  }

  // Create a sorted indicies for compression
  sort(indicies.begin(), indicies.end());
  indicies.erase(unique(indicies.begin(), indicies.end()), indicies.end());

  // Get the distance between each compression index
  for (ll i = 0; i < N; i++) {
    auto curr = updates[i];
    diffArray[getCompress(curr.first.first) + 1] += curr.second;
    diffArray[getCompress(curr.first.second) + 1] -= curr.second;
  }

  //for (ll i = 0; i <= 15; i++) {
    //cout << diffArray[i] << " ";
  //}
    //cout << endl;
    for(ll i = 0; i < indicies.size(); i++){
        width[i+1] = indicies[i+1] - indicies[i];
    }
    for(ll i = 1; i < indicies.size(); i++){
        interval[i] = interval[i-1] + diffArray[i];
    }

    //for(ll i = 0; i <= 15; i++){
        //cout << interval[i] << " ";
    //}
    //cout << endl;

    for(ll i = 1; i < indicies.size(); i++){
        prefixSum[i] = prefixSum[i-1] + width[i] * interval[i];
    }
    
    for(ll i = 0; i < Q; i++){
        cout << prefixSum[getCompress(query[i].second)] - prefixSum[getCompress(query[i].first)] << endl;
    }

}

