
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/Token_validate.hxx>
#include <mmx/Context.hxx>
#include <mmx/Operation.hxx>
#include <mmx/contract/Token_validate_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 Token_validate::VNX_TYPE_HASH(0xc3476057943b66ffull);
const vnx::Hash64 Token_validate::VNX_CODE_HASH(0xc69d5938d17ac4d5ull);

vnx::Hash64 Token_validate::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Token_validate::get_type_name() const {
	return "mmx.contract.Token.validate";
}

const vnx::TypeCode* Token_validate::get_type_code() const {
	return mmx::contract::vnx_native_type_code_Token_validate;
}

std::shared_ptr<Token_validate> Token_validate::create() {
	return std::make_shared<Token_validate>();
}

std::shared_ptr<vnx::Value> Token_validate::clone() const {
	return std::make_shared<Token_validate>(*this);
}

void Token_validate::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Token_validate::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Token_validate::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_Token_validate;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, operation);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, context);
	_visitor.type_end(*_type_code);
}

void Token_validate::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.Token.validate\"";
	_out << ", \"operation\": "; vnx::write(_out, operation);
	_out << ", \"context\": "; vnx::write(_out, context);
	_out << "}";
}

void Token_validate::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Token_validate::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.Token.validate";
	_object["operation"] = operation;
	_object["context"] = context;
	return _object;
}

void Token_validate::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "context") {
			_entry.second.to(context);
		} else if(_entry.first == "operation") {
			_entry.second.to(operation);
		}
	}
}

vnx::Variant Token_validate::get_field(const std::string& _name) const {
	if(_name == "operation") {
		return vnx::Variant(operation);
	}
	if(_name == "context") {
		return vnx::Variant(context);
	}
	return vnx::Variant();
}

void Token_validate::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "operation") {
		_value.to(operation);
	} else if(_name == "context") {
		_value.to(context);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Token_validate& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Token_validate& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Token_validate::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Token_validate::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.Token.validate";
	type_code->type_hash = vnx::Hash64(0xc3476057943b66ffull);
	type_code->code_hash = vnx::Hash64(0xc69d5938d17ac4d5ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::contract::Token_validate);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Token_validate>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::contract::Token_validate_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "operation";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "context";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::Token_validate& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.operation, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.context, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::Token_validate& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_Token_validate;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::Token_validate>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.operation, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.context, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::contract::Token_validate& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::Token_validate& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::Token_validate& value) {
	value.accept(visitor);
}

} // vnx
