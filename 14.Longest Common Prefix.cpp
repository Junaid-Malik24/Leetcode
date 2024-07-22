class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<int> vec(strs.size());
        for(int i=0;i<strs.size();i++){
          vec[i]=strs[i].length();
        }
        int min_length=vec[0];
        for(int i=1;i<vec.size();i++){
           if(vec[i]<=min_length){
            min_length=vec[i];
           }else{
            continue;
           }
        }
        string prefix="";
        char smth;
        for(int i=0;i<min_length;i++){
            for(int j=0;j<strs.size();j++){
                if(j==0){
                  smth=strs[j][i];
                }
                if(smth!=strs[j][i] && j!=0){
                    return prefix;
                }
            }
            prefix+=smth;
        }
        return prefix;
    }
};
//Find minimum length of a string in the vector....that will be your limit of how much characters of a string you have to traverse through...just by using that...you will be able to compare characters of different 
//strings in a vector to a certain limit!Goodluck!Happy Coding!
