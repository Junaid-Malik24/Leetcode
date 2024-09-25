//leetcode: https://leetcode.com/problems/extra-characters-in-a-string/?envType=daily-question&envId=2024-09-23

class Solution {
public:
    int n;
    int solve(int indx,string s,vector<string>&dictionary,vector<int>&dp){
        if(indx>=s.size()){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        int res=n;
        for(string str: dictionary){
            
            int len=str.length();
            if(indx+len<=n and s.substr(indx,len)==str ){
                
                dp[indx]=res=min(res,solve(indx+len,s,dictionary,dp));
                
            }
        }
        int notchoose=1+solve(indx+1,s,dictionary,dp);
        return dp[indx]=min(res,notchoose);
    } 
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n=s.size();
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,dictionary,dp);
    }
};
