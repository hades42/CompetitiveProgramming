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

bool cmp(vector<ll> &a, vector<ll> &b){
    if(a[1] == b[1]){
        return a[2] < b[2];
    }
    return a[1] < b[1];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("convention2");
    ll n; cin >> n;
    vector<vector<ll>> arr(n);
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr[i] = vector<ll>{i, a, b};
    }
    sort(arr.begin(), arr.end(), cmp);
    //print2d(arr);

    set<vector<ll>> waiting;
    ll curr = 0;
    ll ans = 0;
    ll time = 0;

    while(curr < n || waiting.size() > 0){
        //cout << time << " " << arr[curr][1] << " " <<(arr[curr][1] < time) << endl;
         if(curr < n && arr[curr][1] <= time){
            waiting.insert(arr[curr]);
            curr++;
        } else if(waiting.size() == 0){
            time = arr[curr][1] + arr[curr][2];
            curr++;
        } else{
            vector<ll> topId = *waiting.begin();
            //cout << topId << endl;
            ans = max(ans, time - topId[1]);
            //cout << time << " " << topId[2] << endl;
            time = time + topId[2];
            
            waiting.erase(waiting.begin());
        }
        //cout << time << endl;
    }
    cout << ans << endl;
}
