
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/WalletAsyncClient.hxx>
#include <mmx/FarmerKeys.hxx>
#include <mmx/Wallet_get_address.hxx>
#include <mmx/Wallet_get_address_return.hxx>
#include <mmx/Wallet_get_all_farmer_keys.hxx>
#include <mmx/Wallet_get_all_farmer_keys_return.hxx>
#include <mmx/Wallet_get_balance.hxx>
#include <mmx/Wallet_get_balance_return.hxx>
#include <mmx/Wallet_get_farmer_keys.hxx>
#include <mmx/Wallet_get_farmer_keys_return.hxx>
#include <mmx/Wallet_get_history.hxx>
#include <mmx/Wallet_get_history_return.hxx>
#include <mmx/Wallet_get_master_seed.hxx>
#include <mmx/Wallet_get_master_seed_return.hxx>
#include <mmx/Wallet_get_stxo_list.hxx>
#include <mmx/Wallet_get_stxo_list_return.hxx>
#include <mmx/Wallet_get_stxo_list_for.hxx>
#include <mmx/Wallet_get_stxo_list_for_return.hxx>
#include <mmx/Wallet_get_utxo_list.hxx>
#include <mmx/Wallet_get_utxo_list_return.hxx>
#include <mmx/Wallet_get_utxo_list_for.hxx>
#include <mmx/Wallet_get_utxo_list_for_return.hxx>
#include <mmx/Wallet_send.hxx>
#include <mmx/Wallet_send_return.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/stxo_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/utxo_entry_t.hxx>
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

WalletAsyncClient::WalletAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

