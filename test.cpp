
#include<math.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//
//void Probability(int originl,int cur,int sum,int* pPro)
//{
//	if (1 == cur)
//		pPro[sum-originl]++;
//	else
//	{
//		for (int i = 1; i <= 6; ++i)
//			Probability(originl,cur-1,i+sum,pPro);
//	}
//}
//
//void probability(int number, int* pPro)
//{
//	for (int i = 0; i < 6; ++i)
//	{
//		Probability(number,number,i+1,pPro);
//	}
//}
//
//void PrintProbability(int number)
//{
//	if (number < 1)
//		return;
//
//	int MaxSum = number * 6;
//	int* pPro = new int[MaxSum-number-1];
//	for (int i = 0; i < MaxSum - number - 1; ++i)
//		pPro[i] = 0;
//
//	probability(number,pPro);
//
//	int total = pow(6.0,number);
//
//	for (int i = 1; i <= 6; ++i)
//	{
//		double ratio = pPro[i-number]/total;
//		printf("%d:%e\n",i,ratio);
//	}
//	delete []pPro;
//}
//
//int main()
//{
//	PrintProbability(1);
//	return 0;
//}


///*
//*求字符串最后一个单词的长度
//*/
//
//
//int LastWordLen(const char* s)//从前向后遍历,len记录一个单词的长度,如果此单词不是最后一个,len=0
//{
//	if (NULL == s)
//		return 0;
//
//	int len = 0;
//	while (*s != '\0')
//	{
//		len++;
//		if (*s == ' ')
//			len = 0;
//		s++;
//	}
//	return len;
//}
//
//int LastWordLen1(const char* s)
//{
//	if (NULL == s)
//		return 0;
//
//	string str(s);
//	size_t start = str.find_last_of(' ');
//	return str.size() - start - 1;
//}

///*
//*简化路径
//*/
//string simplifyPath(const string& path)
//{
//	vector<string> stack;
//
//	int i = 0;
//	while (i < path.size())
//	{
//		while (i < path.size() && path[i] == '/')
//			++i;
//		if (path.size() == i)
//			break;
//		int start = i;
//		while (i < path.size() && path[i] != '/')
//			++i;
//		int end = i - 1;
//
//		if (path.size() == i)
//			break;
//
//		string s = path.substr(start,end-start+1);
//
//		if (s == "..")
//		{
//			if (!stack.empty())
//				stack.pop_back();
//		}
//		else if (s != ".")
//			stack.push_back(s);		
//	}
//
//	if (stack.empty())
//		return "/";
//
//	string ret;
//	while (!stack.empty())
//	{
//		ret += '/' + stack.back();
//		stack.pop_back();
//	}
//	return ret;
//}


/*
*由颠倒字母顺序而构成的词 Anagrams
*要求:输入两个单词,判断是否为Anagrams
*例如:输入Eat 和 Tea,输出是
*思路:将单词排序,若相等,则符合要求
*/
bool IsAnagrams(const string& s1, const string& s2)
{
	if (s1.size() != s2.size())
		return false;
	string str1(s1);
	string str2(s2);
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] += 32;

		if (str2[i] >= 'A' && str2[i] <= 'Z')
			str2[i] += 32;
	}
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	if (str1 == str2)
		return true;
	else
		return false;
}

/*
*由颠倒字母顺序而构成的词 Anagrams
*要求:判断一组字符串数组中的Anagrams
*例如:输入 [“eat”, “tea”, “tan”, “ate”, “nat”, “bat”]
*	  输出[
*			[“ate”, “eat”,”tea”],
*			[“nat”,”tan”],
*			[“bat”]
*		  ] 
*思路:输出的数组都是字典顺序,因此先需要排序
*	  利用哈希思想,以Anagrams字典顺序的第一个单词为key值,
*	  把同类Anagrams存储到哈希表
*	  用哈希表构建二维数组
*/
vector<vector<string> > groupAnagrams(vector<string>& strs)
{
	if (strs.empty())
		return vector<vector<string> >();

	int len = strs.size();

	//将字符串按照字典顺序排序
	sort(strs.begin(),strs.end());

	vector<vector<string> > ret;

	//利用哈希思想构建map,将string 相等的字符串存储在相应的map
	map<string, vector<string> > mp;
	for (int i = 0; i < len; ++i)
	{
		string s = strs[i];
		sort(s.begin(),s.end());
		mp[s].push_back(strs[i]);
	}

	for (map<string, vector<string> >::iterator it = mp.begin(); it != mp.end();++it)
		ret.push_back(it->second);

	return ret;
}

/*
*count and say-给一个整数n,输出它的第n个读法
*例如:1,是1个1,读作11--记做第一个读法
*	  11是2个1,读作21--第二个读法
*	  21,读作1211--第三个读法
*	  1211,读作111221
*	  111221,读作312211
*
*/
string countAndsay(int n)
{
	if (n < 1)
		return "";
	
	string s("1");
	while(--n)
	{
		string cur = "";
		for (int i = 0; i < s.size(); ++i)
		{
			int cnt = 1;
			while (i + 1 < s.size() && s[i] == s[i + 1])
			{
				++cnt;
				++i;
			}
			cur += to_string(cnt) + s[i];
		}
		s = cur;
	}
	return s;
}

int main()
{
	/*char* str = "";
	cout << LastWordLen1(str);*/
	/*string path("/a/./b/../../c/");*/
	/*cout<<simplifyPath(path);*/
	/*string s1("Eat");
	string s2("Tea");
	bool ret = IsAnagrams(s1,s2);*/

	//vector<string> strs;
	//strs.push_back("eat");
	//strs.push_back("tea");
	//strs.push_back("tan");
	//strs.push_back("ate");
	//strs.push_back("nat");
	//strs.push_back("bat");

	//groupAnagrams(strs);
	cout << countAndsay(5);
}