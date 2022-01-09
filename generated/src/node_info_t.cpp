
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/node_info_t.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/node_type_e.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 node_info_t::VNX_TYPE_HASH(0xda45b5e3a527588eull);
const vnx::Hash64 node_info_t::VNX_CODE_HASH(0xa5e1afc5dbd3ecf5ull);

vnx::Hash64 node_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string node_info_t::get_type_name() const {
	return "mmx.node_info_t";
}

const vnx::TypeCode* node_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_node_info_t;
}

std::shared_ptr<node_info_t> node_info_t::create() {
	return std::make_shared<node_info_t>();
}

std::shared_ptr<node_info_t> node_info_t::clone() const {
	return std::make_shared<node_info_t>(*this);
}

void node_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void node_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void node_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_node_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, id);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, type);
	_visitor.type_end(*_type_code);
}

void node_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"id\": "; vnx::write(_out, id);
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"type\": "; vnx::write(_out, type);
	_out << "}";
}

void node_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object node_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.node_info_t";
	_object["id"] = id;
	_object["version"] = version;
	_object["type"] = type;
	return _object;
}

void node_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "id") {
			_entry.second.to(id);
		} else if(_entry.first == "type") {
			_entry.second.to(type);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant node_info_t::get_field(const std::string& _name) const {
	if(_name == "id") {
		return vnx::Variant(id);
	}
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "type") {
		return vnx::Variant(type);
	}
	return vnx::Variant();
}

void node_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "id") {
		_value.to(id);
	} else if(_name == "version") {
		_value.to(version);
	} else if(_name == "type") {
		_value.to(type);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const node_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, node_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* node_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> node_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.node_info_t";
	type_code->type_hash = vnx::Hash64(0xda45b5e3a527588eull);
	type_code->code_hash = vnx::Hash64(0xa5e1afc5dbd3ecf5ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::node_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<node_info_t>>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::node_type_e::static_get_type_code();
	type_code->fields.resize(3);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "id";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "type";
		field.code = {19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::node_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.id, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.type, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::node_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_node_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::node_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.version);
	vnx::write(out, value.id, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.type, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::node_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::node_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::node_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::node_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::node_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
