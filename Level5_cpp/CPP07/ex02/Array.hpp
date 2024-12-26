/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:26:32 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/12 13:04:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T* array_;
		unsigned int size_;
	public:
		Array() : array_(new T()), size_(0){};
		Array(unsigned int n) : array_(new T(n)), size_(n){};
		Array(const Array &src) : array_(new T[src.size()]), size_(src.size()){
			for (unsigned int i = 0; i < size_; ++i)
				array_[i] = src.array_[i];
		}
		Array &operator=(const Array &src)
		{
			if (this != &src){
				delete [] array_;
				array_ = new T(src.size());
				size_ = src.size();
				for ( unsigned int i = 0; i < size_ ; ++i )
                	array_[i] = src.array_[i];
			}
			return (*this);
		}
		~Array(){ delete [] array_;}
		
		T& operator[](unsigned int i) const {
			if ( i >= size_ )
				throw OutOfBounds();
			return array_[i];
		}
		
		class OutOfBounds : public std::exception {
        	public:
            	virtual const char* what() const throw() { return "Index is out of range of array";}
    	};

		unsigned int size() const { return size_; }
};

//template < typename T >
//std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
//    for ( unsigned int i( 0 ); i < arr.size(); i++ )
//        out << arr[i] << " ";
//    return out;
//}

#endif