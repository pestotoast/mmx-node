
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exchange_trade_entry_t_HXX_
#define INCLUDE_mmx_exchange_trade_entry_t_HXX_

#include <vnx/Type.h>
#include <mmx/exchange/package.hxx>
#include <mmx/exchange/trade_type_e.hxx>
#include <mmx/hash_t.hpp>


namespace mmx {
namespace exchange {

struct VNX_EXPORT trade_entry_t {
	
	
	::mmx::hash_t id;
	uint32_t height = 0;
	::mmx::exchange::trade_type_e type;
	uint64_t bid = 0;
	uint64_t ask = 0;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x3d465e4d012518b0ull;
	
	trade_entry_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static std::shared_ptr<trade_entry_t> create();
	std::shared_ptr<trade_entry_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const trade_entry_t& _value);
	friend std::istream& operator>>(std::istream& _in, trade_entry_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void trade_entry_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<trade_entry_t>(5);
	_visitor.type_field("id", 0); _visitor.accept(id);
	_visitor.type_field("height", 1); _visitor.accept(height);
	_visitor.type_field("type", 2); _visitor.accept(type);
	_visitor.type_field("bid", 3); _visitor.accept(bid);
	_visitor.type_field("ask", 4); _visitor.accept(ask);
	_visitor.template type_end<trade_entry_t>(5);
}


} // namespace mmx
} // namespace exchange


namespace vnx {

template<>
struct is_equivalent<::mmx::exchange::trade_entry_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_exchange_trade_entry_t_HXX_
