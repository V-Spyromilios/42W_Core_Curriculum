#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "helpers.hpp"

namespace ft
{

	template <typename T, typename Allocator = std::allocator<T> > class vector
	{
	public:
		typedef T													value_type;
		typedef Allocator											allocator_type;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename ft::vectorIterator<T>						iterator;
		typedef typename ft::vectorIterator<const T>				const_iterator;
		typedef typename ft::reverseIterator<iterator>				reverse_iterator;
		typedef typename ft::reverseIterator<const_iterator>		const_reverse_iterator;
		typedef typename allocator_type::size_type					size_type;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;

		/* Default constructor */
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(nullptr), _end(nullptr), _capacity(nullptr) {}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(nullptr), _end(nullptr), _capacity(nullptr)
		{
			_start = _alloc.allocate(n);
			_capacity = _start + n;
			_end = _start;
			while (n--)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, \
				const allocator_type &alloc = allocator_type(),
				typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr) : _alloc(alloc)
		{
			difference_type n = ft::distance(first, last);
			this->_start = this->_alloc.allocate(n);
			this->_end = this->_start;
			this->_capacity = this->_start + n;
			while (n--)
			{
				this->_alloc.construct(this->_end, *first);
				first++;
				this->_end++;
			}
		}

		vector(const vector &x) : _alloc(x._alloc), _start(nullptr), _end(nullptr), _capacity(nullptr)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}

		~vector(void)
		{
			this->clear();
			this->_alloc.deallocate(this->_start, this->capacity());
		}

		vector &operator=(const vector &x)
		{
			if (x == *this)
				return (*this);
			this->clear();
			this->insert(this->end(), x.begin(), x.end());
			return (*this);
		}

		iterator begin(void)
		{
			return (this->_start);
		}

		const_iterator begin(void) const
		{
			return (const_iterator(this->_start));
		}

		iterator end(void)
		{
			if (this->empty())
				return (this->begin());
			return (this->_end);
		}

		const_iterator end(void) const
		{
			if (this->empty())
				return (this->begin());
			return (this->_end);
		}

		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin(void) const
		{
			return (reverse_iterator(this->end()));
		}

		reverse_iterator rend(void)
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend(void) const
		{
			return (reverse_iterator(this->begin()));
		}

		size_type size(void) const
		{
			return (this->_end - this->_start);
		}

