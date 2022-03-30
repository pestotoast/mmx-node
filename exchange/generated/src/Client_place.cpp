
// AUTO GENERATED by vnxcppcodegen

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/Client_place.hxx>
#include <mmx/exchange/Client_place_return.hxx>
#include <mmx/exchange/OfferBundle.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace exchange {


const vnx::Hash64 Client_place::VNX_TYPE_HASH(0xb32aebcb67327b40ull);
const vnx::Hash64 Client_place::VNX_CODE_HASH(0xe80c674a13765ca9ull);

vnx::Hash64 Client_place::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Client_place::get_type_name() const {
	return "mmx.exchange.Client.place";
}

const vnx::TypeCode* Client_place::get_type_code() const {
	return mmx::exchange::vnx_native_type_code_Client_place;
}

std::shared_ptr<Client_place> Client_place::create() {
	return std::make_shared<Client_place>();
}

std::shared_ptr<vnx::Value> Client_place::clone() const {
	return std::make_shared<Client_place>(*this);
}

void Client_place::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Client_place::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Client_place::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::exchange::vnx_native_type_code_Client_place;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, offer);
	_visitor.type_end(*_type_code);
}

void Client_place::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.exchange.Client.place\"";
	_out << ", \"offer\": "; vnx::write(_out, offer);
	_out << "}";
}

void Client_place::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Client_place::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exchange.Client.place";
	_object["offer"] = offer;
	return _object;
}

void Client_place::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "offer") {
			_entry.second.to(offer);
		}
	}
}

vnx::Variant Client_place::get_field(const std::string& _name) const {
	if(_name == "offer") {
		return vnx::Variant(offer);
	}
	return vnx::Variant();
}

void Client_place::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "offer") {
		_value.to(offer);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Client_place& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Client_place& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Client_place::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Client_place::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exchange.Client.place";
	type_code->type_hash = vnx::Hash64(0xb32aebcb67327b40ull);
	type_code->code_hash = vnx::Hash64(0xe80c674a13765ca9ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::exchange::Client_place);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Client_place>(); };
	type_code->return_type = ::mmx::exchange::Client_place_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "offer";
		field.code = {16};
	}
	type_code->permission = "mmx.permission_e.SPENDING";
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace exchange


namespace vnx {

void read(TypeInput& in, ::mmx::exchange::Client_place& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.offer, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exchange::Client_place& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::exchange::vnx_native_type_code_Client_place;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exchange::Client_place>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.offer, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::exchange::Client_place& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exchange::Client_place& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exchange::Client_place& value) {
	value.accept(visitor);
}

} // vnx