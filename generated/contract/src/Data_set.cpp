
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/Data_set.hxx>
#include <mmx/contract/Data_set_return.hxx>
#include <vnx/Value.h>
#include <vnx/Variant.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 Data_set::VNX_TYPE_HASH(0x191ecbe87a4ee70aull);
const vnx::Hash64 Data_set::VNX_CODE_HASH(0xe09543ac6a5227d0ull);

vnx::Hash64 Data_set::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Data_set::get_type_name() const {
	return "mmx.contract.Data.set";
}

const vnx::TypeCode* Data_set::get_type_code() const {
	return mmx::contract::vnx_native_type_code_Data_set;
}

std::shared_ptr<Data_set> Data_set::create() {
	return std::make_shared<Data_set>();
}

std::shared_ptr<vnx::Value> Data_set::clone() const {
	return std::make_shared<Data_set>(*this);
}

void Data_set::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Data_set::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Data_set::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_Data_set;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, value);
	_visitor.type_end(*_type_code);
}

void Data_set::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.Data.set\"";
	_out << ", \"value\": "; vnx::write(_out, value);
	_out << "}";
}

void Data_set::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Data_set::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.Data.set";
	_object["value"] = value;
	return _object;
}

void Data_set::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "value") {
			_entry.second.to(value);
		}
	}
}

vnx::Variant Data_set::get_field(const std::string& _name) const {
	if(_name == "value") {
		return vnx::Variant(value);
	}
	return vnx::Variant();
}

void Data_set::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "value") {
		_value.to(value);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Data_set& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Data_set& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Data_set::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Data_set::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.Data.set";
	type_code->type_hash = vnx::Hash64(0x191ecbe87a4ee70aull);
	type_code->code_hash = vnx::Hash64(0xe09543ac6a5227d0ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::contract::Data_set);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Data_set>(); };
	type_code->return_type = ::mmx::contract::Data_set_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "value";
		field.code = {17};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::Data_set& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.value, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::Data_set& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_Data_set;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::Data_set>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.value, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::contract::Data_set& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::Data_set& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::Data_set& value) {
	value.accept(visitor);
}

} // vnx