		size_type max_size(void) const
		{
			return (allocator_type().max_size());
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->max_size())
				throw std::length_error("vector::resize");
			else if (n < this->size())
			{
				while (this->size() > n)
				{
					this->_end--;
					this->_alloc.destroy(this->_end);
				}
			}
			else
				this->insert(this->end(), n - this->size(), val);
		}

		size_type capacity(void) const
		{
			return (this->_capacity - this->_start);
		}

		bool empty(void) const
		{
			if (this->size() == 0)
				return (true);
			return (false);
		}

		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			else if (n > this->capacity())
			{
				pointer prev_start = this->_start;
				pointer prev_end = this->_end;
				size_type prev_size = this->size();
				size_type prev_capacity = this->capacity();

				this->_start = this->_alloc.allocate(n);
				this->_capacity = this->_start + n;
				this->_end = this->_start;
				while (prev_start != prev_end)
				{
					this->_alloc.construct(this->_end, *prev_start);
					this->_end++;
					prev_start++;
				}
				this->_alloc.deallocate(prev_start - prev_size, prev_capacity);
			}
		}

		reference operator[](size_type n)
		{
			return (*(this->_start + n));
		}

		const_reference operator[](size_type n) const
		{
			return (*(this->_start + n));
		}

		reference at(size_type n)
		{
			if (n >= this->size())
				throw std::out_of_range("vector::at: n == " + to_str(n)
										+ " is bigger than vector size == " + to_str(this->size()));
			return ((*this)[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range("vector::at: n == " + ft::to_str(n)
										+ " is bigger than vector size == " + ft::to_str(this->size()));
			return ((*this)[n]);
		}

		reference front(void)
		{
			return (*this->_start);
		}

		const_reference front(void) const
		{
			return (*this->_start);
		}

		reference back(void)
		{
			return (*(this->_end - 1));
		}

		const_reference back(void) const
		{
			return (*(this->_end - 1));
		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr)
		{
			this->clear();
			size_type dist = ft::distance(first, last);
			if (size_type(this->_capacity - this->_start) >= dist)
			{
				while (first != last)
				{
					this->_alloc.construct(this->_end, *first);
					first++;
					this->_end++;
				}
			}
			else
			{
				pointer new_start = this->_alloc.allocate(dist);
				pointer new_end = new_start;
				pointer new_capacity = new_start + dist;
				while (first != last)
				{
					this->_alloc.construct(new_end, *first);
					first++;
					new_end++;
				}
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_end = new_end;
				this->_capacity = new_capacity;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			if (n == 0)
				return ;
			if (size_type(this->_capacity - this->_start) >= n)
			{
				while (n)
				{
					this->_alloc.construct(this->_end, val);
					n--;
					this->_end++;
				}
			}
			else
			{
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = this->_alloc.allocate(n);
				this->_end = this->_start;
				this->_capacity = this->_start + n;
				while (n)
				{
					this->_alloc.construct(this->_end, val);
					n--;
					this->_end++;
				}
			}
		}

		void push_back(const value_type &val)
		{
			if (this->_end == this->_capacity)
			{
				int new_capacity;
				if (this->size() == 0)
					new_capacity = 1;
				else
					new_capacity = this->size() * 2;
				this->reserve(new_capacity);
			}
			this->_alloc.construct(this->_end, val);
			this->_end++;
		}

		void pop_back(void)
		{
			this->_alloc.destroy(&(this->back()));
			this->_end--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type pos = &(*position) - this->_start;
			if (size_type(this->_capacity - this->_end) >= this->size() + 1)
			{
				for (size_type i = 0; i < pos; i++)
					this->_alloc.construct(this->_end - i, *(this->_end - i - 1));
				this->_end++;
				this->_alloc.construct(&(*position), val);
			}
			else
			{
				int new_capacity;
				if (this->size() == 0)
					new_capacity = 1;
				else
					new_capacity = this->size() * 2;
				pointer new_start = this->_alloc.allocate(new_capacity);
				pointer new_end = new_start + this->size() + 1;
				pointer new_capacity_ptr = new_start + new_capacity;
				for (size_type i = 0; i < pos; i++)
					this->_alloc.construct(new_start + i, *(this->_start + i));
				this->_alloc.construct(new_start + pos, val);
				for (size_type j = 0; j < this->size() - pos; j++)
					this->_alloc.construct(new_end - j - 1, *(this->_end - j - 1));
				for (size_type k = 0; k < this->size(); k++)
					this->_alloc.destroy(this->_start + k);
				if (this->_start)
					this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_end = new_end;
				this->_capacity = new_capacity_ptr;
			}
			return (iterator(this->_start + pos));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (n == 0)
				return ;
			if (n > this->max_size())
				throw std::length_error("vector::insert");
			size_type pos = &(*position) - this->_start;
			if (size_type(this->_capacity - this->_end) >= n)
			{
				for (size_type i = 0; i < this->size() - pos; i++)
					this->_alloc.construct(this->_end - i + (n - 1), *(this->_end - i - 1));
				this->_end += n;
				while (n)
				{
					this->_alloc.construct(&(*position) + (n - 1), val);
					n--;
				}
			}
			else
			{
				int new_capacity;
				if (this->size() == 0)
					new_capacity = 0;
				else
					new_capacity = this->size() * 2;
				pointer new_start = this->_alloc.allocate(new_capacity);
				pointer new_capacity_ptr = new_start + new_capacity;
				pointer new_end = pointer();
				if (size_type(new_capacity_ptr - new_start) < this->size() + n)
				{
					if (new_start)
						this->_alloc.deallocate(new_start, new_capacity_ptr - new_start);
					new_capacity = this->size() + n;
					new_start = this->_alloc.allocate(new_capacity);
					new_capacity_ptr = new_start + new_capacity;
				}
				new_end = new_start + this->size() + n;
				for (int i = 0; i < (&(*position) - this->_start); i++)
					this->_alloc.construct(new_start + i, *(this->_start + i));
				for (size_type j = 0; j < n; j++)
					this->_alloc.construct(new_start + pos + j, val);
				for (size_type k = 0; k < (this->size() - pos); k++)
					this->_alloc.construct(new_end - k - 1, *(this->_end - k - 1));
				for (size_type l = 0; l < this->size(); l++)
					this->_alloc.destroy(this->_start + l);
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_end = new_end;
				this->_capacity = new_capacity_ptr;
			}
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr)
		{
			size_type n = ft::distance(first, last);
			if (size_type(this->_capacity - this->_end) >= n)
			{
				for (size_type i = 0; i < (this->size() - (&(*position) - this->_start)); i++)
					this->_alloc.construct(this->_end - i + n - 1, *(this->_end - i - 1));
				this->_end += n;
				while (first != last)
				{
					this->_alloc.construct(&(*position), *first);
					first++;
					position++;
				}
			}
			else
			{
				pointer new_start = this->_alloc.allocate(this->size() * 2);
				pointer new_end = new_start + this->size() + n;
				pointer new_capacity = new_start + (this->size() * 2);
				if (size_type(new_capacity - new_start) < this->size() + n)
				{
					if (new_start)
						this->_alloc.deallocate(new_start, new_capacity - new_start);
					new_start = this->_alloc.allocate(this->size() + n);
					new_end = new_start + this->size() + n;
					new_capacity = new_end;
				}
				for (int i = 0; i < &(*position) - this->_start; i++)
					this->_alloc.construct(new_start + i, *(this->_start + i));
				for (int j = 0; first != last; first++, j++)
					this->_alloc.construct(new_start + (&(*position) - this->_start) + j, *first);
				for (size_type k = 0; k < this->size() - (&(*position) - this->_start); k++)
					this->_alloc.construct(new_start + (&(*position) - this->_start) + n + k, *(&(*position) + k));
				for (size_type l = 0; l < this->size(); l++)
					this->_alloc.destroy(this->_start + l);
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_end = new_end;
				this->_capacity = new_capacity;
			}
		}

		iterator erase(iterator position)
		{
			pointer pos = &(*position);
			this->_alloc.destroy(pos);
			if (&(*position) + 1 != this->_end)
			{
				for (int i = 0; i < this->_end - (&(*position) - 1); i++)
				{
					this->_alloc.construct(&(*position) + i, (*(position + i + 1)));
					this->_alloc.destroy(&(*position) + i + 1);
				}
			}
			this->_end--;
			return (iterator(pos));
		}

		iterator erase(iterator first, iterator last)
		{
			pointer firstPos = &(*first);
			while (first != last)
			{
				this->_alloc.destroy(&(*first));
				first++;
			}
			for (int i = 0; i < this->_end - &(*last); i++)
			{
				this->_alloc.construct(firstPos + i, *(&(*last) + i));
				this->_alloc.destroy(&(*last) + i);
			}
			this->_end -= &(*last) - firstPos;
			return (iterator(firstPos));
		}

		void swap(vector &x)
		{
			pointer x_start = x._start;
			pointer x_end = x._end;
			pointer x_capacity = x._capacity;
			allocator_type x_alloc = x._alloc;

			x._start = this->_start;
			x._end = this->_end;
			x._capacity = this->_capacity;
			x._alloc = this->_alloc;

			this->_start = x_start;
			this->_end = x_end;
			this->_capacity = x_capacity;
			this->_alloc = x_alloc;
		}

		void clear(void)
		{
			size_type size = this->size();
			for (size_type i = 0; i < size; i++)
			{
				this->_end--;
				this->_alloc.destroy(this->_end);
			}
		}

		allocator_type get_allocator(void) const
		{
			return (this->_alloc);
		}

	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_capacity;
	};

	template <typename T, typename Allocator> bool operator==(const vector<T, Allocator> &lhs, const vector<T,Allocator> &rhs)
	{
		// Necessary since the != operator is relying on this function
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<T, Allocator>::const_iterator lhsIteratorBegin = lhs.begin();
		typename vector<T, Allocator>::const_iterator rhsIteratorBegin = rhs.begin();
		while (lhsIteratorBegin != lhs.end())
		{
			if (*lhsIteratorBegin != *rhsIteratorBegin || rhsIteratorBegin == rhs.end())
				return (false);
			lhsIteratorBegin++;
			rhsIteratorBegin++;
		}
		return (true);
	}
	
	template <typename T, typename Allocator> bool operator!=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		if (!(lhs == rhs))
			return true;
		return false;
	}
	
	template <typename T, typename Allocator> bool operator<(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template <typename T, typename Allocator> bool operator<=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		if (!(rhs < lhs))
			return true;
		return false;
	}
	
	template <typename T, typename Allocator> bool operator>(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		if (rhs < lhs)
			return true;
		return false;
	}
	
	template <typename T, typename Allocator> bool operator>=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		if (!(lhs < rhs))
			return true;
		return false;
	}
	

	template <class T, class Allocator> void swap(vector<T,Allocator> &x, vector<T,Allocator> &y)
	{
		x.swap(y);
	}

} // end of ft namespace

#endif