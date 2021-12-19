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

struct Customer{
    ll arrive;
    ll leave;
    ll room;
    ll id;
};

struct Compare{
    bool operator()(Customer &a, Customer &b){
        return a.leave > b.leave;
    }
};

bool cmp(Customer &a, Customer &b){
    if(a.leave == b.leave){
        return a.leave < b.leave;
    }
    return a.arrive < b.arrive ;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    priority_queue<Customer, vector<Customer>, Compare> pq; 
    vector<Customer> input(n);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        input[i] = {a, b, 0, i}; 
    } 

    sort(input.begin(), input.end(), cmp);
    vector<ll> ans(n);

    for(ll i = 0; i < n; i++){
        auto currCust = input[i];
        if(pq.empty()){
            ans[currCust.id] = pq.size() + 1;
            pq.push({currCust.arrive , currCust.leave, (ll)pq.size() + 1, currCust.id});
        } else{
            auto early = pq.top();
            if(currCust.arrive > early.leave){
                pq.pop();
                pq.push({currCust.arrive, currCust.leave , early.room, currCust.id});
                ans[currCust.id] = early.room;
            } else{
                ans[currCust.id] = pq.size()+1;
                pq.push({currCust.arrive, currCust.leave, (ll)pq.size() + 1, currCust.id});
            }
        }
    }
    cout << pq.size() << endl;
    for(ll i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}
