
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Farmer_CLIENT_HXX_
#define INCLUDE_mmx_Farmer_CLIENT_HXX_

#include <vnx/Client.h>
#include <mmx/BlockHeader.hxx>
#include <mmx/FarmInfo.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Hash64.hpp>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>


namespace mmx {

class FarmerClient : public vnx::Client {
public:
	FarmerClient(const std::string& service_name);
	
	FarmerClient(vnx::Hash64 service_addr);
	
	::vnx::Hash64 get_mac_addr();
	
	std::shared_ptr<const ::mmx::FarmInfo> get_farm_info();
	
	std::shared_ptr<const ::mmx::BlockHeader> sign_block(std::shared_ptr<const ::mmx::BlockHeader> block = nullptr, const uint64_t& reward_amount = 0);
	
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
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Farmer_CLIENT_HXX_
