
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_stxo_entry_t_HXX_
#define INCLUDE_mmx_stxo_entry_t_HXX_

#include <mmx/package.hxx>
#include <mmx/txio_key_t.hxx>
#include <mmx/utxo_entry_t.hxx>
#include <mmx/utxo_t.hxx>


namespace mmx {

struct stxo_entry_t : ::mmx::utxo_entry_t {
	
	
	::mmx::txio_key_t spent;
	
	typedef ::mmx::utxo_entry_t Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x7655c1e23969201bull;
	
	stxo_entry_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static ::mmx::stxo_entry_t create_ex(const ::mmx::txio_key_t& key = ::mmx::txio_key_t(), const ::mmx::utxo_t& output = ::mmx::utxo_t(), const ::mmx::txio_key_t& spent = ::mmx::txio_key_t());
	
	static std::shared_ptr<stxo_entry_t> create();
	std::shared_ptr<stxo_entry_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const stxo_entry_t& _value);
	friend std::istream& operator>>(std::istream& _in, stxo_entry_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::stxo_entry_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_stxo_entry_t_HXX_
