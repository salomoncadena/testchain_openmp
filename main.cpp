#include "Blockchain.h"

int main()
{
  Blockchain bChain = Blockchain();

  cout << "Mining block 1..." << endl;
  bChain.AddBlock(Block(1, "Block_1_Data"));

  //cout << "Mining block 2..." << endl;
  //bChain.AddBlock(Block(2, "Block_2_Data"));

  //cout << "Mining block 3..." << endl;
  //bChain.AddBlock(Block(3, "Block_3_Data"));

  return 0;
}

/* 
Compile on OS X
serial: gcc -lstdc++ -o TestChain -std=c++11 -stdlib=libc++ -x c++ main.cpp Block.cpp Blockchain.cpp sha256.cpp
./TestChain
openmp: gcc -Xpreprocessor -fopenmp -lomp -I"$(brew --prefix libomp)/include" -L"$(brew --prefix libomp)/lib" -lstdc++ -std=c++11 -stdlib=libc++ -x c++ main.cpp Block.cpp Blockchain.cpp sha256.cpp -o TestChain

Compile on Ubuntu:
serial: gcc main.cpp Block.cpp Blockchain.cpp sha256.cpp -lstdc++ -o Testchain
openmp: gcc main.cpp Block.cpp Blockchain.cpp sha256.cpp -lstdc++ -fopenmp -o Testchain
*/