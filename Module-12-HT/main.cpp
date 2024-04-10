#include <iostream>
#include <string>

using namespace std;


bool IskPeriodic(string& str, int K)
{
	if (str.empty() || K <= 0)
	{
		cout << str.size() << endl;
		cout << K << endl;
		cout << "Ошибка: пустая строка или K = 0" << endl;
		return false;
	}

	int length = str.size();

	for (int i = 0; i < K; i++)
	{
		//cout << "i = " << i << " = " << str[i] << endl;
		for (int j = i+K; j < length; j+=K)
		{
			//cout << "J = " << j << " = " << str[j] << endl;
			if (str[j] != str[i])
			{
				return false;
			}
		}
	}
	return true;
}

void computeLPS(string pat, int* lps)
{
	int j = 0;

	lps[0] = 0;

	int i = 1;

	while (i < pat.size()) 
	{
		if (pat[i] == pat[j]) 
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	for (int i = 0; i < pat.size(); i++)
	{
		cout << lps[i] << endl;
	}
}

auto main() -> int
{
	setlocale(LC_ALL,"");

	string str = "abcabcabc";
	string q;
	int K = 3;

	if (IskPeriodic(str, K))
	{
		cout << str << " кратно " << K << endl;
	}
	else
	{
		cout << str << "не кратно " << K << endl;
	}
	return 0;
}
	