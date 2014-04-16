#include "bloomfilter.h"

void BloomFilter::setBit(ifstream &f)
{
	string line;
	while(f >> line)
	{
		setBit(line);
	}
}

bool BloomFilter::checkBit(ifstream &f)
{
	string line;
	while(f >> line)
	{
		if(!checkBit(line))
			cout << line << endl;
	}
}

void BloomFilter::setBit(const string &s)
{
	unsigned int bitpos = 0;
	const char *str = s.c_str();
	int len = s.size();

	bitpos = RSHash(str, len);
	setBit(bitpos);
	bitpos = JSHash(str, len);
	setBit(bitpos);
	bitpos = PJWHash(str, len);
	setBit(bitpos);
	bitpos = ELFHash(str, len);
	setBit(bitpos);
	bitpos = BKDRHash(str, len);
	setBit(bitpos);
	bitpos = SDBMHash(str, len);
	setBit(bitpos);
	bitpos = DJBHash(str, len);
	setBit(bitpos);
	bitpos = DEKHash(str, len);
	setBit(bitpos);
	bitpos = BPHash(str, len);
	setBit(bitpos);
	bitpos = FNVHash(str, len);
	setBit(bitpos);
}

bool BloomFilter::checkBit(const string &s)
{
	unsigned int bitpos = 0;
	const char *str = s.c_str();
	int len = s.size();
	bool rev = true;

	bitpos = RSHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = JSHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = PJWHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = ELFHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = BKDRHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = SDBMHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = DJBHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = DEKHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = BPHash(str, len);
	rev &= checkBit(bitpos);
	bitpos = FNVHash(str, len);
	rev &= checkBit(bitpos);
	return rev;
}

void BloomFilter::setBit(unsigned int count)
{
	count = count % (SIZE * 8);
	vec[count / 8] |= (1 << (count % 8));
}

bool BloomFilter::checkBit(unsigned int count)
{
	count = count % (SIZE * 8);
	return vec[count / 8] &= (1 << (count % 8));
}
