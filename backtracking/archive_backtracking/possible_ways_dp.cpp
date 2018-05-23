#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100010] = {0};
int main() {
    cin >> n;
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n ; i++){
        for(int j=1; j<=6; j++)
            if(i - j >= 0)
                dp[i] += dp[i-j];
    }
    cout << dp[n] << endl;
    return 0;
}
