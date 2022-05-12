class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        do{
            st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        
          vector<vector<int>>v;
        for(auto it:st){
            v.push_back(it);
        }
        return v;
    }
};