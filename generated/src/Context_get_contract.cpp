
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Context_get_contract.hxx>
#include <mmx/Context_get_contract_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Context_get_contract::VNX_TYPE_HASH(0x1f4d1db80d454fcbull);
const vnx::Hash64 Context_get_contract::VNX_CODE_HASH(0x1d346bf3b38272dbull);

vnx::Hash64 Context_get_contract::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Context_get_contract::get_type_name() const {
	return "mmx.Context.get_contract";
}

const vnx::TypeCode* Context_get_contract::get_type_code() const {
	return mmx::vnx_native_type_code_Context_get_contract;
}

std::shared_ptr<Context_get_contract> Context_get_contract::create() {
	return std::make_shared<Context_get_contract>();
}

std::shared_ptr<vnx::Value> Context_get_contract::clone() const {
	return std::make_shared<Context_get_contract>(*this);
}

void Context_get_contract::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Context_get_contract::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Context_get_contract::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Context_get_contract;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, address);
	_visitor.type_end(*_type_code);
}

void Context_get_contract::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Context.get_contract\"";
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << "}";
}

void Context_get_contract::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Context_get_contract::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Context.get_contract";
	_object["address"] = address;
	return _object;
}

void Context_get_contract::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		}
	}
}

vnx::Variant Context_get_contract::get_field(const std::string& _name) const {
	if(_name == "address") {
		return vnx::Variant(address);
	}
	return vnx::Variant();
}

void Context_get_contract::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "address") {
		_value.to(address);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Context_get_contract& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Context_get_contract& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Context_get_contract::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Context_get_contract::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Context.get_contract";
	type_code->type_hash = vnx::Hash64(0x1f4d1db80d454fcbull);
	type_code->code_hash = vnx::Hash64(0x1d346bf3b38272dbull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Context_get_contract);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Context_get_contract>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Context_get_contract_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Context_get_contract& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.address, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Context_get_contract& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Context_get_contract;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Context_get_contract>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.address, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::Context_get_contract& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Context_get_contract& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Context_get_contract& value) {
	value.accept(visitor);
}

} // vnx