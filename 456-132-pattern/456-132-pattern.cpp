class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=min(pre[i-1],nums[i]);
        }
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=pre[i])
                st.pop();
            if(!st.empty() && nums[i]>st.top())
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};