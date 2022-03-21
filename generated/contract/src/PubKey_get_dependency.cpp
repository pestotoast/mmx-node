
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/PubKey_get_dependency.hxx>
#include <mmx/contract/PubKey_get_dependency_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 PubKey_get_dependency::VNX_TYPE_HASH(0x5eddf8d7882958f5ull);
const vnx::Hash64 PubKey_get_dependency::VNX_CODE_HASH(0x1ce3a4e9ae04254aull);

vnx::Hash64 PubKey_get_dependency::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string PubKey_get_dependency::get_type_name() const {
	return "mmx.contract.PubKey.get_dependency";
}

const vnx::TypeCode* PubKey_get_dependency::get_type_code() const {
	return mmx::contract::vnx_native_type_code_PubKey_get_dependency;
}

std::shared_ptr<PubKey_get_dependency> PubKey_get_dependency::create() {
	return std::make_shared<PubKey_get_dependency>();
}

std::shared_ptr<vnx::Value> PubKey_get_dependency::clone() const {
	return std::make_shared<PubKey_get_dependency>(*this);
}

void PubKey_get_dependency::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void PubKey_get_dependency::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void PubKey_get_dependency::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_PubKey_get_dependency;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void PubKey_get_dependency::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.PubKey.get_dependency\"";
	_out << "}";
}

void PubKey_get_dependency::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object PubKey_get_dependency::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.PubKey.get_dependency";
	return _object;
}

void PubKey_get_dependency::from_object(const vnx::Object& _object) {
}

vnx::Variant PubKey_get_dependency::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void PubKey_get_dependency::set_field(const std::string& _name, const vnx::Variant& _value) {
}

/// \private
std::ostream& operator<<(std::ostream& _out, const PubKey_get_dependency& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, PubKey_get_dependency& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* PubKey_get_dependency::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> PubKey_get_dependency::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.PubKey.get_dependency";
	type_code->type_hash = vnx::Hash64(0x5eddf8d7882958f5ull);
	type_code->code_hash = vnx::Hash64(0x1ce3a4e9ae04254aull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::contract::PubKey_get_dependency);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<PubKey_get_dependency>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::contract::PubKey_get_dependency_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::PubKey_get_dependency& value, const TypeCode* type_code, const uint16_t* code) {
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
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::PubKey_get_dependency& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_PubKey_get_dependency;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::PubKey_get_dependency>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::mmx::contract::PubKey_get_dependency& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::PubKey_get_dependency& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::PubKey_get_dependency& value) {
	value.accept(visitor);
}

} // vnx
