#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

struct Comparator {
	bool operator() (const int left, const int right) const {
		return right < left;
	}
};

using namespace std;
int main() {
	
	map<int, char,Comparator> mp;
	 
	mp[1] = 'c';
	mp[0] = 'b';
	mp[10] = 'o';
	mp[8] = 'h';
	mp[5] = 'l';
	mp[22] = 'l';
	mp[-11] = '2';
	auto it = mp.begin();
		cout << it->first << it->second << endl;
	
	

	system("pause");
	
}