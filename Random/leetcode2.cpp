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

int minSwaps(vector<int>& nums) {
    int N = nums.size();
    int ones = 0;
    int mis = 0;
    for(int i = 0; i < N; i++){
        nums.push_back(nums[i]);
    }
    for(int i = 0; i < N; i++){
        ones += nums[i] == 1;
    }

    for(int i = 0; i < N; i++){
        mis += nums[i] == 0;
    }
    int tempMis = 0;
    for(int i = 0; i < ones; i++){
        tempMis += nums[i] == 0;
    }
    for(int i = ones; i < 2*N; i++){
        if(nums[i] == 0)tempMis++;
        if(nums[i - ones] == 0) tempMis--;
        mis = min(tempMis, mis);
    }
    return mis;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<int> temp{1};
    cout << minSwaps(temp);
}
