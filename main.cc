#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include "bloomfilter.h"
using namespace std;

const int MAXSIZE = 400000000; 
int main(int argc, char **argv)
{
	char *poolfile = argv[1];
	char *testfile = argv[2];
	cout << poolfile << endl;
	ifstream fpool(poolfile);
	ifstream ftest(testfile);
	if(!fpool)
	{
		cout << "cannot open the file:" << poolfile << endl;
		return 0;
	}
	if(!ftest)
	{
		cout << "cannot open the file:" << testfile << endl;
		return 0;
	}
	BloomFilter bf(MAXSIZE);
	bf.setBit(fpool);
	cout << "Store OK" << endl;
	bf.checkBit(ftest);
	cout << "Check OK" << endl;
	fpool.close();
	ftest.close();
}
