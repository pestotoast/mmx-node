
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exchange_LocalTrade_HXX_
#define INCLUDE_mmx_exchange_LocalTrade_HXX_

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/trade_pair_t.hxx>
#include <mmx/exchange/trade_type_e.hxx>
#include <mmx/hash_t.hpp>
#include <vnx/Value.h>


namespace mmx {
namespace exchange {

class LocalTrade : public ::vnx::Value {
public:
	
	::mmx::hash_t id;
	vnx::bool_t failed = 0;
	vnx::optional<uint32_t> height;
	::mmx::exchange::trade_pair_t pair;
	::mmx::exchange::trade_type_e type = ::mmx::exchange::trade_type_e::SELL;
	uint64_t bid = 0;
	uint64_t ask = 0;
	vnx::optional<uint64_t> offer_id;
	vnx::optional<std::string> message;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x63fd417b165df53cull;
	
	LocalTrade() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual std::shared_ptr<const ::mmx::exchange::LocalTrade> reverse() const;
	
	static std::shared_ptr<LocalTrade> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const LocalTrade& _value);
	friend std::istream& operator>>(std::istream& _in, LocalTrade& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void LocalTrade::accept_generic(T& _visitor) const {
	_visitor.template type_begin<LocalTrade>(9);
	_visitor.type_field("id", 0); _visitor.accept(id);
	_visitor.type_field("failed", 1); _visitor.accept(failed);
	_visitor.type_field("height", 2); _visitor.accept(height);
	_visitor.type_field("pair", 3); _visitor.accept(pair);
	_visitor.type_field("type", 4); _visitor.accept(type);
	_visitor.type_field("bid", 5); _visitor.accept(bid);
	_visitor.type_field("ask", 6); _visitor.accept(ask);
	_visitor.type_field("offer_id", 7); _visitor.accept(offer_id);
	_visitor.type_field("message", 8); _visitor.accept(message);
	_visitor.template type_end<LocalTrade>(9);
}


} // namespace mmx
} // namespace exchange


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_exchange_LocalTrade_HXX_
