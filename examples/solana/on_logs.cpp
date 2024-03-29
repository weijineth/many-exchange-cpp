#include "../../src/json.hpp"

using json = nlohmann::json;

#include "../../src/solana.hpp"

using namespace solana;

int main() {
  Connection connection(cluster_api_url(Cluster::Devnet), Commitment::Processed);

  std::string public_key;
  std::cout << "Enter public key: ";
  std::cin >> public_key;

  int subscriptionId = connection.on_logs(PublicKey(public_key), [&](Result<Logs> result) {
    Logs logs = result.unwrap();
    std::cout << "signature = " << logs.signature << std::endl;
    for (auto log : logs.logs) {
      std::cout << "  " << log << std::endl;
    }
  });
  ASSERT(connection.is_connected());

  for (int i = 0; i < 10; i++) {
    connection.poll();
    sleep(1);
  }

  connection.remove_on_logs_listener(subscriptionId);
  return 0;
}
