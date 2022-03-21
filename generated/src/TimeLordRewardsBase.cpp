
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/TimeLordRewardsBase.hxx>
#include <vnx/NoSuchMethod.hxx>
#include <mmx/ProofOfTime.hxx>
#include <vnx/Module.h>
#include <vnx/ModuleInterface_vnx_get_config.hxx>
#include <vnx/ModuleInterface_vnx_get_config_return.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info_return.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/ModuleInterface_vnx_restart.hxx>
#include <vnx/ModuleInterface_vnx_restart_return.hxx>
#include <vnx/ModuleInterface_vnx_self_test.hxx>
#include <vnx/ModuleInterface_vnx_self_test_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config.hxx>
#include <vnx/ModuleInterface_vnx_set_config_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_stop.hxx>
#include <vnx/ModuleInterface_vnx_stop_return.hxx>
#include <vnx/TopicPtr.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 TimeLordRewardsBase::VNX_TYPE_HASH(0xa21363e9b58e1cbaull);
const vnx::Hash64 TimeLordRewardsBase::VNX_CODE_HASH(0xa7d54ee0c22692full);

TimeLordRewardsBase::TimeLordRewardsBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".input_vdfs", input_vdfs);
	vnx::read_config(vnx_name + ".wallet_index", wallet_index);
	vnx::read_config(vnx_name + ".reward_divider", reward_divider);
	vnx::read_config(vnx_name + ".reward", reward);
	vnx::read_config(vnx_name + ".wallet_server", wallet_server);
}

vnx::Hash64 TimeLordRewardsBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string TimeLordRewardsBase::get_type_name() const {
	return "mmx.TimeLordRewards";
}

const vnx::TypeCode* TimeLordRewardsBase::get_type_code() const {
	return mmx::vnx_native_type_code_TimeLordRewardsBase;
}

void TimeLordRewardsBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_TimeLordRewardsBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, input_vdfs);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, wallet_index);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, reward_divider);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, reward);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, wallet_server);
	_visitor.type_end(*_type_code);
}

void TimeLordRewardsBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"input_vdfs\": "; vnx::write(_out, input_vdfs);
	_out << ", \"wallet_index\": "; vnx::write(_out, wallet_index);
	_out << ", \"reward_divider\": "; vnx::write(_out, reward_divider);
	_out << ", \"reward\": "; vnx::write(_out, reward);
	_out << ", \"wallet_server\": "; vnx::write(_out, wallet_server);
	_out << "}";
}

void TimeLordRewardsBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object TimeLordRewardsBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.TimeLordRewards";
	_object["input_vdfs"] = input_vdfs;
	_object["wallet_index"] = wallet_index;
	_object["reward_divider"] = reward_divider;
	_object["reward"] = reward;
	_object["wallet_server"] = wallet_server;
	return _object;
}

void TimeLordRewardsBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "input_vdfs") {
			_entry.second.to(input_vdfs);
		} else if(_entry.first == "reward") {
			_entry.second.to(reward);
		} else if(_entry.first == "reward_divider") {
			_entry.second.to(reward_divider);
		} else if(_entry.first == "wallet_index") {
			_entry.second.to(wallet_index);
		} else if(_entry.first == "wallet_server") {
			_entry.second.to(wallet_server);
		}
	}
}

vnx::Variant TimeLordRewardsBase::get_field(const std::string& _name) const {
	if(_name == "input_vdfs") {
		return vnx::Variant(input_vdfs);
	}
	if(_name == "wallet_index") {
		return vnx::Variant(wallet_index);
	}
	if(_name == "reward_divider") {
		return vnx::Variant(reward_divider);
	}
	if(_name == "reward") {
		return vnx::Variant(reward);
	}
	if(_name == "wallet_server") {
		return vnx::Variant(wallet_server);
	}
	return vnx::Variant();
}

void TimeLordRewardsBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "input_vdfs") {
		_value.to(input_vdfs);
	} else if(_name == "wallet_index") {
		_value.to(wallet_index);
	} else if(_name == "reward_divider") {
		_value.to(reward_divider);
	} else if(_name == "reward") {
		_value.to(reward);
	} else if(_name == "wallet_server") {
		_value.to(wallet_server);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const TimeLordRewardsBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, TimeLordRewardsBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* TimeLordRewardsBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> TimeLordRewardsBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.TimeLordRewards";
	type_code->type_hash = vnx::Hash64(0xa21363e9b58e1cbaull);
	type_code->code_hash = vnx::Hash64(0xa7d54ee0c22692full);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::TimeLordRewardsBase);
	type_code->methods.resize(9);
	type_code->methods[0] = ::vnx::ModuleInterface_vnx_get_config::static_get_type_code();
	type_code->methods[1] = ::vnx::ModuleInterface_vnx_get_config_object::static_get_type_code();
	type_code->methods[2] = ::vnx::ModuleInterface_vnx_get_module_info::static_get_type_code();
	type_code->methods[3] = ::vnx::ModuleInterface_vnx_get_type_code::static_get_type_code();
	type_code->methods[4] = ::vnx::ModuleInterface_vnx_restart::static_get_type_code();
	type_code->methods[5] = ::vnx::ModuleInterface_vnx_self_test::static_get_type_code();
	type_code->methods[6] = ::vnx::ModuleInterface_vnx_set_config::static_get_type_code();
	type_code->methods[7] = ::vnx::ModuleInterface_vnx_set_config_object::static_get_type_code();
	type_code->methods[8] = ::vnx::ModuleInterface_vnx_stop::static_get_type_code();
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "input_vdfs";
		field.value = vnx::to_string("node.verified_vdfs");
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "wallet_index";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "reward_divider";
		field.value = vnx::to_string(60);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 8;
		field.name = "reward";
		field.value = vnx::to_string(100000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "wallet_server";
		field.value = vnx::to_string("Wallet");
		field.code = {32};
	}
	type_code->build();
	return type_code;
}

void TimeLordRewardsBase::vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) {
	const auto* _type_code = _value->get_type_code();
	while(_type_code) {
		switch(_type_code->type_hash) {
			case 0xa84a63942b8e5c6aull:
				handle(std::static_pointer_cast<const ::mmx::ProofOfTime>(_value));
				return;
			default:
				_type_code = _type_code->super;
		}
	}
	handle(std::static_pointer_cast<const vnx::Value>(_value));
}

std::shared_ptr<vnx::Value> TimeLordRewardsBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) {
	switch(_method->get_type_hash()) {
		case 0xbbc7f1a01044d294ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_return::create();
			_return_value->_ret_0 = vnx_get_config(_args->name);
			return _return_value;
		}
		case 0x17f58f68bf83abc0ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_object_return::create();
			_return_value->_ret_0 = vnx_get_config_object();
			return _return_value;
		}
		case 0xf6d82bdf66d034a1ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_module_info_return::create();
			_return_value->_ret_0 = vnx_get_module_info();
			return _return_value;
		}
		case 0x305ec4d628960e5dull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_type_code_return::create();
			_return_value->_ret_0 = vnx_get_type_code();
			return _return_value;
		}
		case 0x9e95dc280cecca1bull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_restart>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_restart_return::create();
			vnx_restart();
			return _return_value;
		}
		case 0x6ce3775b41a42697ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_self_test_return::create();
			_return_value->_ret_0 = vnx_self_test();
			return _return_value;
		}
		case 0x362aac91373958b7ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_return::create();
			vnx_set_config(_args->name, _args->value);
			return _return_value;
		}
		case 0xca30f814f17f322full: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_object_return::create();
			vnx_set_config_object(_args->config);
			return _return_value;
		}
		case 0x7ab49ce3d1bfc0d2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_stop>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_stop_return::create();
			vnx_stop();
			return _return_value;
		}
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->dst_mac = vnx_request ? vnx_request->dst_mac : vnx::Hash64();
	_ex->method = _method->get_type_name();
	return _ex;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::TimeLordRewardsBase& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.wallet_index, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.reward_divider, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.reward, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.input_vdfs, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.wallet_server, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::TimeLordRewardsBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_TimeLordRewardsBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::TimeLordRewardsBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.wallet_index);
	vnx::write_value(_buf + 4, value.reward_divider);
	vnx::write_value(_buf + 8, value.reward);
	vnx::write(out, value.input_vdfs, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.wallet_server, type_code, type_code->fields[4].code.data());
}

void read(std::istream& in, ::mmx::TimeLordRewardsBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::TimeLordRewardsBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::TimeLordRewardsBase& value) {
	value.accept(visitor);
}

} // vnx
