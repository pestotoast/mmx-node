
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/WalletClient.hxx>
#include <mmx/Contract.hxx>
#include <mmx/FarmerKeys.hxx>
#include <mmx/Solution.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/Wallet_add_account.hxx>
#include <mmx/Wallet_add_account_return.hxx>
#include <mmx/Wallet_deploy.hxx>
#include <mmx/Wallet_deploy_return.hxx>
#include <mmx/Wallet_gather_utxos_for.hxx>
#include <mmx/Wallet_gather_utxos_for_return.hxx>
#include <mmx/Wallet_get_accounts.hxx>
#include <mmx/Wallet_get_accounts_return.hxx>
#include <mmx/Wallet_get_address.hxx>
#include <mmx/Wallet_get_address_return.hxx>
#include <mmx/Wallet_get_all_addresses.hxx>
#include <mmx/Wallet_get_all_addresses_return.hxx>
#include <mmx/Wallet_get_all_farmer_keys.hxx>
#include <mmx/Wallet_get_all_farmer_keys_return.hxx>
#include <mmx/Wallet_get_balance.hxx>
#include <mmx/Wallet_get_balance_return.hxx>
#include <mmx/Wallet_get_balances.hxx>
#include <mmx/Wallet_get_balances_return.hxx>
#include <mmx/Wallet_get_contracts.hxx>
#include <mmx/Wallet_get_contracts_return.hxx>
#include <mmx/Wallet_get_farmer_keys.hxx>
#include <mmx/Wallet_get_farmer_keys_return.hxx>
#include <mmx/Wallet_get_history.hxx>
#include <mmx/Wallet_get_history_return.hxx>
#include <mmx/Wallet_get_master_seed.hxx>
#include <mmx/Wallet_get_master_seed_return.hxx>
#include <mmx/Wallet_get_reserved_balances.hxx>
#include <mmx/Wallet_get_reserved_balances_return.hxx>
#include <mmx/Wallet_get_stxo_list.hxx>
#include <mmx/Wallet_get_stxo_list_return.hxx>
#include <mmx/Wallet_get_stxo_list_for.hxx>
#include <mmx/Wallet_get_stxo_list_for_return.hxx>
#include <mmx/Wallet_get_utxo_list.hxx>
#include <mmx/Wallet_get_utxo_list_return.hxx>
#include <mmx/Wallet_get_utxo_list_for.hxx>
#include <mmx/Wallet_get_utxo_list_for_return.hxx>
#include <mmx/Wallet_mark_spent.hxx>
#include <mmx/Wallet_mark_spent_return.hxx>
#include <mmx/Wallet_mint.hxx>
#include <mmx/Wallet_mint_return.hxx>
#include <mmx/Wallet_release.hxx>
#include <mmx/Wallet_release_return.hxx>
#include <mmx/Wallet_release_all.hxx>
#include <mmx/Wallet_release_all_return.hxx>
#include <mmx/Wallet_reserve.hxx>
#include <mmx/Wallet_reserve_return.hxx>
#include <mmx/Wallet_send.hxx>
#include <mmx/Wallet_send_return.hxx>
#include <mmx/Wallet_send_from.hxx>
#include <mmx/Wallet_send_from_return.hxx>
#include <mmx/Wallet_sign_msg.hxx>
#include <mmx/Wallet_sign_msg_return.hxx>
#include <mmx/Wallet_sign_off.hxx>
#include <mmx/Wallet_sign_off_return.hxx>
#include <mmx/account_t.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/spend_options_t.hxx>
#include <mmx/stxo_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/txio_key_t.hxx>
#include <mmx/utxo_entry_t.hxx>
#include <mmx/utxo_t.hxx>
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
#include <vnx/addons/HttpComponent_http_request.hxx>
#include <vnx/addons/HttpComponent_http_request_return.hxx>
#include <vnx/addons/HttpComponent_http_request_chunk.hxx>
#include <vnx/addons/HttpComponent_http_request_chunk_return.hxx>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>

#include <vnx/Generic.hxx>
#include <vnx/vnx.h>


namespace mmx {

WalletClient::WalletClient(const std::string& service_name)
	:	Client::Client(vnx::Hash64(service_name))
{
}

WalletClient::WalletClient(vnx::Hash64 service_addr)
	:	Client::Client(service_addr)
{
}

::vnx::Object WalletClient::vnx_get_config_object() {
	auto _method = ::vnx::ModuleInterface_vnx_get_config_object::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Object>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::vnx::Variant WalletClient::vnx_get_config(const std::string& name) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config::create();
	_method->name = name;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Variant>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

void WalletClient::vnx_set_config_object(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, false);
}

void WalletClient::vnx_set_config_object_async(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, true);
}

