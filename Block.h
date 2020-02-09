//https://davenash.com/2017/10/build-a-blockchain-with-c/

#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
public:
  string sPrevHash;

  Block(uint32_t nIndexIn, const string &sDataIn);

  string GetHash();

  void MineBlock(uint32_t nDifficulty, int ID, int threads);

private:
  uint32_t _nIndex;
  int64_t _nNonce;
  string _sData;
  string _sHash;
  time_t _tTime;
  bool _nonstop = true;

  string _CalculateHash(int64_t nFunctionNonce) const;
};