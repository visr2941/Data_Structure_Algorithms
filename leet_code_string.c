/* Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3". 
*/

void ReverseString(char * str, int count)
{
    int start = 0, end = count-1;
    char temp;
    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char * my_positive_itoa10(char * str, int data)
{
	char val, count=0, i=0, j=0;
	
    /* run atleast once (corner case when data = 0) */
	do
	{
		val = data%10;
		data = data/10;	
		*(str+i++) = val + '0';	
		count++;
        
	} while(data !=0);

	*(str+i) = '\0';
    
    ReverseString(str, count);

	return str;
} 

void AppendCount(char * chars, int cnt, int * i_wr)
{
    char numStr[15];
    my_positive_itoa10(numStr, cnt);
   
    int len = 0;
    while(numStr[len++]);
    len -= 1;
    
    for(int i = 0; i< len; i++)
        chars[(*i_wr)++] = numStr[i];
}

/*  Solution
    Notes:
    1.  Take two indexes i_wr: index to write the count 
        and i_rd: index of current character reading
    2.  Keep track of current character and last character
    
    Algo:
    1.  Read each character one by one till the length of string
    2.  Compare the current character with last character, if they
        are same, increase the count. If they are different, there
        could be four possibility:
        a.  the i_rd and i_wr points to the same char - this will
            happen when there has not been any repeated char till
            the point or the last repeated char was repeated twice.
        b.  count is not equal to 1 and the the read and write indexes
            are not same.
        c.  cnt is 1 but read and write indexes are not same. This
            can happen when last repeated character wew repeated more
            than twice, so read moved more than the write has to move.
    3.  For 2.a, just increase the i_wr index.
        For 2.b, append the count in the string and then write the
        current character at i_wr index. The count needs to be converted
        to string since a count greater than 9 can be represented by 
        a single ascii value.
        For 2.c, write the current character at the i_wr index and move.
        
*/

int compress(char* chars, int charsSize) 
{
    char ch, last_ch = '\0';
    int cnt = 1, i_wr = 0, i_rd = 0;

    while(i_rd < charsSize)
    {
        ch = chars[i_rd];
        
        if(ch == last_ch)
        {
            cnt++;
        }
        else if((cnt==1) && (i_rd == i_wr))
        {
            i_wr++;
        }
        else if(cnt != 1)
        {
            AppendCount(chars, cnt, &i_wr);
            
            chars[i_wr++] = chars[i_rd];
            
            cnt = 1;
        }
        else
            chars[i_wr++] = chars[i_rd];
        
        i_rd++;
        last_ch = ch;
    }
    
    if(cnt != 1) AppendCount(chars, cnt, &i_wr);
    
    chars[i_wr] = chars[i_rd];
    
    return i_wr;
}

int main ()
{
    char str[21] = {'a', 'a', 'b', 'b', 'b', 'c', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'g', 'g', '\0'};
    
    printf("old string is %s\n", str);
    
    int new_len = compress(str, 20);
    
    printf("new string is %s, new length is %d\n", str, new_len);

    return 0;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's 
and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.

*/
#include <stdio.h>

#define false 0 
#define true  1 


int countBinarySubstrings(char* s) {
    int cnt[2] = {0, 0};
    int  maincnt = 0;
    char ch, lastch;
    int flip = 0;
    int i = 0;

    while((ch = *(s+i)) != '\0')
    {
        
        if(ch == lastch)
        {
            if(flip == 0) cnt[0]++;
            else cnt[1]++;
        }
        else
        {
            flip = !flip;
            
            if(flip == 0)
            {
                maincnt += (cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
                cnt[0] = cnt[1];
                cnt[1] = 1;
                flip = 1;
            }
            else
                cnt[1]++;
            
        }
        
        i++;
        lastch = ch;
    }
    
    maincnt += (cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
    
    return maincnt;
}

int main()
{
    char * str = "10101";
    printf("length %d\n", countBinarySubstrings(str));

    return 0;
}




=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <stdio.h>

struct s {
    int cnt;
    int index;
};

int firstUniqChar(char* s) {
    struct s cntInfo[26];
    int i = 0, retIndex, strSize;
    char ch;
    
    for(int i = 0; i < 26; i++)
    {
        cntInfo[i].cnt = 0;
    }
    
    while((ch = *(s+i)) != '\0')
    {
        cntInfo[ch-97].cnt++;
        cntInfo[ch-97].index = i;
        i++;
    }
    
    strSize = i;  // it's actually strlen(s) + 1
    retIndex = strSize;
    
    for(int i = 0; i < 26; i++)
    {
        if(cntInfo[i].cnt == 1)
        {
            retIndex = retIndex < cntInfo[i].index ? retIndex : cntInfo[i].index;
        }
    }
    
    if(retIndex == strSize) return -1;
    
    return retIndex;
    
}

int main()
{
    char * str = "loveleetcode";
    printf("index %d\n", firstUniqChar(str));

    return 0;
}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each 
digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 
and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
*/

#include <stdio.h>

int rotatedDigits(int N) {
    int invalidFlag = 0, diff = 0;
    int div, goodCnt = 0, num;
    
    for(int i = 1; i <= N; i++)
    {
        num = i; 
        while(num != 0)
        {
            div = num%10;

            if(div == 3 || div == 7 || div == 4)
            {
                invalidFlag = 1;
                break;
            }
            else if(div == 2 || div == 5 || div == 6 || div == 9)
            {
                diff = 1;
            }
            
            num = num/10;
        }
        
        if(invalidFlag != 1 && diff == 1)
        {
            goodCnt++;
        }
        
        invalidFlag = 0;
        diff = 0;
    }
    
    return goodCnt;
}

int main()
{
    int x = 10;;
    printf("Count %d\n", rotatedDigits(x));

    return 0;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool RemoveAndCheckForPlaindrome(char *s, int left, int right, int size)
{
    for(int i = left; i < size; i++)
    {
        if(s[i] != s[right--])
            return false;
    }
    
    return true;
}

bool validPalindrome(char* s) {
    int len = 0;
    
    while(*(s+len++));
    len -= 1;

    int loop = len/2;
    
    for(int i = 0; i < loop; i++)
    {
        if(s[i] != s[len-i-1])
        {
            if(s[i] != s[len-i-2] && s[i+1] != s[len-i-1])
                return false;
            
            return (RemoveAndCheckForPlaindrome(s, i, len-i-2, loop) || RemoveAndCheckForPlaindrome(s, i+1, len-i-1, loop));
        }
    }        
    
    return true;
}

int main()
{
    char * s = "abda";
    printf("True/False %d\n", validPalindrome(s));

    return 0;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given an input string, reverse the string word by word.

Example:  

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ReverseTheString (char * s, int len)
{
    char temp;
    for(int i = 0; i < (len/2); i++)
    {
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

int ClearTrailSpaces(char * s)
{
    int i = 0;
    while(s[i] == ' ') i++;
    
    int j = 0;
    while(*(s+i) != '\0') s[j++] = s[i++];
    s[j] = '\0';
    
    while(s[--j] == ' ');
    s[++j] = '\0';
    
    return j;
}

int DoubleMoreSpacesToSingle(char *s, int len)
{
    int startCnt = 0, j;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ')
        {
            startCnt++;
        }
        else
        {
            if(startCnt > 1)
            {
                j = i;

                while(*(s+j) != '\0') s[j-startCnt+1] = s[j++];
                s[j-startCnt+1] = '\0';
                
                len = len-startCnt+1;
                i = i - startCnt+1;
            }
            startCnt = 0;
        }
    }
    
    return len;
}

void reverseWords(char *s) {
    int len = 0;
    char temp;
    
    while(*(s+len++));
    len-=1;
    
    len = ClearTrailSpaces(s);
        
    len = DoubleMoreSpacesToSingle(s, len);
        
    ReverseTheString(s, len);

    int i = 0, j = 0;
    bool startWord = false, insideWord = false;
    

    while(*(s+i) != '\0')
    {        
        if(insideWord == false)
        {
            if(*(s+i) != ' ') 
            {
                startWord = true;
                insideWord = true;
            }
        }
        
        if(insideWord && startWord) j = i;
        else if (*(s+i) == ' ')
        {
            ReverseTheString((s+j), i-j);
            insideWord = false;
        }
        
        startWord = false;
        
        i++;
    }
    
    ReverseTheString((s+j), i-j);
}

int main()
{
    char s[20] = "   a   b ";
    printf("old string %s %d\n", s, strlen(s));
    reverseWords(s);
    printf("new string: %s\n", s);

    return 0;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should 
truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

int ClearTrailSpaces(char * s)
{
    int i = 0, j = 0;
    while(s[i] == ' ') i++;

    while(*(s+i) != '\0') s[j++] = s[i++];
    s[j] = '\0';
    
    while(s[--j] == ' ');
    s[++j] = '\0';
    
    return j;
}

int SpacesToNoSpace(char *s, int len)
{
    int startCnt = 0, j;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ') 
        {
            startCnt++;
        }
        else if (startCnt > 0)
        {
            j = i;

            while(*(s+j) != '\0') s[j-startCnt] = s[j++];
            s[j-startCnt] = '\0';

            len = len-startCnt;
            i = i - startCnt;
            startCnt = 0;
        }
    }
    
    return len;
}

int calculate(char* s) {
    int len = ClearTrailSpaces(s);
    len = SpacesToNoSpace(s, len);
    
    
    return len;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result 
equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
*/

bool buddyStrings(char* A, char* B) {
    bool flag = false, finalflag = false, samechar = false;
    
    int i = 0, ind;
    char temp;
    
    /* hash is defined to tackle situation where 
    ** A = "abab" and B = "abab" - ans is true */
    char hash[26] = {0};
    
    while(*(A+i) != '\0' && *(B+i) != '\0')
    {
        if(flag && *(A+i) != *(B+i))
        {
            if(A[ind] == B[i] && A[i] == B[ind]) finalflag = true;
            else return false;
            flag = false;
        }
        else if(*(A+i) != *(B+i))
        {
            if(finalflag) return false;
            ind = i;
            flag = true;
        }       

        if(hash[A[i]-97] != 0) samechar = true;
        hash[A[i]-97] = 1;
        
        i++;
    }
    
    
    if(*(A+i) == '\0' && *(B+i) == '\0' && !flag && !samechar) 
    {
        if(finalflag)   
            return true;
        else
            return false;
    }
    else if(*(A+i) != '\0' || *(B+i) != '\0') return false;
    else if(samechar && !flag) return true;
    else if(flag) return false;
    
    return true;
}



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
void addBits(char c1, char c2, char * str, bool * carr)
{
    if(c1 == '1' && c2 == '1')
    {
        if(*carr) *str = '1';
        else *str = '0';

        *carr = true;
    }
    else if(c1 == '1' || c2 == '1')
    {
        if(*carr) *str = '0'; // carry still true
        else *str = '1';            
    }
    else
    {
        if(*carr) {
            *str = '1'; 
            *carr = false; // clear the carry here
        }
        else *str = '0';            
    }
}

char* addBinary(char* a, char* b) {
    int cnt1 = 0, cnt2 = 0, ind1, ind2;
    bool carr = false;
    
    while(a[cnt1++] != '\0');
    while(b[cnt2++] != '\0');
    
    cnt1 -= 1;
    cnt2 -= 1;
        
    int newCnt = (cnt1 > cnt2 ? (cnt1+2) : (cnt2+2));
    char * str = (char *) malloc(newCnt*sizeof(char));
    str[--newCnt] = '\0';
    
    ind1 = --cnt1;
    ind2 = --cnt2;
    while(ind1 >= 0 && ind2 >= 0)
    {
        addBits(a[ind1], b[ind2], &(str[--newCnt]), &carr);
        --ind1;
        --ind2;
    }
    
    while(ind1 >= 0) 
    {
        addBits(a[ind1], '0', &(str[--newCnt]), &carr);
        ind1--;
    }
    
    while(ind2 >= 0)
    {
        addBits('0', b[ind2], &(str[--newCnt]), &carr);
        ind2--;        
    }
    
    if(carr) str[--newCnt] = '1';
    else return (str+1);
    
    return str;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the
string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/


int ClearTrailSpaces(char * s)
{
    int i = 0, j = 0;
    while(s[i] == ' ') i++;

    while(*(s+i) != '\0') s[j++] = s[i++];
    s[j] = '\0';
    
    while(s[--j] == ' ');
    s[++j] = '\0';
    
    return j;
}

int lengthOfLastWord(char* s) {    
    int cnt = 0, retCnt = 0;
    bool flag = false;
    
    cnt = ClearTrailSpaces(s);
    if(s[0] == '\0') return 0;

    int index = cnt-1;
    
    while(s[index] != ' ')
    {
        index--;
        retCnt++;
        if(index < 0) {
            flag = true;
            break;
        }
    }
        
    return retCnt;
}



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

#define isAlphaNum(x)   ((x>='0' && x<='9') || (x<=122 && x>=97))

bool isPalindrome(char* s) {
    if(s[0] == '\0') return true;
    
    int cnt = 0;
    
    while(*(s+cnt) != '\0')
    {
        if(s[cnt]>=65 && s[cnt]<=90)
           s[cnt] += 32;
        
        cnt++;
    }
        
    int ind_last = cnt-1;
    int ind_start = 0;
    
    while(ind_start < ind_last)
    {
        while(ind_start < ind_last && !isAlphaNum(s[ind_start]))
        {
            ind_start++;
        }
        
        while(ind_last > ind_start && !isAlphaNum(s[ind_last]))
        {
            ind_last--;    
        }

        if(s[ind_start] != s[ind_last]) return false;
        ind_start++;
        ind_last--;
    }
    
    return true;
}

