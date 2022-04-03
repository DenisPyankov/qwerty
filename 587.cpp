#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct d {
	float power;
	float deg;
	int num;
};

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int n;
	in >> n;
	vector<d> v;
	vector<int> res;
	
	for (int i = 0; i < n; i++) {
		float a, s;
		in >> a >> s;
		if (s <= 90 && s >= 0) {
			v[i].power = a;
			v[i].deg = s;
			v[i].num = i + 1;
		}
		if (s >= 270 && s <= 360) {
			v[i].power = a;
			v[i].deg = s-180;
			v[i].num = i + 1;
		}
		
	}
	
	for (int i = 0; i < n-1; i++) {
		int m = 0;
		for (int j = i + 1; j < n; j++) {

			if (v[i].deg == v[j].deg)
				if (v[i].power < v[j].power )
					m++;

		}

		if (m == 0  )
			res.push_back(v[i].num);

	}


	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";



}
