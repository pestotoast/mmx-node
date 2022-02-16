
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_RouterBase_HXX_
#define INCLUDE_mmx_RouterBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/PeerInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/node_info_t.hxx>
#include <mmx/node_type_e.hxx>
#include <mmx/pubkey_t.hpp>
#include <mmx/signature_t.hpp>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/MsgServer.h>


namespace mmx {

class VNX_EXPORT RouterBase : public ::vnx::addons::MsgServer {
public:
	
	::vnx::TopicPtr input_vdfs = "timelord.proofs";
	::vnx::TopicPtr input_blocks = "node.verified_blocks";
	::vnx::TopicPtr input_verified_vdfs = "node.verified_vdfs";
	::vnx::TopicPtr input_verified_proof = "node.verified_proof";
	::vnx::TopicPtr input_transactions = "node.transactions";
	::vnx::TopicPtr output_vdfs = "network.vdfs";
	::vnx::TopicPtr output_proof = "network.proof";
	::vnx::TopicPtr output_blocks = "network.blocks";
	::vnx::TopicPtr output_transactions = "network.transactions";
	int32_t max_queue_ms = 1000;
	int32_t send_interval_ms = 20;
	int32_t query_interval_ms = 10000;
	int32_t update_interval_ms = 1000;
	int32_t connect_interval_ms = 10000;
	int32_t fetch_timeout_ms = 10000;
	int32_t relay_target_ms = 5000;
	uint32_t sync_loss_delay = 60;
	uint32_t discover_interval = 60;
	uint32_t num_threads = 32;
	uint32_t num_peers_out = 8;
	uint32_t min_sync_peers = 2;
	uint32_t max_sync_peers = 4;
	uint32_t max_sent_cache = 20000;
	uint32_t max_hash_cache = 100000;
	uint32_t tx_credits = 10000;
	uint32_t vdf_credits = 1024;
	uint32_t block_credits = 256;
	uint32_t proof_credits = 10;
	uint32_t vdf_relay_cost = 768;
	uint32_t proof_relay_cost = 2;
	uint32_t block_relay_cost = 8;
	uint32_t max_node_credits = 1024;
	uint32_t max_farmer_credits = 32;
	uint32_t node_version = 102;
	::mmx::node_type_e mode = ::mmx::node_type_e::FULL_NODE;
	vnx::bool_t do_relay = true;
	std::set<std::string> seed_peers;
	std::set<std::string> block_peers;
	std::string storage_path;
	std::string node_server = "Node";
	
	typedef ::vnx::addons::MsgServer Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x952c4ef2956f31c4ull;
	
	RouterBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const RouterBase& _value);
	friend std::istream& operator>>(std::istream& _in, RouterBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual void discover() = 0;
	virtual ::mmx::hash_t get_id() const = 0;
	virtual ::mmx::node_info_t get_info() const = 0;
	virtual std::pair<::mmx::pubkey_t, ::mmx::signature_t> sign_msg(const ::mmx::hash_t& msg) const = 0;
	virtual std::vector<std::string> get_peers(const uint32_t& max_count) const = 0;
	virtual std::vector<std::string> get_known_peers() const = 0;
	virtual std::vector<std::string> get_connected_peers() const = 0;
	virtual std::shared_ptr<const ::mmx::PeerInfo> get_peer_info() const = 0;
	virtual std::vector<std::pair<std::string, uint32_t>> get_farmer_credits() const = 0;
	virtual void get_blocks_at_async(const uint32_t& height, const vnx::request_id_t& _request_id) const = 0;
	void get_blocks_at_async_return(const vnx::request_id_t& _request_id, const std::vector<std::shared_ptr<const ::mmx::Block>>& _ret_0) const;
	virtual void fetch_block_async(const ::mmx::hash_t& hash, const vnx::optional<std::string>& address, const vnx::request_id_t& _request_id) const = 0;
	void fetch_block_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::mmx::Block>& _ret_0) const;
	virtual void fetch_block_at_async(const uint32_t& height, const std::string& address, const vnx::request_id_t& _request_id) const = 0;
	void fetch_block_at_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::mmx::Block>& _ret_0) const;
	virtual void handle(std::shared_ptr<const ::mmx::Block> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::Transaction> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofOfTime> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofResponse> _value) {}
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};

