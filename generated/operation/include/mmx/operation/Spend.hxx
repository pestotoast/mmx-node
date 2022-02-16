
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_operation_Spend_HXX_
#define INCLUDE_mmx_operation_Spend_HXX_

#include <mmx/operation/package.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Operation.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/txio_key_t.hxx>
#include <mmx/utxo_t.hxx>


namespace mmx {
namespace operation {

class VNX_EXPORT Spend : public ::mmx::Operation {
public:
	
	::mmx::txio_key_t key;
	::mmx::utxo_t utxo;
	
	typedef ::mmx::Operation Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xfa01bec4331109c3ull;
	
	Spend() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual ::mmx::hash_t calc_hash() const override;
	virtual uint64_t calc_min_fee(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const override;
	
	static std::shared_ptr<Spend> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Spend& _value);
	friend std::istream& operator>>(std::istream& _in, Spend& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void Spend::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Spend>(5);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("address", 1); _visitor.accept(address);
	_visitor.type_field("solution", 2); _visitor.accept(solution);
	_visitor.type_field("key", 3); _visitor.accept(key);
	_visitor.type_field("utxo", 4); _visitor.accept(utxo);
	_visitor.template type_end<Spend>(5);
}


} // namespace mmx
} // namespace operation


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_operation_Spend_HXX_
