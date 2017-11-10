/*
对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。保证字符串中有重复字符，字符串的长度小于等于500。
*/
class FirstRepeat {
public:
    char findFirstRepeat(string A, int n) {
        // write code here
    vector<char> c;
	for (int i = 0; i < n; i++)
	{
		if (find(c.begin(), c.end(), A[i]) == c.end())
			c.push_back(A[i]);
		else
			return A[i];
	}
        return -1;
    }
};