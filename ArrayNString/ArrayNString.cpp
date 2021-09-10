#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;
// Find the first nonrepeadted string
char FindFirstNonrepeatedChar(string strInputString)
{
	char cRet;
	unordered_map<char, int> mapChar; // first: character in string, second : number appear in string
	for (int i = 0; i < strInputString.length(); ++i)
	{
		// New char insert into map 
		if (mapChar.find(strInputString[i]) == mapChar.end())
		{
			mapChar.insert(make_pair(strInputString[i], 1));
		}
		else 
		{
			++(mapChar.find(strInputString[i])->second);
		}
	}

	// Find the first character nonrepeated
	for (auto& it : mapChar)
	{
		if (it.second == 1)
		{
			cRet = it.first;
			break;
		}
	}
	return cRet;
}

// Remove Specifier Characters
string RemoveChars(string str, string remove)
{
	// O(n2) Using 2 for loop to check
	// Improvement
	bool flags[128];
	for (int i = 0; i < 128; i++)
	{
		flags[i] = false;
	}

	// Set flag for remove character
	for (int i = 0; i < remove.length(); ++i)
	{
		flags[remove[i]] = true;
	}

	int dst = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (flags[str[i]] == false)
		{
			str[dst] = str[i];
			dst++;
		}
	}
	return str;
}

// Reverse Words
// There are 2 steps
// 1st: Reverse all string: van hung -> gnuh nav
// 2nd: Reverse each word:  hung van
string ReverseString(string strInputString)
{
	string strRet;
	int length = strInputString.length();
	// 1st step
	for (int i = 0; i < length/2; ++i)
	{
		char temp = strInputString[i];
		strInputString[i] = strInputString[length - i - 1];
		strInputString[length - i - 1] = temp;
	}
	
	// 2nd second step
	int iStart = 0;
	int iEnd = 0;
	for (int i = 0; i <= length; i++)
	{
		if (strInputString[i] == ' ' || strInputString[i] == '\0')
		{
			iEnd = i - 1;
			for (int j = iStart; j <= (iEnd + iStart) / 2; j++)
			{
				char temp = strInputString[j];
				strInputString[j] = strInputString[iEnd + iStart - j];
				strInputString[iEnd + iStart - j] = temp;
			}
			iStart = iEnd + 2;
		}
	}

	strRet = strInputString;
	return strRet;
}

// Remove duplicated from sorted array
 int removeDuplicates(vector<int>& nums) 
    {
        int nSize = nums.size();
        if (nSize <= 1)
        {
            iRet = nSize;
        }
        else
        {
            auto itPrev = nums.begin();
            auto itNext = itPrev + 1;
            
            while (itNext != nums.end())
            {
                if (*itPrev == *itNext)
                {
                    itNext = nums.erase(itNext);
                    nSize--;
                }
                else
                {
                    itPrev++;
                    itNext++;
                }
            }
        }
        return nSize;
    }


// Contain duplicated
 bool containsDuplicate(vector<int>& nums) 
    {
        bool bRet = false;
        int nSize = nums.size();
        
        // 1st solution: Use 2 for loop: 
        for (int i = 0; i < nSize; i++)
        {
            for (int j = i + 1; j < nSize; j++)
            {
                if (nums.at(i) == nums.at(j))
                {
                    bRet = true;
                    break;
                }
            }
            if (bRet == true)
            {
                break;
            }
        }
        
        // 2nd solution: sort then check same element
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (nSize - 1); i++)
        {
            if (nums.at(i) == nums.at(i+1))
            {
                bRet = true;
                break;
            }
            
        }
        return bRet;
    }

// Find the third largest number in array
 int thirdMax(vector<int>& nums) {
	 int nSize = nums.size();
	 if (nSize == 1)
	 {
		 return nums.at(0);
	 }
	 else if (nSize == 2)
	 {
		 return std::max(nums.at(0), nums.at(1));
	 }
	 else
	 {
		 int nFirst = INT_MIN;
		 int nSecond = INT_MIN;
		 int nThird = INT_MIN;
		 for (int i = 0; i < nSize; i++)
		 {
			 int nElm = nums.at(i);
			 if (nElm > nFirst)
			 {
				 nThird = nSecond;
				 nSecond = nFirst;
				 nFirst = nElm;
			 }
             // Elm is between first and second
			 else if (nElm > nSecond && nElm < nFirst)
			 {
				 nThird = nSecond;
				 nSecond = nElm;
			 }
             // Elm is between third and nsecond
			 else if (nElm > nThird && nElm < nSecond)
			 {
				 nThird = nElm;
			 }
		 }
		 return nThird;
	 }
    }

int main()
{
	//char cRet = FindFirstNonrepeatedChar("HungHun");
	string cRet = ReverseString("Nguyen Van Hung Koh Young Technology");
	cout << cRet << endl;
	return 0;
}
