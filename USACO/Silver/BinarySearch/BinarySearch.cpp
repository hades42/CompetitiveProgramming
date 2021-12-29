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

vector<ll> arr;
ll n;

bool bs(ll num){
    ll left = 0;
    ll right = n -1;
    while(right >= left){
        ll m = (left + right)/2;
        if(arr[m] == num){
            return true;
        } else if(arr[m] < num){
            left = m + 1;
        } else if(arr[m] > num){
            right = m - 1;
        }
    }
    return false;
}


ll closetLeft(ll num){
    ll left = -1;
    ll right = n;
    //cout << left << " " << right << endl;
    while(right > left + 1){
        //cout << left << " " << right << endl;
        ll mid = (left + right)/2;
        if(arr[mid] <= num){
            left = mid;
        } else{
            right = mid;
        }
    }
    return left + 1;
}

ll closeRight(ll num){
    ll left = -1;
    ll right = n;
    //cout << left << " " << right << endl;
    while(right > left + 1){
        //cout << left << " " << right << endl;
        ll mid = (left + right)/2;
        if(arr[mid] < num){
            left = mid;
        } else{
            right = mid;
        }
    }
    return right + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        ll i1 = closeRight(a);
        ll i2 = closetLeft(b);
        cout << i2 - i1 + 1 << " ";
    }
}

