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
    ll limit, type_num; 
    cin >> limit >> type_num;
    map<ll, vector<pr>> mp;
    for(ll i = 0; i < type_num; i++){
	    ll value;
		ll weight;
		ll amt;
		cin >> value >> weight >> amt;

        if(weight <= limit && amt > 0){
            mp[weight].push_back({value, amt});
        }
    }

    //for(auto &[w, items] : mp){
        //cout << w << endl;
        //for(auto thing : items){
            //cout << thing.first << " " << thing.second << endl;
        //}
    //}

    vector<vector<ll>> dp(mp.size() + 1, vector<ll>(limit + 1, -1));
    ll at = 1;
    dp[0][0] = 0;
    for(auto &[w, items] : mp){
        sort(items.begin(), items.end(), greater<pair<ll,ll>>());

        for(ll i = 0; i <= limit; i++){
            dp[at][i] = dp[at-1][i];
            // To predict whether you can keep buying the current product
            ll copies = 0;
            // What is the index of product you are buying right now
            ll type_at = 0;
            // What is the amount of product you already bought from the type_at product
            ll curr_used = 0;
            // What is the current profit
            ll profit = 0;
            while((copies + 1) * w <= i && type_at < items.size()){
                copies++;
                profit += items[type_at].first;
                if(dp[at - 1][i - copies * w] != INF){
                    dp[at][i] = max(dp[at][i], dp[at - 1][i - copies * w] + profit);
                }

                curr_used++;
                if(curr_used == items[type_at].second){
                    curr_used = 0;
                    type_at++;
                }
            }
        }
        at++;
    }
    //print2d(dp);
    cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}
