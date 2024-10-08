#include <string>
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman_numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman = "";
        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                num -= values[i];
                roman += roman_numerals[i];
            }
        }
        return roman;
    }
};
//Traverse through the whole values array containing values corresponding to the symbols in the roman_numerals array....for instance....roman_numerals[0]="M"=values[0]=1000....Only Speaking Realistically
//We Traverse the array from left to right 13 times(Disclaimer:Total 13 Array Elements) until we find a value which is less than our integer which then we subtract from our integer 
//We also concatenate the symbol with our variable roman which will will consequently hold the final answer until we can't find any values less than our integer...Good luck!
