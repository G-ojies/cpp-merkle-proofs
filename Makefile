CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt \
          miner_perf merkle_verify mempool_sorter header_assembler \
          coinbase_gen block_template_gen pubkey_hasher address_encoder \
          bech32_encoder multisig_gen fee_estimator timelock_gen \
          script_stack_sim rbf_simulator coinjoin_sim p2p_handshake inv_handler

all: $(TARGETS)

inv_handler: inv_handler.cpp
	$(CXX) $(CXXFLAGS) inv_handler.cpp -o inv_handler

clean:
	rm -f $(TARGETS)
