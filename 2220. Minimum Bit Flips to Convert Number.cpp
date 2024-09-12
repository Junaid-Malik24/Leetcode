//leetcode: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11

//Approach 1 (Simple One)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count1=0;
        int count2=0;
        int init_start=start;
        int init_goal=goal;
        while(start>1){
           start/=2;
           count1++;
        }
        while(goal>1){
           goal/=2;
           count2++;
        }
        int max_count=max(count1,count2);
        int two_multiple;
        int result=0;
        while(max_count>=0){
            two_multiple=pow(2,max_count);
            if(two_multiple<=init_start && two_multiple<=init_goal){
                init_start-=two_multiple;
                init_goal-=two_multiple;
            }else if(two_multiple<=init_start && two_multiple>init_goal){
                init_start-=two_multiple;
                result++;
            }
            else if(two_multiple>init_start && two_multiple<=init_goal){
                init_goal-=two_multiple;
                result++;
            }
            max_count--;
        }
        return result;
    }
};

//Approach 2 (Using Bitwise Manipulation and Operators)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int nx=0;
        for(int i=0;i<32;i++)
        {
            bool x=start&(1<<i);
            bool y=goal&(1<<i);
            //left rotate gives 2^i and '&' operator checks if the bit in start/goal is '1' or '0'
            if(x!=y)
            nx++;
        }
        return nx;
    }
};