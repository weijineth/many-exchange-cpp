#include "../src/solana.h"

using namespace solana;

int main() {
  Connection connection(clusterApiUrl(Cluster::MainnetBeta), Commitment::Processed);
  auto slotLeader = connection.getSlotLeader();

  std::cout << "slot leader = " << slotLeader << std::endl << std::endl;

  return 0;
}
