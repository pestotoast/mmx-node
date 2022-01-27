
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/utxo_t.hxx>
#include <mmx/tx_out_t.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 utxo_t::VNX_TYPE_HASH(0xb698d425571f5729ull);
const vnx::Hash64 utxo_t::VNX_CODE_HASH(0x4ca5ddab2a2a97d2ull);

vnx::Hash64 utxo_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string utxo_t::get_type_name() const {
	return "mmx.utxo_t";
}

const vnx::TypeCode* utxo_t::get_type_code() const {
	return mmx::vnx_native_type_code_utxo_t;
}

std::shared_ptr<utxo_t> utxo_t::create() {
	return std::make_shared<utxo_t>();
}

std::shared_ptr<utxo_t> utxo_t::clone() const {
	return std::make_shared<utxo_t>(*this);
}

void utxo_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void utxo_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void utxo_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_utxo_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, contract);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, amount);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, height);
	_visitor.type_end(*_type_code);
}

void utxo_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"address\": "; vnx::write(_out, address);
	_out << ", \"contract\": "; vnx::write(_out, contract);
	_out << ", \"amount\": "; vnx::write(_out, amount);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << "}";
}

void utxo_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object utxo_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.utxo_t";
	_object["address"] = address;
	_object["contract"] = contract;
	_object["amount"] = amount;
	_object["height"] = height;
	return _object;
}

void utxo_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "amount") {
			_entry.second.to(amount);
		} else if(_entry.first == "contract") {
			_entry.second.to(contract);
		} else if(_entry.first == "height") {
			_entry.second.to(height);
		}
	}
}

vnx::Variant utxo_t::get_field(const std::string& _name) const {
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "contract") {
		return vnx::Variant(contract);
	}
	if(_name == "amount") {
		return vnx::Variant(amount);
	}
	if(_name == "height") {
		return vnx::Variant(height);
	}
	return vnx::Variant();
}

void utxo_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "address") {
		_value.to(address);
	} else if(_name == "contract") {
		_value.to(contract);
	} else if(_name == "amount") {
		_value.to(amount);
	} else if(_name == "height") {
		_value.to(height);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const utxo_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, utxo_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* utxo_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> utxo_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.utxo_t";
	type_code->type_hash = vnx::Hash64(0xb698d425571f5729ull);
	type_code->code_hash = vnx::Hash64(0x4ca5ddab2a2a97d2ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::utxo_t);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::tx_out_t::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<utxo_t>>(); };
	type_code->fields.resize(4);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "contract";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 8;
		field.name = "amount";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "height";
		field.value = vnx::to_string(-1);
		field.code = {3};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::utxo_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.amount, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.contract, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::utxo_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_utxo_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::utxo_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.amount);
	vnx::write_value(_buf + 8, value.height);
	vnx::write(out, value.address, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.contract, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::utxo_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::utxo_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::utxo_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::utxo_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::utxo_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
