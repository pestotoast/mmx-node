
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_create_wallet.hxx>
#include <mmx/Wallet_create_wallet_return.hxx>
#include <mmx/account_t.hxx>
#include <mmx/hash_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_create_wallet::VNX_TYPE_HASH(0xdcc08a3a1b171a19ull);
const vnx::Hash64 Wallet_create_wallet::VNX_CODE_HASH(0x827e2d7912501f24ull);

vnx::Hash64 Wallet_create_wallet::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_create_wallet::get_type_name() const {
	return "mmx.Wallet.create_wallet";
}

const vnx::TypeCode* Wallet_create_wallet::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_create_wallet;
}

std::shared_ptr<Wallet_create_wallet> Wallet_create_wallet::create() {
	return std::make_shared<Wallet_create_wallet>();
}

std::shared_ptr<vnx::Value> Wallet_create_wallet::clone() const {
	return std::make_shared<Wallet_create_wallet>(*this);
}

void Wallet_create_wallet::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_create_wallet::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_create_wallet::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_create_wallet;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, config);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, seed);
	_visitor.type_end(*_type_code);
}

void Wallet_create_wallet::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.create_wallet\"";
	_out << ", \"config\": "; vnx::write(_out, config);
	_out << ", \"seed\": "; vnx::write(_out, seed);
	_out << "}";
}

void Wallet_create_wallet::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_create_wallet::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.create_wallet";
	_object["config"] = config;
	_object["seed"] = seed;
	return _object;
}

void Wallet_create_wallet::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "config") {
			_entry.second.to(config);
		} else if(_entry.first == "seed") {
			_entry.second.to(seed);
		}
	}
}

vnx::Variant Wallet_create_wallet::get_field(const std::string& _name) const {
	if(_name == "config") {
		return vnx::Variant(config);
	}
	if(_name == "seed") {
		return vnx::Variant(seed);
	}
	return vnx::Variant();
}

void Wallet_create_wallet::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "config") {
		_value.to(config);
	} else if(_name == "seed") {
		_value.to(seed);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_create_wallet& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_create_wallet& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_create_wallet::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_create_wallet::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.create_wallet";
	type_code->type_hash = vnx::Hash64(0xdcc08a3a1b171a19ull);
	type_code->code_hash = vnx::Hash64(0x827e2d7912501f24ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Wallet_create_wallet);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_create_wallet>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::account_t::static_get_type_code();
	type_code->return_type = ::mmx::Wallet_create_wallet_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "config";
		field.code = {19, 0};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "seed";
		field.code = {33, 11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_create_wallet& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.config, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.seed, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_create_wallet& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_create_wallet;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_create_wallet>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.config, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.seed, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::Wallet_create_wallet& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_create_wallet& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_create_wallet& value) {
	value.accept(visitor);
}

} // vnx