
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Wallet_CLIENT_HXX_
#define INCLUDE_mmx_Wallet_CLIENT_HXX_

#include <vnx/Client.h>
#include <mmx/FarmerKeys.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/stxo_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/utxo_entry_t.hxx>
#include <vnx/Module.h>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class WalletClient : public vnx::Client {
public:
	WalletClient(const std::string& service_name);
	
	WalletClient(vnx::Hash64 service_addr);
	
	::vnx::Object vnx_get_config_object();
	
	::vnx::Variant vnx_get_config(const std::string& name = "");
	
	void vnx_set_config_object(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config_object_async(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	void vnx_set_config_async(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	::vnx::TypeCode vnx_get_type_code();
	
	std::shared_ptr<const ::vnx::ModuleInfo> vnx_get_module_info();
	
	void vnx_restart();
	
	void vnx_restart_async();
	
	void vnx_stop();
	
	void vnx_stop_async();
	
	vnx::bool_t vnx_self_test();
	
	::mmx::hash_t send(const uint32_t& index = 0, const uint64_t& amount = 0, const ::mmx::addr_t& dst_addr = ::mmx::addr_t(), const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	std::vector<::mmx::utxo_entry_t> get_utxo_list(const uint32_t& index = 0);
	
	std::vector<::mmx::utxo_entry_t> get_utxo_list_for(const uint32_t& index = 0, const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	std::vector<::mmx::stxo_entry_t> get_stxo_list(const uint32_t& index = 0);
	
	std::vector<::mmx::stxo_entry_t> get_stxo_list_for(const uint32_t& index = 0, const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	std::vector<::mmx::tx_entry_t> get_history(const uint32_t& index = 0, const int32_t& since = 0);
	
	uint64_t get_balance(const uint32_t& index = 0, const ::mmx::addr_t& contract = ::mmx::addr_t());
	
	::mmx::addr_t get_address(const uint32_t& index = 0, const uint32_t& offset = 0);
	
	::mmx::hash_t get_master_seed(const uint32_t& index = 0);
	
	std::shared_ptr<const ::mmx::FarmerKeys> get_farmer_keys(const uint32_t& index = 0);
	
	std::vector<std::shared_ptr<const ::mmx::FarmerKeys>> get_all_farmer_keys();
	
	std::shared_ptr<const ::vnx::addons::HttpResponse> http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "");
	
	std::shared_ptr<const ::vnx::addons::HttpData> http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request = nullptr, const std::string& sub_path = "", const int64_t& offset = 0, const int64_t& max_bytes = 0);
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Wallet_CLIENT_HXX_
