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
    ll t; cin >> t; 
    string check = "0123456789ACDEFHJKLMNPRTVWX";

    map<char, char> special = {
        {'B', '8'},
        {'G', 'C'},
        {'I', '1'},
        {'O', '0'},
        {'Q', '0'},
        {'S', '5'},
        {'U', 'V'},
        {'Y', 'V'},
        {'Z', '2'},
    };

    for(ll i = 0; i < t; i++){
        ll id; cin >> id;
        string num; cin >> num;
        ll temp = 2*(check.find(num[0])) + 4*(check.find(num[1])) + 5*(check.find(num[2])) + 7*(check.find(num[3])) + 8*(check.find(num[4])) + 10*(check.find(num[5])) + 11*(check.find(num[6])) + 13*(check.find(num[7]));
        temp %= 27;
        ll find = check.find(num[8]); 
        if(find == -1){
            find = check.find(special[num[8]]);
        }

        //cout << find << " " << temp << endl;
        if(find == temp){
            ll res = 0;
            for(ll j = 0; j < 8; j++){
                ll curr = check.find(num[j]);
                res += curr * pow(27, 7 - j);
            }
            cout << id << " " << res << endl;
        } else{
            cout << id << " " << "Invalid" << endl;
        }
    }
}
