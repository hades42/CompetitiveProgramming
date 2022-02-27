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
    ll day = 1;
    string cmd;
    map<string, ll> money; 
    
    while(cin >> cmd){
        if(cmd == "CLOSE"){
            cout << "Day " << day << endl;
            for(auto pi : money){
                cout << fixed << setprecision(2) << pi.first << " " << "$" << (double)pi.second / 10 << endl;
            }
            cout << endl;
            money.clear();
            day++;
        } else if(cmd != "OPEN"){
            string name;
            ll time;
            cin >> name >> time;
            if(cmd == "ENTER"){
                money[name] -= time;
            } else if(cmd == "EXIT"){
                money[name] += time;
            }
        }
    }
    return 0;
}
