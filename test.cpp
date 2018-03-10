
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
//*���ַ������һ�����ʵĳ���
//*/
//
//
//int LastWordLen(const char* s)//��ǰ������,len��¼һ�����ʵĳ���,����˵��ʲ������һ��,len=0
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
//*��·��
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
*�ɵߵ���ĸ˳������ɵĴ� Anagrams
*Ҫ��:������������,�ж��Ƿ�ΪAnagrams
*����:����Eat �� Tea,�����
*˼·:����������,�����,�����Ҫ��
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
*�ɵߵ���ĸ˳������ɵĴ� Anagrams
*Ҫ��:�ж�һ���ַ��������е�Anagrams
*����:���� [��eat��, ��tea��, ��tan��, ��ate��, ��nat��, ��bat��]
*	  ���[
*			[��ate��, ��eat��,��tea��],
*			[��nat��,��tan��],
*			[��bat��]
*		  ] 
*˼·:��������鶼���ֵ�˳��,�������Ҫ����
*	  ���ù�ϣ˼��,��Anagrams�ֵ�˳��ĵ�һ������Ϊkeyֵ,
*	  ��ͬ��Anagrams�洢����ϣ��
*	  �ù�ϣ������ά����
*/
vector<vector<string> > groupAnagrams(vector<string>& strs)
{
	if (strs.empty())
		return vector<vector<string> >();

	int len = strs.size();

	//���ַ��������ֵ�˳������
	sort(strs.begin(),strs.end());

	vector<vector<string> > ret;

	//���ù�ϣ˼�빹��map,��string ��ȵ��ַ����洢����Ӧ��map
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
*count and say-��һ������n,������ĵ�n������
*����:1,��1��1,����11--������һ������
*	  11��2��1,����21--�ڶ�������
*	  21,����1211--����������
*	  1211,����111221
*	  111221,����312211
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