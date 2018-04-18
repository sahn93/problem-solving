#include <iostream>
#include <vector>

using namespace std;
int main() {
    int T;
    int len;
    bool valid;

    cin >> T;
    for (int t=0; t<T; t++) {
        cout << "Case #" << t+1 << ": ";
        cin >> len;
        vector<int> V(len);
        valid = true;

        int tmp;
        for (int i=0; i<len; i++) {
            cin >> tmp; 
            V[i] = tmp;
        }

        vector<int> even;
        vector<int> odd;

        for (int i=0; i<len; i+=2) {
            even.push_back(V[i]);
        }

        for (int i=1; i<len; i+=2) {
            odd.push_back(V[i]);
        }
        
        // O(nlogn) 
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        // O(n)
        int prev = even[0];
        int curr;
        for (int i=1; i<len; i++) {
            if (i%2!=0) {
                curr = odd[i/2];
            } else {
                curr = even[i/2];
            }

            if (prev > curr) {
                cout << i - 1 << '\n';
                valid = false;
                break;
            }
            prev = curr;
        }

        if (valid) {
            cout << "OK\n";
        }
    }
}
