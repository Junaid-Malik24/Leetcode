//leetcode: https://leetcode.com/problems/clumsy-factorial/

//Approach 1 (The Stack Approach taking precedence into account)
class Solution {
public:
    int clumsy(int n) {
        stack<int> S;
    S.push(n);
    n--;
    int i=0;
    while (n>0)
    {
        if (i==0)
        {
            S.top()*=n;
        }else if (i==1)
        {
            S.top()/=n;
        }else if(i==2){
            S.push(n);
        }else
        {
            S.push(-n);
        }
        i++;
        i%=4;
        n--;    
    }
    int number=0;
    while (!S.empty())
    {
        number+=S.top();
        S.pop();
    }
    return number;
    }
};

//Approach 2 (The Symmetric Method to solve a problem)
class Solution {
public:
    int clumsy(int n) {
        int temp=n;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 6;
        if(n==4)
            return 7;
        if(n%4==2)
            return n+2;
        if(n%4==1)
            return n+2;
        if(n%4==3)
            return n-1;
        return n+1;
        
    }
};