
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exchange_OfferBundle_HXX_
#define INCLUDE_mmx_exchange_OfferBundle_HXX_

#include <mmx/exchange/package.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/exchange/limit_order_t.hxx>
#include <mmx/exchange/open_order_t.hxx>
#include <mmx/exchange/trade_pair_t.hxx>
#include <mmx/txio_key_t.hxx>
#include <vnx/Value.h>


namespace mmx {
namespace exchange {

class VNX_EXPORT OfferBundle : public ::vnx::Value {
public:
	
	uint64_t id = 0;
	uint32_t wallet = 0;
	::mmx::exchange::trade_pair_t pair;
	uint64_t bid = 0;
	uint64_t ask = 0;
	uint64_t bid_sold = 0;
	std::vector<::mmx::exchange::limit_order_t> limit_orders;
	std::vector<std::pair<::mmx::txio_key_t, ::mmx::exchange::open_order_t>> orders;
	std::vector<std::shared_ptr<const ::mmx::Transaction>> generator;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xa1f52e2a78efa212ull;
	
	OfferBundle() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<OfferBundle> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const OfferBundle& _value);
	friend std::istream& operator>>(std::istream& _in, OfferBundle& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void OfferBundle::accept_generic(T& _visitor) const {
	_visitor.template type_begin<OfferBundle>(9);
	_visitor.type_field("id", 0); _visitor.accept(id);
	_visitor.type_field("wallet", 1); _visitor.accept(wallet);
	_visitor.type_field("pair", 2); _visitor.accept(pair);
	_visitor.type_field("bid", 3); _visitor.accept(bid);
	_visitor.type_field("ask", 4); _visitor.accept(ask);
	_visitor.type_field("bid_sold", 5); _visitor.accept(bid_sold);
	_visitor.type_field("limit_orders", 6); _visitor.accept(limit_orders);
	_visitor.type_field("orders", 7); _visitor.accept(orders);
	_visitor.type_field("generator", 8); _visitor.accept(generator);
	_visitor.template type_end<OfferBundle>(9);
}


} // namespace mmx
} // namespace exchange


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_exchange_OfferBundle_HXX_
