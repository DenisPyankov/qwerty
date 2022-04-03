#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 

int main()
{

	ifstream in("in.txt");
	ofstream out("out.txt");
	int N, D;
	in >> N >> D;
	vector<int> v;
	map<int, int> m;
	vector<int> res;
	for (int i = 0; i < N; i++) {
		int a;
		in >> a;
		v.push_back(a);
		m[a] = 0;
		res.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());
	int max = -1234;
	int k = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i; j < v.size(); j++) {
			if (v[i] - v[j] <= D) {
				k++;
			}
		}
		if (k > max) 
			max = k ;
		k = 0;
	}
	out << max << endl;

	int c = 1;
	for (int i = 0; i < v.size(); i++) {
		if (c > max)
			c = 1;
		m[v[i]] = c;
		c++;
	}

	for (int i = 0; i < v.size(); i++)
		out << m[res[i]] << " ";

}
