#ifndef HELPERS_HPP
# define HELPERS_HPP

#include "iterator.hpp"
#include <stddef.h>
#include <sstream>

namespace ft
{

	template<typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	/* Iterator types */
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag {};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};

	template<class Iterator> struct iterator_traits
	{

		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<typename T> struct iterator_traits<T*>
	{

		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T							*pointer;
		typedef T							&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename T> struct iterator_traits<const T*>
	{

		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T							*pointer;
		typedef T							&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class Iterator>
	class reverseIterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::reference reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
			
			/* Default constructor */
			reverseIterator(void) : _iter()
			{}
			
			explicit reverseIterator(iterator_type iterType) : _iter(iterType)
			{}

			template <class Iter> reverseIterator(const reverseIterator<Iter> &reverseIter) : _iter(reverseIter.base())
			{}

			/* Copy assignment operator */
			reverseIterator &operator=(const reverseIterator &rhs)
			{
				this->_iter = rhs._iter;
				return (*this);
			}

			/* Destructor */
			virtual ~reverseIterator(void)
			{}

			iterator_type base(void) const
			{
				return (this->_iter);
			}

			reference operator*(void) const
			{
				iterator_type temp = this->_iter;
				temp--;
				return (*temp);
			}

			reverseIterator operator+(difference_type n) const
			{
				return (reverseIterator(this->_iter - n));
			}
			
			reverseIterator &operator++(void)
			{
				this->_iter--;
				return (*this);
			}
			
			reverseIterator operator++(int)
			{
				reverseIterator temp = *this;
				++(*this);
				return (temp);
			}
			
			reverseIterator &operator+=(difference_type n)
			{
				*this = *this + n;
				return (*this);
			}
			
			reverseIterator operator-(difference_type n) const
			{
				return (reverseIterator(this->_iter + n));
			}
			
			reverseIterator &operator--(void)
			{
				this->_iter++;
				return (*this);
			}
			
			reverseIterator operator--(int)
			{
				reverseIterator temp = *this;
				--(*this);
				return (temp);
			}
			
			reverseIterator &operator-=(difference_type n)
			{
				*this = *this - n;
				return (*this);
			}
			
			pointer operator->(void) const
			{
				return(&(operator*()));
			}
			
			reference operator[](difference_type n) const
			{
				return (this->base()[-n - 1]);
			}
		
		/* Private section: All attributes below the 'private' keyword are just accessible within the class */
		private:
			iterator_type	_iter;	
	};

	//non-member overloads for reverseIterator
	template <class Iterator>
	bool operator==(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator==(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator!=(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator<(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator<=(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator>(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverseIterator<Iterator> &lhs,
					const reverseIterator<Iterator> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	//for comparisons between reverseIterator and const_reverseIterator
	template <class Iterator_L, class Iterator_R>
	bool operator>=(const reverseIterator<Iterator_L> &lhs,
					const reverseIterator<Iterator_R> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n,
										const reverseIterator<Iterator> &rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
	typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator> &lhs,
																const reverseIterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
	
	template <typename T>
	std::string to_str(T n)
	{
		std::ostringstream outputStringStream;
		outputStringStream << n;
		return (outputStringStream.str());
	}
	
	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			first++;
			n++;
		}
		return (n);
	}

	/* Lexicigraphical comparisons */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/* enable_if */
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/* is_integral */
	template <class T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						valueType;
		typedef integral_constant<T, v>	type;
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	//non-itegral types
	template <class T> struct is_integral : false_type {};

	//integral types
	template <> struct is_integral<bool>					: true_type {};
	template <> struct is_integral<char>					: true_type {};
	template <> struct is_integral<char16_t>				: true_type {};
	template <> struct is_integral<char32_t>				: true_type {};
	template <> struct is_integral<wchar_t>					: true_type {};
	template <> struct is_integral<signed char>				: true_type {};
	template <> struct is_integral<short int>				: true_type {};
	template <> struct is_integral<int>						: true_type {};
	template <> struct is_integral<long int>				: true_type {};
	template <> struct is_integral<long long int>			: true_type {};
	template <> struct is_integral<unsigned char>			: true_type {};
	template <> struct is_integral<unsigned short int>		: true_type {};
	template <> struct is_integral<unsigned int>			: true_type {};
	template <> struct is_integral<unsigned long int>		: true_type {};
	template <> struct is_integral<unsigned long long int>	: true_type {};

	/* Pair */
	template <class T1, class T2>
	class pair
	{
	public:
		
		/* Types of pair values */
		typedef T1 firstValueType;
		typedef T2 secondValueType;

		/* Pair values */
		firstValueType first;
		secondValueType second;

		/* Default constructor */
		pair(void) : first(), second() {}

		/* Parametric constructor */
		pair(const firstValueType &a, const secondValueType &b) : first(a), second(b) {}

		/* Copy constructor */
		template <class U, class V>
		pair(const pair<U, V> &copy) : first(copy.first), second(copy.second) {}
		
		/* Copy assignment operator */
		const pair &operator=(const pair &rhs)
		{
			this->first = rhs.first;
			this->second = rhs.second;
			return (*this);
		}

		/* Destructor */
		~pair(void) {}
	};

	/* Is equal operator */
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	/* Is not equal operator */
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	/* Is smaller than operator */
	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || lhs.second < rhs.second);
	}

	/* Is smaller or equal than operator */
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	/* Is bigger than operator */
	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	/* Is bigger or equal than operator */
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	/* Make pair will create a pair out of given values */
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif