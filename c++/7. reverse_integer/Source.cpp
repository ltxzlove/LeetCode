#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Solution {
public:
    int reverse_1(int x) {
        int ret = 0;

        char cNum[32] = "\0";
        char cNewNum[32] = "\0";

        sprintf_s(cNum, "%d", x);

        unsigned int nLength = strlen(cNum);
        if (nLength > 0)
        {
            if (cNum[0] == '-')
            {
                cNewNum[0] = '-';

                for (unsigned int i = 1; i < nLength; i++)
                {
                    cNewNum[nLength - i] = cNum[i];
                }
            }
            else
            {
                for (unsigned int i = 0; i < nLength; i++)
                {
                    cNewNum[nLength - i -1] = cNum[i];
                }
            }

            cNewNum[nLength] = '\0';
        }

        const char* NUM_MIN = "-2147483648";
        const char* NUM_MAX = "2147483647";

        int newLength = strlen(cNewNum);
        if (newLength > 0)
        {
            if (cNewNum[0] == '-')
            {
                if (newLength > 11)
                {
                    ret = 0;
                }
                else if (newLength < 11)
                {
                    ret = atoi(cNewNum);
                }
                else
                {
                    if (strcmp(cNewNum, NUM_MIN) > 0)
                    {
                        ret = 0;
                    }
                    else
                    {
                        ret = atoi(cNewNum);
                    }
                }
            }
            else
            {
                if (newLength > 10)
                {
                    ret = 0;
                }
                else if (newLength < 10)
                {
                    ret = atoi(cNewNum);
                }
                else
                {
                    if (strcmp(cNewNum, NUM_MAX) > 0)
                    {
                        ret = 0;
                    }
                    else
                    {
                        ret = atoi(cNewNum);
                    }
                }
            }
        }
        
        return ret;
    }

    int reverse_2(int x)
    {
        int ret = 0;
        bool bOverflow = false;


        while (x != 0)
        {
            int lastNumber = x % 10;
            x = x / 10;

            static int MAX_10 = INT_MAX / 10;
            static int MIN_10 = INT_MIN / 10;

            if (ret > MAX_10)
            {
                bOverflow = true;
                break;
            }
            
            if (ret < MIN_10)
            {
                bOverflow = true;
                break;
            }

            if ((ret == MAX_10) && (lastNumber > 7))
            {
                bOverflow = true;
                break;
            }

            if ((ret == MIN_10) && (lastNumber < -8))
            {
                bOverflow = true;
                break;
            }

            ret = ret * 10 + lastNumber;
        }

        if (bOverflow)
        {
            ret = 0;
        }

        return ret;
    }

    int reverse(int x) {
        long long out = 0;
        bool bfu = x < 0;
        bool startZero = true;
        if (bfu)
            x *= -1;
        while (x) {
            if (x < 10) {
                out *= 10;
                out += x;
                break;
            }
            else {
                int yu = x % 10;
                if (yu != 0) {
                    out = 10 * out + yu;

                    startZero = false;
                }
                else if (!startZero) {
                    out *= 10;
                }
            }
            x /= 10;
        }

        if (bfu)
            out *= -1;

        if (out >= INT_MAX || out <= -INT_MIN)
            return 0;

        return out;
    }
};

int main()
{
    Solution s1;
    s1.reverse(1534236469);
    s1.reverse(321);

    int n = -6 % 10;
    return 0;
}