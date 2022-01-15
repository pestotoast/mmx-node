
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_NodeBase_HXX_
#define INCLUDE_mmx_NodeBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/stxo_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/txio_key_t.hxx>
#include <mmx/txo_info_t.hxx>
#include <mmx/utxo_entry_t.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class NodeBase : public ::vnx::Module {
public:
	
	::vnx::TopicPtr input_vdfs = "network.vdfs";
	::vnx::TopicPtr input_proof = "network.proof";
	::vnx::TopicPtr input_blocks = "network.blocks";
	::vnx::TopicPtr input_transactions = "network.transactions";
	::vnx::TopicPtr input_timelord_vdfs = "timelord.proofs";
	::vnx::TopicPtr input_harvester_proof = "harvester.proof";
	::vnx::TopicPtr output_verified_vdfs = "node.verified_vdfs";
	::vnx::TopicPtr output_verified_proof = "node.verified_proof";
	::vnx::TopicPtr output_verified_blocks = "node.verified_blocks";
	::vnx::TopicPtr output_committed_blocks = "node.committed_blocks";
	::vnx::TopicPtr output_transactions = "node.transactions";
	::vnx::TopicPtr output_interval_request = "timelord.requests";
	::vnx::TopicPtr output_timelord_infuse = "timelord.infuse";
	::vnx::TopicPtr output_challenges = "harvester.challenges";
	int32_t max_queue_ms = 10000;
	int32_t update_interval_ms = 1000;
	int32_t sync_loss_delay = 60;
	uint32_t max_history = 1000;
	uint32_t tx_pool_limit = 1000000;
	uint32_t max_fork_length = 100000;
	uint32_t max_sync_jobs = 64;
	uint32_t num_sync_retries = 3;
	uint32_t replay_height = -1;
	uint32_t num_vdf_threads = 8;
	uint32_t vdf_check_divider = 10000;
	int32_t opencl_device = 0;
	vnx::bool_t do_sync = true;
	vnx::bool_t light_mode = false;
	std::string storage_path;
	std::string router_name = "Router";
	std::string timelord_name = "TimeLord";
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x289d7651582d76a3ull;
	
	NodeBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const NodeBase& _value);
	friend std::istream& operator>>(std::istream& _in, NodeBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual std::shared_ptr<const ::mmx::ChainParams> get_params() const = 0;
	virtual uint32_t get_height() const = 0;
	virtual vnx::optional<uint32_t> get_synced_height() const = 0;
	virtual std::shared_ptr<const ::mmx::Block> get_block(const ::mmx::hash_t& hash) const = 0;
	virtual std::shared_ptr<const ::mmx::Block> get_block_at(const uint32_t& height) const = 0;
	virtual std::shared_ptr<const ::mmx::BlockHeader> get_header(const ::mmx::hash_t& hash) const = 0;
	virtual std::shared_ptr<const ::mmx::BlockHeader> get_header_at(const uint32_t& height) const = 0;
	virtual vnx::optional<::mmx::hash_t> get_block_hash(const uint32_t& height) const = 0;
	virtual vnx::optional<::mmx::txo_info_t> get_txo_info(const ::mmx::txio_key_t& key) const = 0;
	virtual std::vector<vnx::optional<::mmx::txo_info_t>> get_txo_infos(const std::vector<::mmx::txio_key_t>& keys) const = 0;
	virtual vnx::optional<uint32_t> get_tx_height(const ::mmx::hash_t& id) const = 0;
	virtual std::vector<::mmx::hash_t> get_tx_ids_at(const uint32_t& height) const = 0;
	virtual void add_block(std::shared_ptr<const ::mmx::Block> block) = 0;
	virtual void add_transaction(std::shared_ptr<const ::mmx::Transaction> tx) = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> get_transaction(const ::mmx::hash_t& id) const = 0;
	virtual std::vector<std::shared_ptr<const ::mmx::Transaction>> get_transactions(const std::vector<::mmx::hash_t>& ids) const = 0;
	virtual std::vector<::mmx::tx_entry_t> get_history_for(const std::vector<::mmx::addr_t>& addresses, const int32_t& since) const = 0;
	virtual std::shared_ptr<const ::mmx::Contract> get_contract(const ::mmx::addr_t& address) const = 0;
	virtual uint64_t get_balance(const ::mmx::addr_t& address, const ::mmx::addr_t& contract) const = 0;
	virtual uint64_t get_total_balance(const std::vector<::mmx::addr_t>& addresses, const ::mmx::addr_t& contract) const = 0;
	virtual uint64_t get_total_supply(const ::mmx::addr_t& contract) const = 0;
	virtual std::vector<::mmx::utxo_entry_t> get_utxo_list(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual std::vector<::mmx::stxo_entry_t> get_stxo_list(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual void start_sync(const vnx::bool_t& force) = 0;
	virtual void handle(std::shared_ptr<const ::mmx::Block> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::Transaction> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofOfTime> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofResponse> _value) {}
	virtual void http_request_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const vnx::request_id_t& _request_id) const = 0;
	void http_request_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpResponse>& _ret_0) const;
	virtual void http_request_chunk_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& _request_id) const = 0;
	void http_request_chunk_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpData>& _ret_0) const;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_NodeBase_HXX_
