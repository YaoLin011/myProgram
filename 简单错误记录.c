/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool comp(pair<string, int> v1,pair<string, int> v2)
{
	return v1.second > v2.second;
}

int main()
{
	vector<pair<string, int>> vec;
	string input;
	vector<pair<string, int>> ::iterator iter;
	while (getline(cin, input)&& input != "0")
	{
		int index = input.rfind("\\",input.npos);  //注意转义字符
		string s = input.substr(index+1);
		vec.push_back(make_pair(s, 1));
		for (iter = vec.begin(); iter != vec.end() - 1; iter++)
		{
			if (iter->first == s)
			{
				iter->second++;
				vec.pop_back();     //只会有一个重复的
				break;
			}

		}	
	}
	stable_sort(vec.begin(), vec.end(), comp);
	int i = 1;
	for (iter = vec.begin(); i <= 8 && iter != vec.end(); i++, iter++)
	{
		int t = iter->first.find(' ');
		if (t > 16)
			iter->first.erase(0, t - 16);
		cout << iter->first << ' ' << iter->second << " " << endl;
	}
	
	system("pause");
}