
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Solution_HXX_
#define INCLUDE_mmx_Solution_HXX_

#include <mmx/package.hxx>
#include <mmx/ChainParams.hxx>
#include <vnx/Value.h>


namespace mmx {

class MMX_EXPORT Solution : public ::vnx::Value {
public:
	
	uint32_t version = 0;
	vnx::bool_t is_contract = 0;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x9f693babd1a91ccdull;
	
	Solution() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual uint64_t calc_min_fee(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const;
	
	static std::shared_ptr<Solution> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Solution& _value);
	friend std::istream& operator>>(std::istream& _in, Solution& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void Solution::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Solution>(2);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("is_contract", 1); _visitor.accept(is_contract);
	_visitor.template type_end<Solution>(2);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_Solution_HXX_
