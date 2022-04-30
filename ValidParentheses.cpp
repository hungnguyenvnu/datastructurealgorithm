/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order. */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stParen;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stParen.push(s[i]);
            }
            else
            {
                if (!stParen.empty())
                {
                    char cTop = stParen.top();
                    if ((cTop == '(' && s[i] == ')')
                       || (cTop == '[' && s[i] == ']')
                        || (cTop == '{' && s[i] == '}'))
                        {
                            stParen.pop();
                        }
                        else
                        {
                            return false;
                        }
                }
                else
                {
                    return false;
                }
            }
        }
        return stParen.empty();
    }
};
