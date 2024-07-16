class Solution {
public:
    int romanToInt(string s) {
        int integer=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='I' && s[i+1]!='X' &&s[i+1]!='V'){
            integer+=1;
           }
           else if(s[i]=='I' && s[i+1]=='X'){
            integer+=9;
            i++;
           }
        else if(s[i]=='I' && s[i+1]=='V'){
            integer+=4;
            i++;
           }
           else if(s[i]=='X' && s[i+1]!='L' &&s[i+1]!='C'){
            integer+=10;
           }
           else if(s[i]=='X' && s[i+1]=='L'){
            integer+=40;
            i++;
           }
           else if(s[i]=='X' && s[i+1]=='C'){
            integer+=90;
            i++;
           }
        else if(s[i]=='C' && s[i+1]!='D' &&s[i+1]!='M'){
            integer+=100;
           }
        else if(s[i]=='C' && s[i+1]=='D'){
            integer+=400;
            i++;
           }
         else if(s[i]=='C' && s[i+1]=='M'){
            integer+=900;
            i++;
           }
           else if(s[i]=='V'){
            integer+=5;
           }
         else if(s[i]=='L'){
            integer+=50;
           }
        else if(s[i]=='D'){
            integer+=500;
           }
         else if(s[i]=='M'){
            integer+=1000;
           }
        }
        return integer;
    }
};
