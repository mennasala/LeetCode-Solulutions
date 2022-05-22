class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        string temp="",rev="";
        for(int i=0;i<s.size();i++){
            temp="",rev="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                rev=s[j]+rev;
                if(temp==rev)
                    cnt++;
            }
        }
        return cnt;
    }
};