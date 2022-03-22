
// AUTO GENERATED by vnxcppcodegen

#include <mmx/operation/package.hxx>
#include <mmx/operation/Mutate_calc_cost_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace operation {


const vnx::Hash64 Mutate_calc_cost_return::VNX_TYPE_HASH(0xe9787d7e0426c7feull);
const vnx::Hash64 Mutate_calc_cost_return::VNX_CODE_HASH(0x5b7eab027e08b0acull);

vnx::Hash64 Mutate_calc_cost_return::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Mutate_calc_cost_return::get_type_name() const {
	return "mmx.operation.Mutate.calc_cost.return";
}

const vnx::TypeCode* Mutate_calc_cost_return::get_type_code() const {
	return mmx::operation::vnx_native_type_code_Mutate_calc_cost_return;
}

std::shared_ptr<Mutate_calc_cost_return> Mutate_calc_cost_return::create() {
	return std::make_shared<Mutate_calc_cost_return>();
}

std::shared_ptr<vnx::Value> Mutate_calc_cost_return::clone() const {
	return std::make_shared<Mutate_calc_cost_return>(*this);
}

void Mutate_calc_cost_return::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Mutate_calc_cost_return::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Mutate_calc_cost_return::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::operation::vnx_native_type_code_Mutate_calc_cost_return;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, _ret_0);
	_visitor.type_end(*_type_code);
}

void Mutate_calc_cost_return::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.operation.Mutate.calc_cost.return\"";
	_out << ", \"_ret_0\": "; vnx::write(_out, _ret_0);
	_out << "}";
}

void Mutate_calc_cost_return::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Mutate_calc_cost_return::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.operation.Mutate.calc_cost.return";
	_object["_ret_0"] = _ret_0;
	return _object;
}

void Mutate_calc_cost_return::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "_ret_0") {
			_entry.second.to(_ret_0);
		}
	}
}

vnx::Variant Mutate_calc_cost_return::get_field(const std::string& _name) const {
	if(_name == "_ret_0") {
		return vnx::Variant(_ret_0);
	}
	return vnx::Variant();
}

void Mutate_calc_cost_return::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "_ret_0") {
		_value.to(_ret_0);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Mutate_calc_cost_return& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Mutate_calc_cost_return& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Mutate_calc_cost_return::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Mutate_calc_cost_return::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.operation.Mutate.calc_cost.return";
	type_code->type_hash = vnx::Hash64(0xe9787d7e0426c7feull);
	type_code->code_hash = vnx::Hash64(0x5b7eab027e08b0acull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_return = true;
	type_code->native_size = sizeof(::mmx::operation::Mutate_calc_cost_return);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Mutate_calc_cost_return>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "_ret_0";
		field.code = {4};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace operation


namespace vnx {

void read(TypeInput& in, ::mmx::operation::Mutate_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value._ret_0, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::operation::Mutate_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::operation::vnx_native_type_code_Mutate_calc_cost_return;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::operation::Mutate_calc_cost_return>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value._ret_0);
}

void read(std::istream& in, ::mmx::operation::Mutate_calc_cost_return& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::operation::Mutate_calc_cost_return& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::operation::Mutate_calc_cost_return& value) {
	value.accept(visitor);
}

} // vnx
