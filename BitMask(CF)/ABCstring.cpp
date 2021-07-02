#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1e18;
using namespace std;

template<typename T>
void print(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}

template<typename T>
void print2d(const T& t) {
    std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

const ll maxSize = 100100;
bool primes[maxSize];
void precompute(){
	fill(primes, primes + maxSize, true);
	primes[0] = false;
	primes[1] = false;
	for(ll i = 2; i*i < maxSize; i++){
		if(primes[i]){
			for(ll j = i + i; j < maxSize; j+= i){
				primes[j] = false;
			}
		}
	}
}

bool checking(string str){
	stack<char> st;
	st.push(str[0]);
	for(ll i = 1; i < str.size(); i++){
		if(!st.empty() && st.top() == '(' && str[i] == ')'){
			st.pop();
		} else{
			st.push(str[i]);
		}
	}
	if(st.empty()){
		return true;
	} else return false;
}
int main() {
	ll t; cin >> t;
	for(ll i = 0; i < t; i++){
		string in; cin >> in;
		bool check = false;
		for(ll mask = 0; mask < (1 << 3); mask++){
			string cop = in;
			vector<ll> cases(3);
			for(ll i = 0; i < 3; i++){
				if(mask & (1 << i)){
					cases[i] = 1;
				}
			}
			for(ll i = 0; i < in.size(); i++){
				if(cop[i] == 'A'){
					if(cases[0] == 1){
						cop[i] = '(';
					} else cop[i] = ')';
				} 

				if(cop[i] == 'B'){
					if(cases[1] == 1){
						cop[i] = '(';
					} else cop[i] = ')';
				} 

				if(cop[i] == 'C'){
					if(cases[2] == 1){
						cop[i] = '(';
					} else cop[i] = ')';
				} 
			}
			check |= checking(cop);
		}
		cout << (check ? "YES" : "NO") << endl;
	}
}








