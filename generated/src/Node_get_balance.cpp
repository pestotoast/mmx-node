
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_get_balance.hxx>
#include <mmx/Node_get_balance_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_get_balance::VNX_TYPE_HASH(0x2e00172d0470479ull);
const vnx::Hash64 Node_get_balance::VNX_CODE_HASH(0x3e56e5611a8ddbf9ull);

vnx::Hash64 Node_get_balance::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_get_balance::get_type_name() const {
	return "mmx.Node.get_balance";
}

const vnx::TypeCode* Node_get_balance::get_type_code() const {
	return mmx::vnx_native_type_code_Node_get_balance;
}

std::shared_ptr<Node_get_balance> Node_get_balance::create() {
	return std::make_shared<Node_get_balance>();
}

std::shared_ptr<vnx::Value> Node_get_balance::clone() const {
	return std::make_shared<Node_get_balance>(*this);
}

void Node_get_balance::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_get_balance::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_get_balance::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_get_balance;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, currency);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, min_confirm);
	_visitor.type_end(*_type_code);
}

void Node_get_balance::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.get_balance\"";
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << ", \"currency\": "; vnx::write(_out, currency);
	_out << ", \"min_confirm\": "; vnx::write(_out, min_confirm);
	_out << "}";
}

void Node_get_balance::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_get_balance::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.get_balance";
	_object["address"] = address;
	_object["currency"] = currency;
	_object["min_confirm"] = min_confirm;
	return _object;
}

void Node_get_balance::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "currency") {
			_entry.second.to(currency);
		} else if(_entry.first == "min_confirm") {
			_entry.second.to(min_confirm);
		}
	}
}

vnx::Variant Node_get_balance::get_field(const std::string& _name) const {
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "currency") {
		return vnx::Variant(currency);
	}
	if(_name == "min_confirm") {
		return vnx::Variant(min_confirm);
	}
	return vnx::Variant();
}

void Node_get_balance::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "address") {
		_value.to(address);
	} else if(_name == "currency") {
		_value.to(currency);
	} else if(_name == "min_confirm") {
		_value.to(min_confirm);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_get_balance& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_get_balance& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_get_balance::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_get_balance::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.get_balance";
	type_code->type_hash = vnx::Hash64(0x2e00172d0470479ull);
	type_code->code_hash = vnx::Hash64(0x3e56e5611a8ddbf9ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_get_balance);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_get_balance>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Node_get_balance_return::static_get_type_code();
	type_code->fields.resize(3);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "currency";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "min_confirm";
		field.value = vnx::to_string(1);
		field.code = {3};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_get_balance& value, const TypeCode* type_code, const uint16_t* code) {
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
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.min_confirm, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.currency, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_get_balance& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_get_balance;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_get_balance>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.min_confirm);
	vnx::write(out, value.address, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.currency, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::Node_get_balance& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_get_balance& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_get_balance& value) {
	value.accept(visitor);
}

} // vnx
