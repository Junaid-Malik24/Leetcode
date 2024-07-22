#include <string>
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        string final_roman = "";
        string ffinal_roman = "";
        string fffinal_roman = "";
        int original_num = num;
        int count = 0;
        while (num > 0)
        {
            num /= 10;
            count++;
        }
        if (count == 1)
        {
            if (original_num <= 3)
            {
                for (int i = 0; i < original_num; i++)
                {
                    roman += "I";
                }
            }
            else if (original_num == 4)
            {
                roman += "IV";
            }
            else if (original_num == 5)
            {
                roman += "V";
            }
            else if (original_num >= 6 && original_num <= 8)
            {
                roman += "V";
                for (int i = 0; i < original_num % 5; i++)
                {
                    roman += "I";
                }
            }
            else if (original_num == 9)
            {
                roman += "IX";
            }
            return roman;
        }
        else if (count == 2)
        {
            int units = original_num % 10;
            int tens = original_num / 10;
            if (units <= 3)
            {
                for (int i = 0; i < units; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 4)
            {
                roman += "IV";
            }
            else if (units == 5)
            {
                roman += "V";
            }
            else if (units >= 6 && units <= 8)
            {
                roman += "V";
                for (int i = 0; i < units % 5; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 9)
            {
                roman += "IX";
            }
            if (tens <= 3)
            {
                for (int i = 0; i < tens; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 4)
            {
                final_roman += "XL";
            }
            else if (tens == 5)
            {
                final_roman += "L";
            }
            else if (tens >= 6 && tens <= 8)
            {
                final_roman += "L";
                for (int i = 0; i < tens % 5; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 9)
            {
                final_roman += "XC";
            }
            return final_roman + roman;
        }
        else if (count == 3)
        {
            int units = original_num % 10;
            int tens = (original_num / 10) % 10;
            int hundreds = original_num / 100;

            if (units <= 3)
            {
                for (int i = 0; i < units; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 4)
            {
                roman += "IV";
            }
            else if (units == 5)
            {
                roman += "V";
            }
            else if (units >= 6 && units <= 8)
            {
                roman += "V";
                for (int i = 0; i < units % 5; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 9)
            {
                roman += "IX";
            }
            if (tens <= 3)
            {
                for (int i = 0; i < tens; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 4)
            {
                final_roman += "XL";
            }
            else if (tens == 5)
            {
                final_roman += "L";
            }
            else if (tens >= 6 && tens <= 8)
            {
                final_roman += "L";
                for (int i = 0; i < tens % 5; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 9)
            {
                final_roman += "XC";
            }

            if (hundreds <= 3)
            {
                for (int i = 0; i < hundreds; i++)
                {
                    ffinal_roman += "C";
                }
            }
            else if (hundreds == 4)
            {
                ffinal_roman += "CD";
            }
            else if (hundreds == 5)
            {
                ffinal_roman += "D";
            }
            else if (hundreds >= 6 && hundreds <= 8)
            {
                ffinal_roman += "D";
                for (int i = 0; i < hundreds % 5; i++)
                {
                    ffinal_roman += "C";
                }
            }
            else if (hundreds == 9)
            {
                ffinal_roman += "CM";
            }

            return ffinal_roman + final_roman + roman;
        }
        else if (count == 4)
        {
            int units = original_num % 10;
            int tens = (original_num / 10) % 10;
            int hundreds = (original_num / 100) % 10;
            int thousands = original_num / 1000;

            if (units <= 3)
            {
                for (int i = 0; i < units; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 4)
            {
                roman += "IV";
            }
            else if (units == 5)
            {
                roman += "V";
            }
            else if (units >= 6 && units <= 8)
            {
                roman += "V";
                for (int i = 0; i < units % 5; i++)
                {
                    roman += "I";
                }
            }
            else if (units == 9)
            {
                roman += "IX";
            }

            if (tens <= 3)
            {
                for (int i = 0; i < tens; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 4)
            {
                final_roman += "XL";
            }
            else if (tens == 5)
            {
                final_roman += "L";
            }
            else if (tens >= 6 && tens <= 8)
            {
                final_roman += "L";
                for (int i = 0; i < tens % 5; i++)
                {
                    final_roman += "X";
                }
            }
            else if (tens == 9)
            {
                final_roman += "XC";
            }

            if (hundreds <= 3)
            {
                for (int i = 0; i < hundreds; i++)
                {
                    ffinal_roman += "C";
                }
            }
            else if (hundreds == 4)
            {
                ffinal_roman += "CD";
            }
            else if (hundreds == 5)
            {
                ffinal_roman += "D";
            }
            else if (hundreds >= 6 && hundreds <= 8)
            {
                ffinal_roman += "D";
                for (int i = 0; i < hundreds % 5; i++)
                {
                    ffinal_roman += "C";
                }
            }
            else if (hundreds == 9)
            {
                ffinal_roman += "CM";
            }
            if (thousands <= 3)
            {
                for (int i = 0; i < thousands; i++)
                {
                    fffinal_roman += "M";
                }
            }
            return fffinal_roman + ffinal_roman + final_roman + roman;
        }
        return "";
    }
};
