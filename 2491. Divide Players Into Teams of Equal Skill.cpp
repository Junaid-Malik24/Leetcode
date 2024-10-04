//leetcode: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-09-29

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        vector<int>result;
        long long int res=0;
        if(!skill.empty() && skill.size()-1!=0){
        result.push_back(skill[0]+skill[skill.size()-1]);
        res+=skill[0]*skill[skill.size()-1];
        }
        for(int i=1;i<skill.size()/2;i++){
           if(skill[i]+skill[skill.size()-1-i]==result.back()){
            res+=skill[i]*skill[skill.size()-1-i];
           }else{
            return -1;
           }
        }
        return res;
    }
};