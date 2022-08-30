
#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "helpers.hpp"

namespace ft
{
	template <typename T>
	class vectorIterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		/* Public section: All attributes below the 'public' keyword are accessible from everywhere */
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		
			/* Default constructor */
			vectorIterator(void) : _element(nullptr)
			{}
			
			/* Copy constructor */
			vectorIterator(const vectorIterator &copy) : _element(copy._element)
			{}
			
			/* Pointer constructor */	
			vectorIterator(pointer element) : _element(element)
			{}
			
			/* Copy assignment operator */
			vectorIterator &operator=(const vectorIterator &iter)
			{
				this->_element = iter._element;
				return (*this);
			}
			
			/* Destructor */
			virtual ~vectorIterator(void)
			{}

			/* Return pointer */
			pointer base(void) const
			{
				return (this->_element);
			}

			/* Dereference pointer */
			reference operator*(void) const
			{
				return (*(this->_element));
			}

			/* Member access operator */
			pointer operator->(void)
			{
				return (&(this->operator*()));
			}
			
			/* Pre incrementing operator */
			vectorIterator operator++(int)
			{
				vectorIterator tmp = *this;
				this->_element++;
				return (tmp);
			}
			
			/* Post incrementing operator */
			vectorIterator &operator++(void)
			{
				this->_element++;
				return (*this);
			}
			
			/* Pre decrementing operator */
			vectorIterator operator--(int)
			{
				vectorIterator tmp = *this;
				this->_element--;
				return (tmp);
			}
			
			/* Post decrementing operator */
			vectorIterator &operator--(void)
			{
				this->_element--;
				return (*this);
			}

			/* Addition operator */
			vectorIterator operator+(difference_type n) const
			{
				return (this->_element + n);	
			}

			/* Add and equal operator */
			vectorIterator &operator+=(difference_type n)
			{
				this->_element += n;
				return (*this);
			}
			
			/* Subtraction operator */
			vectorIterator operator-(difference_type n) const
			{
				return (this->_element - n);
			}

			/* Subtract and equal operator */
			vectorIterator &operator-=(difference_type n)
			{
				this->_element -= n;
				return (*this);
			}

			/* Is equal operator */
			bool operator==(const vectorIterator<T> &rhs)
			{
				return (this->base() == rhs.base());
			}

			/* Is not equal operator */
			bool operator!=(const vectorIterator<T> &rhs)
			{
				return (this->base() != rhs.base());
			}
			
			/* Is bigger than operator */
			bool operator>(const vectorIterator<T> &rhs)
			{
				return (this->base() > rhs.base());
			}

			/* Is bigger or equal than operator */
			bool operator>=(const vectorIterator<T> &rhs)
			{
				return (this->base() >= rhs.base());
			}

			/* Is smaller than operator */
			bool operator<(const vectorIterator<T> &rhs)
			{
				return (this->base() > rhs.base());
			}

			/* Is smaller or equal than operator */
			bool operator<=(const vectorIterator<T> &rhs)
			{
				return (this->base() >= rhs.base());
			}

			reference operator[](difference_type n)
			{
				return (*(this->_element + n));
			}
			
		private:
			pointer _element;
	};

	//adding difference_type with iterator
	template<typename T>
	vectorIterator<T> operator+(typename vectorIterator<T>::difference_type n,
										vectorIterator<T> &it)
	{
		return (&(*it) + n);
	}

	//returns difference between two iterators
	template<typename T>
	typename vectorIterator<T>::difference_type operator-(const vectorIterator<T> &lhs,
																const vectorIterator<T> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	typename vectorIterator<T>::difference_type operator-(const vectorIterator<const T> &lhs,
																const vectorIterator<T> &rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif