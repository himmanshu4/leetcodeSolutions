class Solution {
public:
    string smallestPalindrome(string s) {
        bool isOdd = s.length()%2;
        char oddChar = s[s.length()/2];
        string ansL (s.begin(),s.begin()+s.length()/2);
        sort(ansL.begin(),ansL.end());
        string ansR(ansL.rbegin(),ansL.rend());
        if(isOdd){
            ansL+=oddChar;
        }
        return ansL+ansR;
    }
};