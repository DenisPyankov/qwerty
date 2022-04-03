#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int N, K;
	in >> N >> K;
	string S;
	in >> S;
	map<char, int> m;
	map<char, int>::iterator it;
	for (int i = 0; i < N; i++)
		m[S[i]] = 0;
	int c = S.length();

	for (int i = 0; i < S.length()-1; i++) {
		m[S[i]]++;
		for (int j = i+1; j < S.length(); j++) {
			m[S[j]]++;
			int n = 0;
			for (it = m.begin(); it != m.end(); it++)
				if (it->second > K)
					n++;
			if (n != 0)
				break;
			else { c++; }
			}
		for (it = m.begin(); it != m.end(); it++)
			it->second = 0;
	}
	
	out << c;
}
