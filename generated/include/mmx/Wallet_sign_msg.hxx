
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Wallet_sign_msg_HXX_
#define INCLUDE_mmx_Wallet_sign_msg_HXX_

#include <mmx/package.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <vnx/Value.h>


namespace mmx {

class VNX_EXPORT Wallet_sign_msg : public ::vnx::Value {
public:
	
	uint32_t index = 0;
	::mmx::addr_t address;
	::mmx::hash_t msg;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x5bc54cc8b0112d3aull;
	
	Wallet_sign_msg() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<Wallet_sign_msg> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Wallet_sign_msg& _value);
	friend std::istream& operator>>(std::istream& _in, Wallet_sign_msg& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void Wallet_sign_msg::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Wallet_sign_msg>(3);
	_visitor.type_field("index", 0); _visitor.accept(index);
	_visitor.type_field("address", 1); _visitor.accept(address);
	_visitor.type_field("msg", 2); _visitor.accept(msg);
	_visitor.template type_end<Wallet_sign_msg>(3);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_Wallet_sign_msg_HXX_
