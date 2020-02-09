#include "Blockchain.h"
#include "omp.h"

#define THREADS 1

Blockchain::Blockchain()
{
  _vChain.emplace_back(Block(0, "Genesis Block"));
  _nDifficulty = 7;
}

void Blockchain::AddBlock(Block bNew)
{
  cout<<"Difficulty: "<<_nDifficulty << endl;
  int i, threads = THREADS;
  bNew.sPrevHash = _GetLastBlock().GetHash();

    #pragma omp parallel num_threads(threads)
    {
        int ID = omp_get_thread_num();
        bNew.MineBlock(_nDifficulty, ID, threads);
    }

  _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
  return _vChain.back();
}