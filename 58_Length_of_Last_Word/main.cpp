#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
	{
		int result = 0;
		int size = s.size() - 1;
		while(size >= 0)
		{
			if(s.at(size) == ' ')
			{
				if(result != 0)
					return result;
			}
			else
			{
				result++;
			}
			size--;
		}
		return result;
    }
};

int main(void)
{
	string s1("Hello World");
	string s2("   fly me   to   the moon  ");
	string s3("luffy is still joyboy");
	Solution s;
	cout << s.lengthOfLastWord(s1) << endl;
	cout << s.lengthOfLastWord(s2) << endl;
	cout << s.lengthOfLastWord(s3) << endl;
	return 1;
}

