#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
class PAIR
{
public:
	int first;
	int second;
};
bool compare(PAIR a,const PAIR b)
{
	return a.second > b.second;
}
int main()
{
	vector<PAIR>salaryfrequeny;
	map<int, int>salarynum;
	int num, salaries;
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		cin >> salaries;
		salarynum[salaries]++;
	}
	for (auto i = salarynum.begin(); i!=salarynum.end(); i++)
	{
		PAIR temp;
		temp.first = i->first;
		temp.second = i->second;
		salaryfrequeny.push_back(temp);
	}
	sort(salaryfrequeny.begin(), salaryfrequeny.end(), compare);
	for (int i = 0; i<salaryfrequeny.size(); i++)
	{
		for (int j = 0; j<salaryfrequeny[i].second; j++)
		{
			cout << salaryfrequeny[i].first << " ";
		}
	}
	return 0;
}