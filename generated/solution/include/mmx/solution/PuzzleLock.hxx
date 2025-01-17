
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_solution_PuzzleLock_HXX_
#define INCLUDE_mmx_solution_PuzzleLock_HXX_

#include <mmx/solution/package.hxx>
#include <mmx/Solution.hxx>


namespace mmx {
namespace solution {

class MMX_SOLUTION_EXPORT PuzzleLock : public ::mmx::Solution {
public:
	
	std::shared_ptr<const ::mmx::Solution> puzzle;
	std::shared_ptr<const ::mmx::Solution> target;
	
	typedef ::mmx::Solution Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x7f4b6db1893deaecull;
	
	PuzzleLock() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual vnx::bool_t is_valid() const override;
	
	static std::shared_ptr<PuzzleLock> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const PuzzleLock& _value);
	friend std::istream& operator>>(std::istream& _in, PuzzleLock& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void PuzzleLock::accept_generic(T& _visitor) const {
	_visitor.template type_begin<PuzzleLock>(3);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("puzzle", 1); _visitor.accept(puzzle);
	_visitor.type_field("target", 2); _visitor.accept(target);
	_visitor.template type_end<PuzzleLock>(3);
}


} // namespace mmx
} // namespace solution


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_solution_PuzzleLock_HXX_
