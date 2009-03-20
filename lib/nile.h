#include <iostream>
#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <deque>

namespace nile {

class Exception : public std::exception {
};

class TypeError : public Exception {
};

class BaseType;
typedef boost::shared_ptr<BaseType> BaseP;

class ListType;
typedef boost::shared_ptr<ListType> ListP;

class NumberType;
typedef boost::shared_ptr<NumberType> NumberP;

class StringType;
typedef boost::shared_ptr<StringType> StringP;

class BaseType : public boost::enable_shared_from_this<BaseType> {
	public:
		virtual bool isTrue() { throw TypeError(); }
		virtual BaseP call(BaseP arg) { throw TypeError(); }
		virtual BaseP call() { return BaseP(this); }
		virtual int getArity() { return 0; }
		virtual StringP nile_toString();
		virtual NumberP nile_cmp(BaseP rhs) { throw TypeError(); }

};

class StringType : public BaseType {
		std::string value;
	public:
		StringType(std::string value_) : value(value_) {}	
		std::string getValue() const { return value; }
		StringP nile_toString() 
		{ 
			return boost::dynamic_pointer_cast<StringType>(shared_from_this()); 
		}
};

class NumberType : public BaseType {
		long value;
	public:
		NumberType(long value_) : value(value_) {}	
		virtual bool isTrue() { return value!=0; }
		long getValue() { return value; }
		NumberP nile_cmp(BaseP rhs) {
			return NumberP(new NumberType((boost::dynamic_pointer_cast<NumberType>(rhs))->getValue()-getValue()));
		}
};

class NoneType : public BaseType {
};

class ListType : public BaseType {
	private:
		typedef std::deque<BaseP> container_t;
		container_t container;
	public:
		void nile_append(BaseP item)
		{
			container.push_back(item);
		}
		BaseP nile_pop()
		{
			BaseP ret = container.back();
			container.pop_back();
			return ret;
		}
		BaseP nile_shift()
		{
			BaseP ret = container.front();
			container.pop_front();
			return ret;
		}
		void nile_unshift(BaseP item)
		{
			container.push_front(item);
		}
		NumberP nile_length()
		{
			return NumberP(new NumberType(container.size()));
		}
};


}

extern nile::BaseP nile_None;
extern nile::BaseP nile_print;
extern nile::BaseP nile_if;