WalletAsyncClient::WalletAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t WalletAsyncClient::vnx_get_config_object(const std::function<void(const ::vnx::Object&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config_object::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 0;
		vnx_queue_vnx_get_config_object[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_get_config(const std::string& name, const std::function<void(const ::vnx::Variant&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config::create();
	_method->name = name;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 1;
		vnx_queue_vnx_get_config[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_set_config_object(const ::vnx::Object& config, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 2;
		vnx_queue_vnx_set_config_object[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_set_config(const std::string& name, const ::vnx::Variant& value, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 3;
		vnx_queue_vnx_set_config[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_get_type_code(const std::function<void(const ::vnx::TypeCode&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 4;
		vnx_queue_vnx_get_type_code[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_get_module_info(const std::function<void(std::shared_ptr<const ::vnx::ModuleInfo>)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_module_info::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 5;
		vnx_queue_vnx_get_module_info[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_restart(const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 6;
		vnx_queue_vnx_restart[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_stop(const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 7;
		vnx_queue_vnx_stop[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::vnx_self_test(const std::function<void(const vnx::bool_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_self_test::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 8;
		vnx_queue_vnx_self_test[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::send(const uint32_t& index, const uint64_t& amount, const ::mmx::addr_t& dst_addr, const ::mmx::addr_t& contract, const std::function<void(const ::mmx::hash_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_send::create();
	_method->index = index;
	_method->amount = amount;
	_method->dst_addr = dst_addr;
	_method->contract = contract;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 9;
		vnx_queue_send[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_utxo_list(const uint32_t& index, const std::function<void(const std::vector<::mmx::utxo_entry_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_utxo_list::create();
	_method->index = index;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 10;
		vnx_queue_get_utxo_list[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_utxo_list_for(const uint32_t& index, const ::mmx::addr_t& contract, const std::function<void(const std::vector<::mmx::utxo_entry_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_utxo_list_for::create();
	_method->index = index;
	_method->contract = contract;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 11;
		vnx_queue_get_utxo_list_for[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_stxo_list(const uint32_t& index, const std::function<void(const std::vector<::mmx::stxo_entry_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_stxo_list::create();
	_method->index = index;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 12;
		vnx_queue_get_stxo_list[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_stxo_list_for(const uint32_t& index, const ::mmx::addr_t& contract, const std::function<void(const std::vector<::mmx::stxo_entry_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_stxo_list_for::create();
	_method->index = index;
	_method->contract = contract;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 13;
		vnx_queue_get_stxo_list_for[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_history(const uint32_t& index, const int32_t& since, const std::function<void(const std::vector<::mmx::tx_entry_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_history::create();
	_method->index = index;
	_method->since = since;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 14;
		vnx_queue_get_history[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_balance(const uint32_t& index, const ::mmx::addr_t& contract, const std::function<void(const uint64_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_balance::create();
	_method->index = index;
	_method->contract = contract;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 15;
		vnx_queue_get_balance[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_address(const uint32_t& index, const uint32_t& offset, const std::function<void(const ::mmx::addr_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_address::create();
	_method->index = index;
	_method->offset = offset;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 16;
		vnx_queue_get_address[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_master_seed(const uint32_t& index, const std::function<void(const ::mmx::hash_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_master_seed::create();
	_method->index = index;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 17;
		vnx_queue_get_master_seed[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_farmer_keys(const uint32_t& index, const std::function<void(std::shared_ptr<const ::mmx::FarmerKeys>)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_farmer_keys::create();
	_method->index = index;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 18;
		vnx_queue_get_farmer_keys[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::get_all_farmer_keys(const std::function<void(const std::vector<std::shared_ptr<const ::mmx::FarmerKeys>>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::mmx::Wallet_get_all_farmer_keys::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 19;
		vnx_queue_get_all_farmer_keys[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const std::function<void(std::shared_ptr<const ::vnx::addons::HttpResponse>)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::addons::HttpComponent_http_request::create();
	_method->request = request;
	_method->sub_path = sub_path;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 20;
		vnx_queue_http_request[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t WalletAsyncClient::http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes, const std::function<void(std::shared_ptr<const ::vnx::addons::HttpData>)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::addons::HttpComponent_http_request_chunk::create();
	_method->request = request;
	_method->sub_path = sub_path;
	_method->offset = offset;
	_method->max_bytes = max_bytes;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 21;
		vnx_queue_http_request_chunk[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

int32_t WalletAsyncClient::vnx_purge_request(uint64_t _request_id, const vnx::exception& _ex) {
	std::unique_lock<std::mutex> _lock(vnx_mutex);
	const auto _iter = vnx_pending.find(_request_id);
	if(_iter == vnx_pending.end()) {
		return -1;
	}
	const auto _index = _iter->second;
	vnx_pending.erase(_iter);
	switch(_index) {
		case 0: {
			const auto _iter = vnx_queue_vnx_get_config_object.find(_request_id);
			if(_iter != vnx_queue_vnx_get_config_object.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_config_object.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 1: {
			const auto _iter = vnx_queue_vnx_get_config.find(_request_id);
			if(_iter != vnx_queue_vnx_get_config.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_config.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 2: {
			const auto _iter = vnx_queue_vnx_set_config_object.find(_request_id);
			if(_iter != vnx_queue_vnx_set_config_object.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_set_config_object.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 3: {
			const auto _iter = vnx_queue_vnx_set_config.find(_request_id);
			if(_iter != vnx_queue_vnx_set_config.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_set_config.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 4: {
			const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
			if(_iter != vnx_queue_vnx_get_type_code.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_type_code.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 5: {
			const auto _iter = vnx_queue_vnx_get_module_info.find(_request_id);
			if(_iter != vnx_queue_vnx_get_module_info.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_module_info.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 6: {
			const auto _iter = vnx_queue_vnx_restart.find(_request_id);
			if(_iter != vnx_queue_vnx_restart.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_restart.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 7: {
			const auto _iter = vnx_queue_vnx_stop.find(_request_id);
			if(_iter != vnx_queue_vnx_stop.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_stop.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 8: {
			const auto _iter = vnx_queue_vnx_self_test.find(_request_id);
			if(_iter != vnx_queue_vnx_self_test.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_self_test.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 9: {
			const auto _iter = vnx_queue_send.find(_request_id);
			if(_iter != vnx_queue_send.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_send.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 10: {
			const auto _iter = vnx_queue_get_utxo_list.find(_request_id);
			if(_iter != vnx_queue_get_utxo_list.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_utxo_list.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 11: {
			const auto _iter = vnx_queue_get_utxo_list_for.find(_request_id);
			if(_iter != vnx_queue_get_utxo_list_for.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_utxo_list_for.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 12: {
			const auto _iter = vnx_queue_get_stxo_list.find(_request_id);
			if(_iter != vnx_queue_get_stxo_list.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_stxo_list.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 13: {
			const auto _iter = vnx_queue_get_stxo_list_for.find(_request_id);
			if(_iter != vnx_queue_get_stxo_list_for.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_stxo_list_for.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 14: {
			const auto _iter = vnx_queue_get_history.find(_request_id);
			if(_iter != vnx_queue_get_history.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_history.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 15: {
			const auto _iter = vnx_queue_get_balance.find(_request_id);
			if(_iter != vnx_queue_get_balance.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_balance.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 16: {
			const auto _iter = vnx_queue_get_address.find(_request_id);
			if(_iter != vnx_queue_get_address.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_address.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 17: {
			const auto _iter = vnx_queue_get_master_seed.find(_request_id);
			if(_iter != vnx_queue_get_master_seed.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_master_seed.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 18: {
			const auto _iter = vnx_queue_get_farmer_keys.find(_request_id);
			if(_iter != vnx_queue_get_farmer_keys.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_farmer_keys.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 19: {
			const auto _iter = vnx_queue_get_all_farmer_keys.find(_request_id);
			if(_iter != vnx_queue_get_all_farmer_keys.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_all_farmer_keys.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 20: {
			const auto _iter = vnx_queue_http_request.find(_request_id);
			if(_iter != vnx_queue_http_request.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_http_request.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 21: {
			const auto _iter = vnx_queue_http_request_chunk.find(_request_id);
			if(_iter != vnx_queue_http_request_chunk.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_http_request_chunk.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
	}
	return _index;
}

int32_t WalletAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Value> _value) {
	std::unique_lock<std::mutex> _lock(vnx_mutex);
	const auto _iter = vnx_pending.find(_request_id);
	if(_iter == vnx_pending.end()) {
		throw std::runtime_error("WalletAsyncClient: received unknown return");
	}
	const auto _index = _iter->second;
	vnx_pending.erase(_iter);
	switch(_index) {
		case 0: {
			const auto _iter = vnx_queue_vnx_get_config_object.find(_request_id);
			if(_iter == vnx_queue_vnx_get_config_object.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_config_object.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::Object>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 1: {
			const auto _iter = vnx_queue_vnx_get_config.find(_request_id);
			if(_iter == vnx_queue_vnx_get_config.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_config.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::Variant>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 2: {
			const auto _iter = vnx_queue_vnx_set_config_object.find(_request_id);
			if(_iter == vnx_queue_vnx_set_config_object.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_set_config_object.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 3: {
			const auto _iter = vnx_queue_vnx_set_config.find(_request_id);
			if(_iter == vnx_queue_vnx_set_config.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_set_config.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 4: {
			const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
			if(_iter == vnx_queue_vnx_get_type_code.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_type_code.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::TypeCode>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 5: {
			const auto _iter = vnx_queue_vnx_get_module_info.find(_request_id);
			if(_iter == vnx_queue_vnx_get_module_info.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_module_info.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::ModuleInfo>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 6: {
			const auto _iter = vnx_queue_vnx_restart.find(_request_id);
			if(_iter == vnx_queue_vnx_restart.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_restart.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 7: {
			const auto _iter = vnx_queue_vnx_stop.find(_request_id);
			if(_iter == vnx_queue_vnx_stop.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_stop.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 8: {
			const auto _iter = vnx_queue_vnx_self_test.find(_request_id);
			if(_iter == vnx_queue_vnx_self_test.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_self_test.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<vnx::bool_t>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 9: {
			const auto _iter = vnx_queue_send.find(_request_id);
			if(_iter == vnx_queue_send.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_send.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_send_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::mmx::hash_t>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 10: {
			const auto _iter = vnx_queue_get_utxo_list.find(_request_id);
			if(_iter == vnx_queue_get_utxo_list.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_utxo_list.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_utxo_list_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::mmx::utxo_entry_t>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 11: {
			const auto _iter = vnx_queue_get_utxo_list_for.find(_request_id);
			if(_iter == vnx_queue_get_utxo_list_for.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_utxo_list_for.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_utxo_list_for_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::mmx::utxo_entry_t>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 12: {
			const auto _iter = vnx_queue_get_stxo_list.find(_request_id);
			if(_iter == vnx_queue_get_stxo_list.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_stxo_list.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_stxo_list_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::mmx::stxo_entry_t>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 13: {
			const auto _iter = vnx_queue_get_stxo_list_for.find(_request_id);
			if(_iter == vnx_queue_get_stxo_list_for.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_stxo_list_for.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_stxo_list_for_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::mmx::stxo_entry_t>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 14: {
			const auto _iter = vnx_queue_get_history.find(_request_id);
			if(_iter == vnx_queue_get_history.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_history.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_history_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::mmx::tx_entry_t>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 15: {
			const auto _iter = vnx_queue_get_balance.find(_request_id);
			if(_iter == vnx_queue_get_balance.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_balance.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_balance_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<uint64_t>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 16: {
			const auto _iter = vnx_queue_get_address.find(_request_id);
			if(_iter == vnx_queue_get_address.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_address.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_address_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::mmx::addr_t>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 17: {
			const auto _iter = vnx_queue_get_master_seed.find(_request_id);
			if(_iter == vnx_queue_get_master_seed.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_master_seed.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_master_seed_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::mmx::hash_t>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 18: {
			const auto _iter = vnx_queue_get_farmer_keys.find(_request_id);
			if(_iter == vnx_queue_get_farmer_keys.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_farmer_keys.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_farmer_keys_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::FarmerKeys>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 19: {
			const auto _iter = vnx_queue_get_all_farmer_keys.find(_request_id);
			if(_iter == vnx_queue_get_all_farmer_keys.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_all_farmer_keys.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::mmx::Wallet_get_all_farmer_keys_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<std::shared_ptr<const ::mmx::FarmerKeys>>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 20: {
			const auto _iter = vnx_queue_http_request.find(_request_id);
			if(_iter == vnx_queue_http_request.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_http_request.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpResponse>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 21: {
			const auto _iter = vnx_queue_http_request_chunk.find(_request_id);
			if(_iter == vnx_queue_http_request_chunk.end()) {
				throw std::runtime_error("WalletAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_http_request_chunk.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_chunk_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpData>>());
				} else {
					throw std::logic_error("WalletAsyncClient: invalid return value");
				}
			}
			break;
		}
		default:
			if(_index >= 0) {
				throw std::logic_error("WalletAsyncClient: invalid callback index");
			}
	}
	return _index;
}


} // namespace mmx
