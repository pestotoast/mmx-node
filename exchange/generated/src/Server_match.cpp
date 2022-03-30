
// AUTO GENERATED by vnxcppcodegen

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/Server_match.hxx>
#include <mmx/exchange/Server_match_return.hxx>
#include <mmx/exchange/trade_order_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace exchange {


const vnx::Hash64 Server_match::VNX_TYPE_HASH(0x7d6b1feaf4d8a485ull);
const vnx::Hash64 Server_match::VNX_CODE_HASH(0x575bd558f14e092ull);

vnx::Hash64 Server_match::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Server_match::get_type_name() const {
	return "mmx.exchange.Server.match";
}

const vnx::TypeCode* Server_match::get_type_code() const {
	return mmx::exchange::vnx_native_type_code_Server_match;
}

std::shared_ptr<Server_match> Server_match::create() {
	return std::make_shared<Server_match>();
}

std::shared_ptr<vnx::Value> Server_match::clone() const {
	return std::make_shared<Server_match>(*this);
}

void Server_match::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Server_match::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Server_match::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::exchange::vnx_native_type_code_Server_match;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, order);
	_visitor.type_end(*_type_code);
}

void Server_match::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.exchange.Server.match\"";
	_out << ", \"order\": "; vnx::write(_out, order);
	_out << "}";
}

void Server_match::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Server_match::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exchange.Server.match";
	_object["order"] = order;
	return _object;
}

void Server_match::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "order") {
			_entry.second.to(order);
		}
	}
}

vnx::Variant Server_match::get_field(const std::string& _name) const {
	if(_name == "order") {
		return vnx::Variant(order);
	}
	return vnx::Variant();
}

void Server_match::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "order") {
		_value.to(order);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Server_match& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Server_match& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Server_match::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Server_match::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exchange.Server.match";
	type_code->type_hash = vnx::Hash64(0x7d6b1feaf4d8a485ull);
	type_code->code_hash = vnx::Hash64(0x575bd558f14e092ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::exchange::Server_match);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Server_match>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::exchange::trade_order_t::static_get_type_code();
	type_code->is_const = true;
	type_code->is_async = true;
	type_code->return_type = ::mmx::exchange::Server_match_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "order";
		field.code = {19, 0};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace exchange


namespace vnx {

void read(TypeInput& in, ::mmx::exchange::Server_match& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.order, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exchange::Server_match& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::exchange::vnx_native_type_code_Server_match;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exchange::Server_match>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.order, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::exchange::Server_match& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exchange::Server_match& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exchange::Server_match& value) {
	value.accept(visitor);
}

} // vnx
