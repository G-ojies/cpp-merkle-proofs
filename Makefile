CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt \
          miner_perf merkle_verify mempool_sorter header_assembler \
          coinbase_gen block_template_gen pubkey_hasher address_encoder \
          bech32_encoder multisig_gen fee_estimator timelock_gen \
          script_stack_sim rbf_simulator coinjoin_sim

all: $(TARGETS)

coinjoin_sim: coinjoin_sim.cpp
	$(CXX) $(CXXFLAGS) coinjoin_sim.cpp -o coinjoin_sim

clean:
	rm -f $(TARGETS)
