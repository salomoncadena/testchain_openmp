#include <sstream>
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
  _nNonce = -1;
  _tTime = time(nullptr);
}

string Block::GetHash()
{
  return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty, int ID, int threads)
{
  char cstr[nDifficulty + 1];
  int64_t nLocalNonce;
  string sLocalHash;
  for (uint32_t i = 0; i < nDifficulty; ++i)
  {
    cstr[i] = '0';
  }
  cstr[nDifficulty] = '\0';

  string str(cstr);

  nLocalNonce = ID - threads;
  do
  {
    nLocalNonce+= threads;
    sLocalHash = _CalculateHash(nLocalNonce);
    //cout<<"Thread "<<ID<<" of "<<threads<<". LocalNonce: "<<nLocalNonce<<" NonStop: "<<_nonstop<<" Local Hash: "<<sLocalHash.substr(0, nDifficulty)<<endl;
  //} while (sLocalHash.substr(0, nDifficulty) != str);
  } while (_nonstop && (sLocalHash.substr(0, nDifficulty) != str));

  if (sLocalHash.substr(0, nDifficulty) == str){
    _nonstop = false;
    _nNonce = nLocalNonce;
    _sHash = sLocalHash;
    cout << "Block mined: " << _sHash << " Nonce: " << _nNonce << endl;
  }
  
}

inline string Block::_CalculateHash(int64_t nFunctionNonce) const

{
  stringstream ss;
  /*
  ss << _nIndex << _tTime << _sData << nFunctionNonce << sPrevHash;
  ss << _nIndex << " " << _tTime << " " << _sData << " " << nFunctionNonce << " " << sPrevHash;
  */
  ss << _nIndex << _sData << nFunctionNonce << sPrevHash;
  ss << _nIndex << " " << " " << _sData << " " << nFunctionNonce << " " << sPrevHash;
  // cout << ss.str() << endl;
  return sha256(ss.str());
}
