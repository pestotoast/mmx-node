
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_ChainParams_HXX_
#define INCLUDE_mmx_ChainParams_HXX_

#include <mmx/package.hxx>
#include <mmx/ulong_fraction_t.hxx>
#include <vnx/Value.h>


namespace mmx {

class MMX_EXPORT ChainParams : public ::vnx::Value {
public:
	
	uint32_t port = 0;
	uint32_t decimals = 6;
	uint32_t min_ksize = 30;
	uint32_t max_ksize = 42;
	uint32_t plot_filter = 10;
	uint32_t commit_delay = 18;
	uint32_t finality_delay = 6;
	uint32_t challenge_delay = 9;
	uint32_t challenge_interval = 48;
	uint32_t max_diff_adjust = 10;
	uint32_t min_vdf_segments = 320;
	uint32_t num_vdf_segments = 760;
	uint32_t max_vdf_segments = 1024;
	uint32_t max_tx_base_out = 10;
	uint32_t recursive_interval = 60480;
	uint32_t score_bits = 16;
	uint32_t score_target = 8192;
	uint32_t score_threshold = 65536;
	uint32_t max_weight_buffer = 262144;
	uint64_t min_reward = 200000;
	::mmx::ulong_fraction_t reward_factor;
	uint64_t time_diff_constant = 1000;
	uint64_t space_diff_constant = 100000000;
	uint64_t initial_time_diff = 10000;
	uint64_t initial_space_diff = 10;
	uint64_t min_txfee_io = 100;
	uint64_t min_txfee_sign = 1000;
	uint64_t min_txfee_exec = 10000;
	uint64_t min_txfee_byte = 10;
	uint64_t max_block_cost = 10000000;
	vnx::float64_t block_time = 10;
	std::string vdf_seed;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x51bba8d28881e8e7ull;
	
	ChainParams() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<ChainParams> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const ChainParams& _value);
	friend std::istream& operator>>(std::istream& _in, ChainParams& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void ChainParams::accept_generic(T& _visitor) const {
	_visitor.template type_begin<ChainParams>(32);
	_visitor.type_field("port", 0); _visitor.accept(port);
	_visitor.type_field("decimals", 1); _visitor.accept(decimals);
	_visitor.type_field("min_ksize", 2); _visitor.accept(min_ksize);
	_visitor.type_field("max_ksize", 3); _visitor.accept(max_ksize);
	_visitor.type_field("plot_filter", 4); _visitor.accept(plot_filter);
	_visitor.type_field("commit_delay", 5); _visitor.accept(commit_delay);
	_visitor.type_field("finality_delay", 6); _visitor.accept(finality_delay);
	_visitor.type_field("challenge_delay", 7); _visitor.accept(challenge_delay);
	_visitor.type_field("challenge_interval", 8); _visitor.accept(challenge_interval);
	_visitor.type_field("max_diff_adjust", 9); _visitor.accept(max_diff_adjust);
	_visitor.type_field("min_vdf_segments", 10); _visitor.accept(min_vdf_segments);
	_visitor.type_field("num_vdf_segments", 11); _visitor.accept(num_vdf_segments);
	_visitor.type_field("max_vdf_segments", 12); _visitor.accept(max_vdf_segments);
	_visitor.type_field("max_tx_base_out", 13); _visitor.accept(max_tx_base_out);
	_visitor.type_field("recursive_interval", 14); _visitor.accept(recursive_interval);
	_visitor.type_field("score_bits", 15); _visitor.accept(score_bits);
	_visitor.type_field("score_target", 16); _visitor.accept(score_target);
	_visitor.type_field("score_threshold", 17); _visitor.accept(score_threshold);
	_visitor.type_field("max_weight_buffer", 18); _visitor.accept(max_weight_buffer);
	_visitor.type_field("min_reward", 19); _visitor.accept(min_reward);
	_visitor.type_field("reward_factor", 20); _visitor.accept(reward_factor);
	_visitor.type_field("time_diff_constant", 21); _visitor.accept(time_diff_constant);
	_visitor.type_field("space_diff_constant", 22); _visitor.accept(space_diff_constant);
	_visitor.type_field("initial_time_diff", 23); _visitor.accept(initial_time_diff);
	_visitor.type_field("initial_space_diff", 24); _visitor.accept(initial_space_diff);
	_visitor.type_field("min_txfee_io", 25); _visitor.accept(min_txfee_io);
	_visitor.type_field("min_txfee_sign", 26); _visitor.accept(min_txfee_sign);
	_visitor.type_field("min_txfee_exec", 27); _visitor.accept(min_txfee_exec);
	_visitor.type_field("min_txfee_byte", 28); _visitor.accept(min_txfee_byte);
	_visitor.type_field("max_block_cost", 29); _visitor.accept(max_block_cost);
	_visitor.type_field("block_time", 30); _visitor.accept(block_time);
	_visitor.type_field("vdf_seed", 31); _visitor.accept(vdf_seed);
	_visitor.template type_end<ChainParams>(32);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_ChainParams_HXX_