void WalletClient::vnx_set_config(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, false);
}

void WalletClient::vnx_set_config_async(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, true);
}

::vnx::TypeCode WalletClient::vnx_get_type_code() {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::TypeCode>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::ModuleInfo> WalletClient::vnx_get_module_info() {
	auto _method = ::vnx::ModuleInterface_vnx_get_module_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::ModuleInfo>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

void WalletClient::vnx_restart() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, false);
}

void WalletClient::vnx_restart_async() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, true);
}

void WalletClient::vnx_stop() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, false);
}

void WalletClient::vnx_stop_async() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, true);
}

vnx::bool_t WalletClient::vnx_self_test() {
	auto _method = ::vnx::ModuleInterface_vnx_self_test::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<vnx::bool_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::mmx::hash_t WalletClient::send(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) {
	auto _method = ::mmx::Wallet_send::create();
	_method->index = index;
	_method->amount = amount;
	_method->dst_addr = dst_addr;
	_method->currency = currency;
	_method->options = options;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_send_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::mmx::hash_t WalletClient::send_from(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& src_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) {
	auto _method = ::mmx::Wallet_send_from::create();
	_method->index = index;
	_method->amount = amount;
	_method->dst_addr = dst_addr;
	_method->src_addr = src_addr;
	_method->currency = currency;
	_method->options = options;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_send_from_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::mmx::hash_t WalletClient::mint(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) {
	auto _method = ::mmx::Wallet_mint::create();
	_method->index = index;
	_method->amount = amount;
	_method->dst_addr = dst_addr;
	_method->currency = currency;
	_method->options = options;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_mint_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::mmx::hash_t WalletClient::deploy(const uint32_t& index, std::shared_ptr<const ::mmx::Contract> contract, const ::mmx::spend_options_t& options) {
	auto _method = ::mmx::Wallet_deploy::create();
	_method->index = index;
	_method->contract = contract;
	_method->options = options;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_deploy_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::Transaction> WalletClient::sign_off(const uint32_t& index, std::shared_ptr<const ::mmx::Transaction> tx, const vnx::bool_t& cover_fee, const std::vector<std::pair<::mmx::txio_key_t, ::mmx::utxo_t>>& utxo_list) {
	auto _method = ::mmx::Wallet_sign_off::create();
	_method->index = index;
	_method->tx = tx;
	_method->cover_fee = cover_fee;
	_method->utxo_list = utxo_list;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_sign_off_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::Transaction>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::Solution> WalletClient::sign_msg(const uint32_t& index, const ::mmx::addr_t& address, const ::mmx::hash_t& msg) {
	auto _method = ::mmx::Wallet_sign_msg::create();
	_method->index = index;
	_method->address = address;
	_method->msg = msg;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_sign_msg_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::Solution>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

void WalletClient::mark_spent(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_mark_spent::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, false);
}

void WalletClient::mark_spent_async(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_mark_spent::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, true);
}

void WalletClient::reserve(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_reserve::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, false);
}

void WalletClient::reserve_async(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_reserve::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, true);
}

void WalletClient::release(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_release::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, false);
}

void WalletClient::release_async(const uint32_t& index, const std::vector<::mmx::txio_key_t>& keys) {
	auto _method = ::mmx::Wallet_release::create();
	_method->index = index;
	_method->keys = keys;
	vnx_request(_method, true);
}

void WalletClient::release_all() {
	auto _method = ::mmx::Wallet_release_all::create();
	vnx_request(_method, false);
}

void WalletClient::release_all_async() {
	auto _method = ::mmx::Wallet_release_all::create();
	vnx_request(_method, true);
}

std::vector<::mmx::utxo_entry_t> WalletClient::get_utxo_list(const uint32_t& index, const uint32_t& min_confirm) {
	auto _method = ::mmx::Wallet_get_utxo_list::create();
	_method->index = index;
	_method->min_confirm = min_confirm;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_utxo_list_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::utxo_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::utxo_entry_t> WalletClient::get_utxo_list_for(const uint32_t& index, const ::mmx::addr_t& currency, const uint32_t& min_confirm) {
	auto _method = ::mmx::Wallet_get_utxo_list_for::create();
	_method->index = index;
	_method->currency = currency;
	_method->min_confirm = min_confirm;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_utxo_list_for_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::utxo_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::stxo_entry_t> WalletClient::get_stxo_list(const uint32_t& index) {
	auto _method = ::mmx::Wallet_get_stxo_list::create();
	_method->index = index;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_stxo_list_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::stxo_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::stxo_entry_t> WalletClient::get_stxo_list_for(const uint32_t& index, const ::mmx::addr_t& currency) {
	auto _method = ::mmx::Wallet_get_stxo_list_for::create();
	_method->index = index;
	_method->currency = currency;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_stxo_list_for_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::stxo_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::utxo_entry_t> WalletClient::gather_utxos_for(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& currency, const ::mmx::spend_options_t& options) {
	auto _method = ::mmx::Wallet_gather_utxos_for::create();
	_method->index = index;
	_method->amount = amount;
	_method->currency = currency;
	_method->options = options;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_gather_utxos_for_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::utxo_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::tx_entry_t> WalletClient::get_history(const uint32_t& index, const int32_t& since) {
	auto _method = ::mmx::Wallet_get_history::create();
	_method->index = index;
	_method->since = since;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_history_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::tx_entry_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

uint64_t WalletClient::get_balance(const uint32_t& index, const ::mmx::addr_t& currency, const uint32_t& min_confirm) {
	auto _method = ::mmx::Wallet_get_balance::create();
	_method->index = index;
	_method->currency = currency;
	_method->min_confirm = min_confirm;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_balance_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<uint64_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::map<::mmx::addr_t, uint64_t> WalletClient::get_balances(const uint32_t& index, const uint32_t& min_confirm) {
	auto _method = ::mmx::Wallet_get_balances::create();
	_method->index = index;
	_method->min_confirm = min_confirm;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_balances_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::map<::mmx::addr_t, uint64_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::map<::mmx::addr_t, uint64_t> WalletClient::get_reserved_balances(const uint32_t& index, const uint32_t& min_confirm) {
	auto _method = ::mmx::Wallet_get_reserved_balances::create();
	_method->index = index;
	_method->min_confirm = min_confirm;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_reserved_balances_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::map<::mmx::addr_t, uint64_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::map<::mmx::addr_t, std::shared_ptr<const ::mmx::Contract>> WalletClient::get_contracts(const uint32_t& index) {
	auto _method = ::mmx::Wallet_get_contracts::create();
	_method->index = index;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_contracts_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::map<::mmx::addr_t, std::shared_ptr<const ::mmx::Contract>>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

::mmx::addr_t WalletClient::get_address(const uint32_t& index, const uint32_t& offset) {
	auto _method = ::mmx::Wallet_get_address::create();
	_method->index = index;
	_method->offset = offset;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_address_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::addr_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<::mmx::addr_t> WalletClient::get_all_addresses(const int32_t& index) {
	auto _method = ::mmx::Wallet_get_all_addresses::create();
	_method->index = index;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_all_addresses_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::mmx::addr_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::map<uint32_t, ::mmx::account_t> WalletClient::get_accounts() {
	auto _method = ::mmx::Wallet_get_accounts::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_accounts_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::map<uint32_t, ::mmx::account_t>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

void WalletClient::add_account(const uint32_t& index, const ::mmx::account_t& config) {
	auto _method = ::mmx::Wallet_add_account::create();
	_method->index = index;
	_method->config = config;
	vnx_request(_method, false);
}

void WalletClient::add_account_async(const uint32_t& index, const ::mmx::account_t& config) {
	auto _method = ::mmx::Wallet_add_account::create();
	_method->index = index;
	_method->config = config;
	vnx_request(_method, true);
}

::mmx::hash_t WalletClient::get_master_seed(const uint32_t& index) {
	auto _method = ::mmx::Wallet_get_master_seed::create();
	_method->index = index;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_master_seed_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::FarmerKeys> WalletClient::get_farmer_keys(const uint32_t& index) {
	auto _method = ::mmx::Wallet_get_farmer_keys::create();
	_method->index = index;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_farmer_keys_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::FarmerKeys>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::vector<std::shared_ptr<const ::mmx::FarmerKeys>> WalletClient::get_all_farmer_keys() {
	auto _method = ::mmx::Wallet_get_all_farmer_keys::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_all_farmer_keys_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<std::shared_ptr<const ::mmx::FarmerKeys>>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::addons::HttpResponse> WalletClient::http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path) {
	auto _method = ::vnx::addons::HttpComponent_http_request::create();
	_method->request = request;
	_method->sub_path = sub_path;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpResponse>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::addons::HttpData> WalletClient::http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes) {
	auto _method = ::vnx::addons::HttpComponent_http_request_chunk::create();
	_method->request = request;
	_method->sub_path = sub_path;
	_method->offset = offset;
	_method->max_bytes = max_bytes;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_chunk_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpData>>();
	} else {
		throw std::logic_error("WalletClient: invalid return value");
	}
}


} // namespace mmx
