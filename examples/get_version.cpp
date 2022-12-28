#include "../src/json.hpp"
#include "../src/solana.hpp"

using namespace solana;

int main() {
  Connection connection(clusterApiUrl(Cluster::MainnetBeta), Commitment::Processed);
  auto version = connection.get_version();

  std::cout << "version = " << version << std::endl << std::endl;

  return 0;
}
