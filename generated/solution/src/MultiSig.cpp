
// AUTO GENERATED by vnxcppcodegen

#include <mmx/solution/package.hxx>
#include <mmx/solution/MultiSig.hxx>
#include <mmx/Solution.hxx>
#include <mmx/solution/PubKey.hxx>

#include <vnx/vnx.h>


namespace mmx {
namespace solution {


const vnx::Hash64 MultiSig::VNX_TYPE_HASH(0x64ffa2f8fc8dffd1ull);
const vnx::Hash64 MultiSig::VNX_CODE_HASH(0x82c11432b8f8fb13ull);

vnx::Hash64 MultiSig::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string MultiSig::get_type_name() const {
	return "mmx.solution.MultiSig";
}

const vnx::TypeCode* MultiSig::get_type_code() const {
	return mmx::solution::vnx_native_type_code_MultiSig;
}

std::shared_ptr<MultiSig> MultiSig::create() {
	return std::make_shared<MultiSig>();
}

std::shared_ptr<vnx::Value> MultiSig::clone() const {
	return std::make_shared<MultiSig>(*this);
}

void MultiSig::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void MultiSig::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void MultiSig::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::solution::vnx_native_type_code_MultiSig;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, solutions);
	_visitor.type_end(*_type_code);
}

void MultiSig::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.solution.MultiSig\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"solutions\": "; vnx::write(_out, solutions);
	_out << "}";
}

void MultiSig::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object MultiSig::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.solution.MultiSig";
	_object["version"] = version;
	_object["solutions"] = solutions;
	return _object;
}

void MultiSig::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "solutions") {
			_entry.second.to(solutions);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant MultiSig::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "solutions") {
		return vnx::Variant(solutions);
	}
	return vnx::Variant();
}

void MultiSig::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "solutions") {
		_value.to(solutions);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const MultiSig& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, MultiSig& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* MultiSig::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> MultiSig::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.solution.MultiSig";
	type_code->type_hash = vnx::Hash64(0x64ffa2f8fc8dffd1ull);
	type_code->code_hash = vnx::Hash64(0x82c11432b8f8fb13ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::solution::MultiSig);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Solution::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<MultiSig>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::solution::PubKey::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "solutions";
		field.code = {12, 19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace solution


namespace vnx {

void read(TypeInput& in, ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.solutions, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::solution::vnx_native_type_code_MultiSig;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::solution::MultiSig>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.version);
	vnx::write(out, value.solutions, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::solution::MultiSig& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::solution::MultiSig& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::solution::MultiSig& value) {
	value.accept(visitor);
}

} // vnx