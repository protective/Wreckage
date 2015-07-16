/* 
 * File:   SOrderVars.h
 * Author: karsten
 *
 * Created on 4. september 2014, 22:39
 */

#ifndef VARIABLE_H
#define	VARIABLE_H

#include <cstddef>
#include <vector>
#include <inttypes.h>

using namespace std;
namespace wkl {
	class Variable;
	class VObject {
	public:
		
		VObject (){
			
		};
		
		VObject (VObject* vo){
			_vector = vector<Variable>(vo->_vector);
		};
		
		virtual VObject* clone(){
			return new VObject(this);
		};
		
		vector<Variable> _vector;
	};
	
	class Variable {
	public:
		int32_t v;
		VObject* t;

		Variable (){
			this->v = 0;
			this->t = NULL;
		}	
		
		Variable (int32_t v){
			this->v = v;
			this->t = NULL;
		}
		
		Variable (const Variable& v){
			this->v = v.v;
			if(v.t)
				this->t = v.t->clone();
			else
				this->t = NULL;
		}
		~Variable(){
			if(this->t)
				delete this->t;
		}
		
		inline Variable & operator+=(const Variable &rhs)
		{
			if(this->t)
				delete this->t;
			this->t = NULL;
			this->v += rhs.v;
			return *this;
		}
		inline Variable & operator-=(const Variable &rhs)
		{
			if(this->t)
				delete this->t;
			this->t = NULL;
			this->v -= rhs.v;
			return *this;
		}
		inline Variable & operator=(const Variable &rhs)
		{
			this->v = rhs.v;
			if(this->t)
				delete this->t;
			if(rhs.t)
				this->t = rhs.t->clone();
			else
				this->t = NULL;
			return *this;
		}
		
		inline Variable & operator+=(const int rhs) {
			this->v += rhs;
			if(this->t)
				delete this->t;
			this->t = NULL;
			return *this;
		}
		inline Variable & operator-=(const int rhs) {
			this->v -= rhs;
			if(this->t)
				delete this->t;
			this->t = NULL;
			return *this;
		}
		inline Variable & operator=(const int rhs)
		{
			this->v = rhs;
			if(this->t)
				delete this->t;
			this->t = NULL;
			return *this;
		}

		operator bool() const {
			return this->v || this->t;
		  }
		
	};

	inline bool operator==(const Variable& lhs, const Variable& rhs){return lhs.v == rhs.v && lhs.t == rhs.t;}
	inline bool operator!=(const Variable& lhs, const Variable& rhs){return !operator==(lhs,rhs);}
	inline bool operator< (const Variable& lhs, const Variable& rhs){return lhs.v < rhs.v;}
	inline bool operator> (const Variable& lhs, const Variable& rhs){return  operator< (rhs,lhs);}
	inline bool operator<=(const Variable& lhs, const Variable& rhs){return !operator> (lhs,rhs);}
	inline bool operator>=(const Variable& lhs, const Variable& rhs){return !operator< (lhs,rhs);}
		
		
	inline Variable operator+(Variable lhs, const Variable& rhs)
	{
	  lhs.v += rhs.v;
	  
	  return lhs;
	}

	inline Variable operator-(Variable lhs, const Variable& rhs)
	{
	  lhs.v -= rhs.v;
	  
	  return lhs;
	}
	
	inline Variable operator*(Variable lhs, const Variable& rhs)
	{
	  lhs.v *= rhs.v;
	  
	  return lhs;
	}

	inline Variable operator/(Variable lhs, const Variable& rhs)
	{
	  lhs.v /= rhs.v;
	  
	  return lhs;
	}
	
	class VTuple{
		vector<Variable*> t;
	};

}
#endif	/* VARIABLE_H */

