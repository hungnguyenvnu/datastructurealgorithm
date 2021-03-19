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

int main()
{
	//char cRet = FindFirstNonrepeatedChar("HungHun");
	string cRet = ReverseString("Nguyen Van Hung Koh Young Technology");
	cout << cRet << endl;
	return 0;
}