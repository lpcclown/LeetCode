class Solution {
    int dp[10][1005];
public:
    bool isOK(vector<int>& nums)
    {
        int flag = 1;
        for (int i=0; i<nums.size(); i++)
        {
            if (dp[i][nums[i]]==false)
            {
                flag = 0;
                break;
            }
        }
        return flag;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        for (int i=0; i<nums.size(); i++)
            dp[i][0] = true;
        
        if (isOK(nums)) return 0;
        
        for (int k=0; k<queries.size(); k++)
        {
            int a = queries[k][0], b = queries[k][1], d = queries[k][2];
            for (int i=a; i<=b; i++)
            {
                for (int v=1000; v>=0; v--)
                    if (v>=d) dp[i][v] = (dp[i][v] || dp[i][v-d]);                
            }            
            
            if (isOK(nums)) return k+1;
        }
        return -1;
    }
};
