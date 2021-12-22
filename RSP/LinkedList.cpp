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

struct Node{
    ll data;
    Node* next;
};

void travel(Node* node){
    Node* curr = node;
    while(curr != NULL){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    Node* head = NULL;
    Node* first= NULL;
    Node* second= NULL;
    Node* third= NULL;

    head = new Node();
    head -> data = 0;

    first = new Node();
    first -> data = 1;

    second = new Node();
    second -> data = 2;

    third = new Node();
    third -> data = 3;
    
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    travel(head);
}