template<typename T>
void RouterBase::accept_generic(T& _visitor) const {
	_visitor.template type_begin<RouterBase>(52);
	_visitor.type_field("port", 0); _visitor.accept(port);
	_visitor.type_field("host", 1); _visitor.accept(host);
	_visitor.type_field("max_connections", 2); _visitor.accept(max_connections);
	_visitor.type_field("listen_queue_size", 3); _visitor.accept(listen_queue_size);
	_visitor.type_field("stats_interval_ms", 4); _visitor.accept(stats_interval_ms);
	_visitor.type_field("connection_timeout_ms", 5); _visitor.accept(connection_timeout_ms);
	_visitor.type_field("send_buffer_size", 6); _visitor.accept(send_buffer_size);
	_visitor.type_field("receive_buffer_size", 7); _visitor.accept(receive_buffer_size);
	_visitor.type_field("tcp_no_delay", 8); _visitor.accept(tcp_no_delay);
	_visitor.type_field("tcp_keepalive", 9); _visitor.accept(tcp_keepalive);
	_visitor.type_field("show_warnings", 10); _visitor.accept(show_warnings);
	_visitor.type_field("max_msg_size", 11); _visitor.accept(max_msg_size);
	_visitor.type_field("input_vdfs", 12); _visitor.accept(input_vdfs);
	_visitor.type_field("input_blocks", 13); _visitor.accept(input_blocks);
	_visitor.type_field("input_verified_vdfs", 14); _visitor.accept(input_verified_vdfs);
	_visitor.type_field("input_verified_proof", 15); _visitor.accept(input_verified_proof);
	_visitor.type_field("input_transactions", 16); _visitor.accept(input_transactions);
	_visitor.type_field("output_vdfs", 17); _visitor.accept(output_vdfs);
	_visitor.type_field("output_proof", 18); _visitor.accept(output_proof);
	_visitor.type_field("output_blocks", 19); _visitor.accept(output_blocks);
	_visitor.type_field("output_transactions", 20); _visitor.accept(output_transactions);
	_visitor.type_field("max_queue_ms", 21); _visitor.accept(max_queue_ms);
	_visitor.type_field("send_interval_ms", 22); _visitor.accept(send_interval_ms);
	_visitor.type_field("query_interval_ms", 23); _visitor.accept(query_interval_ms);
	_visitor.type_field("update_interval_ms", 24); _visitor.accept(update_interval_ms);
	_visitor.type_field("connect_interval_ms", 25); _visitor.accept(connect_interval_ms);
	_visitor.type_field("fetch_timeout_ms", 26); _visitor.accept(fetch_timeout_ms);
	_visitor.type_field("relay_target_ms", 27); _visitor.accept(relay_target_ms);
	_visitor.type_field("sync_loss_delay", 28); _visitor.accept(sync_loss_delay);
	_visitor.type_field("discover_interval", 29); _visitor.accept(discover_interval);
	_visitor.type_field("num_threads", 30); _visitor.accept(num_threads);
	_visitor.type_field("num_peers_out", 31); _visitor.accept(num_peers_out);
	_visitor.type_field("min_sync_peers", 32); _visitor.accept(min_sync_peers);
	_visitor.type_field("max_sync_peers", 33); _visitor.accept(max_sync_peers);
	_visitor.type_field("max_sent_cache", 34); _visitor.accept(max_sent_cache);
	_visitor.type_field("max_hash_cache", 35); _visitor.accept(max_hash_cache);
	_visitor.type_field("tx_credits", 36); _visitor.accept(tx_credits);
	_visitor.type_field("vdf_credits", 37); _visitor.accept(vdf_credits);
	_visitor.type_field("block_credits", 38); _visitor.accept(block_credits);
	_visitor.type_field("proof_credits", 39); _visitor.accept(proof_credits);
	_visitor.type_field("vdf_relay_cost", 40); _visitor.accept(vdf_relay_cost);
	_visitor.type_field("proof_relay_cost", 41); _visitor.accept(proof_relay_cost);
	_visitor.type_field("block_relay_cost", 42); _visitor.accept(block_relay_cost);
	_visitor.type_field("max_node_credits", 43); _visitor.accept(max_node_credits);
	_visitor.type_field("max_farmer_credits", 44); _visitor.accept(max_farmer_credits);
	_visitor.type_field("node_version", 45); _visitor.accept(node_version);
	_visitor.type_field("mode", 46); _visitor.accept(mode);
	_visitor.type_field("do_relay", 47); _visitor.accept(do_relay);
	_visitor.type_field("seed_peers", 48); _visitor.accept(seed_peers);
	_visitor.type_field("block_peers", 49); _visitor.accept(block_peers);
	_visitor.type_field("storage_path", 50); _visitor.accept(storage_path);
	_visitor.type_field("node_server", 51); _visitor.accept(node_server);
	_visitor.template type_end<RouterBase>(52);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_RouterBase_HXX_
