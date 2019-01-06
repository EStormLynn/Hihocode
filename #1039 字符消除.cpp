#include <iostream>
#include <algorithm>

using namespace std;

char str[200];
int solve(int l){
    int len = 1;
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i < l; i++){
        if (str[i] == str[i - 1]){
            cnt++;
        }
        else {
            if (cnt != 1){
                len--;
                ans += cnt;
            }
            str[len++] = str[i];
            cnt = 1;
        }
    }
    if (cnt != 1){
        len--;
        ans += cnt;
    }
    if (ans == 0)return ans;
    return ans + solve(len);
}
int main(){
    string s;
    int T;
    cin >> T;
    while (T--){
        cin >> s;
        int ans = 0;
        for (int i = 0; i <= s.length(); i++){
            for (char j = 'A'; j <= 'C'; j++){
                int l = 0;
                for (int k = 0; k < s.size(); k++){
                    if (i == k){
                        str[l++] = j;
                    }
                    str[l++] = s[k];
                }
                if (i == s.size())str[l++] = j;
                str[l] = '\0';
                ans = max(ans, solve(l));
            }
        }
        cout << ans << endl;
    }
}