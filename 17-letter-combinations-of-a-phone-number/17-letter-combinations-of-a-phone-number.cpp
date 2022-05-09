class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        string arr[4]={""};
        for(int i=0;i<digits.size();i++){
            arr[i]=mp[digits[i]];
        }
        vector<string>ans;
        string res="";
        bool ok=0,ok2=0,ok3=0,ok4=0;
        for(int i=0;i<arr[0].size();i++){
            res="";
            res+=arr[0][i];
            ok=1,ok2=0,ok3=0,ok4=0;
            for(int j=0;j<arr[1].size();j++){
                string res2=res;
                res2+=arr[1][j];
                ok2=1;
                for(int k=0;k<arr[2].size();k++){
                    string res3=res2;
                    res3+=arr[2][k];
                    ok3=1;
                    for(int l=0;l<arr[3].size();l++){
                        string res4=res3;
                        res4+=arr[3][l]; 
                        ok4=1;
                        ans.push_back(res4);
                    }
                    if(!ok4){
                        ans.push_back(res3);
                    }
                }
                if(!ok3){
                    ans.push_back(res2);
                }
            }
            if(!ok2){
                ans.push_back(res);
            }
        }  
        return ans;
    }
};