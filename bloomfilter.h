#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "hash.h"
using namespace std;
class BloomFilter
{
	public:
		BloomFilter(int size) : SIZE(size) { vec.resize(size); };
		void setBit(ifstream &f);
		void setBit(const string &s);
		void setBit(unsigned int count);

		bool checkBit(ifstream &f);
		bool checkBit(const string &s);
		bool checkBit(unsigned int count);
	private:
		vector<char> vec;
		const unsigned int SIZE;
};
