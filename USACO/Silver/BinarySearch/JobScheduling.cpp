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
ll n, d, m; 
vector<pr> arr;
bool check(ll machine){
    vector<ll> robo(machine, 0);
    ll wait = 0;
    ll curr = 0;
    for(ll i = 0; i < m; i++){
        if(curr == machine){
            curr = 0;
        }

        if(robo[curr] + 1 > arr[i].first){
            robo[curr]++;
            wait = max(wait, robo[curr] - arr[i].first);
        } else{
            robo[curr] = arr[i].first;
        }
        curr++;
    }
    return wait > d;
}

bool works(ll robots)
{
	ll endT[robots] = {0};
	ll maxD = 0;

	for (ll i = 0, cur = 0; i < m; i++, cur++) {
		if (cur == robots)
			cur = 0;
		// if our end time for this job is > than our start time for this job
		// there will be delay
		if (endT[cur] + 1 > arr[i].first) {
			endT[cur]++;
			maxD = max(maxD, endT[cur] - arr[i].first);
		}
		else
			endT[cur] = arr[i].first;
	}
	return maxD > d;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> d >> m;
    arr.resize(m);
    for(ll i = 0; i < m; i++){
        ll num; cin >> num;
        arr[i] = {num, i + 1};
    }
    sort(arr.begin(), arr.end());
    //for(ll i = 0; i < n; i++){
        //cout << arr[i].first << " " << arr[i].second << endl;
    //}
    ll left = 1;
    ll right = m;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(check(mid)){
            left = mid + 1; 
        } else{
            right = mid;
        }
    }
    ll need = left;
    ll curr = 0;
    ll count = 0;
    cout << need << endl;
    for(ll i = 0; i < n; i++){
        while(count < need && curr < m){
            cout << arr[curr].second << " ";
            curr++;
            count++;
        }
        count = 0;
        cout << 0 << endl;
    }
}
