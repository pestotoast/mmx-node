
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_start_sync.hxx>
#include <mmx/Node_start_sync_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_start_sync::VNX_TYPE_HASH(0x6c5be8aeb25ef3c8ull);
const vnx::Hash64 Node_start_sync::VNX_CODE_HASH(0x4dd801a35570131cull);

vnx::Hash64 Node_start_sync::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_start_sync::get_type_name() const {
	return "mmx.Node.start_sync";
}

const vnx::TypeCode* Node_start_sync::get_type_code() const {
	return mmx::vnx_native_type_code_Node_start_sync;
}

std::shared_ptr<Node_start_sync> Node_start_sync::create() {
	return std::make_shared<Node_start_sync>();
}

std::shared_ptr<vnx::Value> Node_start_sync::clone() const {
	return std::make_shared<Node_start_sync>(*this);
}

void Node_start_sync::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_start_sync::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_start_sync::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_start_sync;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, force);
	_visitor.type_end(*_type_code);
}

void Node_start_sync::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.start_sync\"";
	_out << ", \"force\": "; vnx::write(_out, force);
	_out << "}";
}

void Node_start_sync::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_start_sync::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.start_sync";
	_object["force"] = force;
	return _object;
}

void Node_start_sync::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "force") {
			_entry.second.to(force);
		}
	}
}

vnx::Variant Node_start_sync::get_field(const std::string& _name) const {
	if(_name == "force") {
		return vnx::Variant(force);
	}
	return vnx::Variant();
}

void Node_start_sync::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "force") {
		_value.to(force);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_start_sync& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_start_sync& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_start_sync::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_start_sync::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.start_sync";
	type_code->type_hash = vnx::Hash64(0x6c5be8aeb25ef3c8ull);
	type_code->code_hash = vnx::Hash64(0x4dd801a35570131cull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_start_sync);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_start_sync>(); };
	type_code->return_type = ::mmx::Node_start_sync_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.data_size = 1;
		field.name = "force";
		field.code = {31};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_start_sync& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.force, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_start_sync& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_start_sync;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_start_sync>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(1);
	vnx::write_value(_buf + 0, value.force);
}

void read(std::istream& in, ::mmx::Node_start_sync& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_start_sync& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_start_sync& value) {
	value.accept(visitor);
}

} // vnx
