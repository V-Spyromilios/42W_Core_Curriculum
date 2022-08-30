#ifdef STD
# include <map>
# include <vector>
# include <stack>
namespace ft = std;
#else
# include "ft_vector.hpp"
# include "ft_stack.hpp"
# include "ft_map.hpp"
#endif

#include <iostream>
#include <list>
#include <deque>

int main(void)
{
	{
		std::cout << "#######################################################" << std::endl;
		std::cout << "#------------------------ MAP ------------------------#" << std::endl;
	#ifdef STD
		std::cout << "#------------------------ STL ------------------------#" << std::endl;
	#else
		std::cout << "#------------------------ FT  ------------------------#" << std::endl;
	#endif
		std::cout << "#######################################################" << std::endl << std::endl;
		ft::map<int, std::string> mp;

		mp[0] = "This";
		mp[1] = "is";
		mp[2] = "an";
		mp[3] = "entry";

		std::cout << "Insertion and printing using operator[]" << std::endl;
		std::cout << " - " << mp[0] << std::endl;
		std::cout << " - " << mp[1] << std::endl;
		std::cout << " - " << mp[2] << std::endl;
		std::cout << " - " << mp[3] << std::endl;

		std::cout << "Printing using iterators (from begin to end)" << std::endl;
		ft::map<int, std::string>::iterator it = mp.begin();
		for (; it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;

		std::cout << "Printing using iterators (from end to begin)" << std::endl;
		it = --(mp.end());
		for (; it != mp.begin(); it--)
			std::cout << " - " << it->second << std::endl;
		std::cout << " - " << it->second << std::endl;

		std::cout << "Printing from a new map after copying" << std::endl;
		ft::map<int, std::string> mp2 = mp;
		it = mp2.begin();
		for (; it != mp2.end(); it++)
			std::cout << " - " << it->second << std::endl;
		
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.erase(3);
		std::cout << "After removing the last element using key" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.erase(mp.begin());
		std::cout << "After removing first element using iterator" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.erase(mp.begin(), mp.end());
		std::cout << "After removing all remaining elements" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.insert(mp2.begin(), mp2.end());
		std::cout << "After inserting range from copied Map" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.insert(ft::make_pair(8, "borgor"));
		std::cout << "After inserting with key 8" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		mp.insert(ft::make_pair(6, "duck"));
		std::cout << "After inserting with key 6" << std::endl;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Map size" << std::endl;
		std::cout << " - " << mp.size() << std::endl;
		std::cout << "Is Map empty" << std::endl;
		std::cout << " - " << mp.empty() << std::endl;
		it = mp.find(6);
		std::cout << "Using 'find' to get element with key 6" << std::endl;
		std::cout << " - " << it->second << std::endl;
		it = mp.find(2);
		std::cout << "Using 'find' to get element with key 2" << std::endl;
		std::cout << " - " << it->second << std::endl;
		it = mp.lower_bound(3);
		std::cout << "Lower bound of key 3" << std::endl;
		std::cout << " - " << it->second << std::endl;
		it = mp.upper_bound(3);
		std::cout << "Upper bound of key 3" << std::endl;
		std::cout << " - " << it->second << std::endl;
		std::cout << "Traversing with reverse iterator" << std::endl;
		ft::map<int, std::string>::reverse_iterator rit = mp.rbegin();
		for (; rit != mp.rend(); rit++)
			std::cout << " - " << rit->second << std::endl;
		std::cout << "Removing element with key 3, and then checking if previously\ncreated iterator begin() is still valid" << std::endl;
		it = mp.begin();
		mp.erase(3);
		for (; it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		it = mp.begin();
		std::cout << "comparing iterator to begin (should be the same)" << std::endl;
		std::cout << " - it == begin: " << (it == mp.begin()) << std::endl;
		std::cout << " - it == begin: " << (it != mp.begin()) << std::endl;
		it++;
		std::cout << "comparing iterator to begin (should be different)" << std::endl;
		std::cout << " - it == begin: " << (it == mp.begin()) << std::endl;
		std::cout << " - it == begin: " << (it != mp.begin()) << std::endl;
		std::cout << "Checking behavior of ft::make_pair" << std::endl;
		ft::pair<std::string, std::string> p = ft::make_pair("forg", "phroge");
		std::cout << " - First: " << p.first << std::endl;
		std::cout << " - Second: " << p.second << std::endl;
		std:: cout << "Trying to add element with existing key (6)" << std::endl;
		mp.insert(ft::make_pair(6, "handborgor"));
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		ft::map<int, std::string> new_mp;
		new_mp.insert(ft::make_pair(1, "I"));
		new_mp.insert(ft::make_pair(2, "hate"));
		new_mp.insert(ft::make_pair(3, "containers"));
		new_mp.insert(ft::make_pair(4, "(for life)"));
		std::cout << "Newly created map" << std::endl;
		for (it = new_mp.begin(); it != new_mp.end(); it++)
			std::cout << " - " << it->second << std::endl;
		std::cout << "Swapping maps and making sure that previously declared iterators are valid" << std::endl;
		it = new_mp.begin();
		ft::map<int, std::string>::iterator it2 = mp.begin();
		mp.swap(new_mp);
		std::cout << " - old mp.begin == curent new_mp.begin: " << (it2 == new_mp.begin()) << std::endl;
		std::cout << " - old new_mp.begin == curent mp.begin: " << (it == mp.begin()) << std::endl;
		std::cout << "Max_size function (calls max_size of\ncontainers std::allocator)" << std::endl;
		std::cout << " - " << mp.max_size() << std::endl << std::endl;
	}
	{
		std::cout << "#######################################################" << std::endl;
		std::cout << "#----------------------- VECTOR ----------------------#" << std::endl;
	#ifdef STD
		std::cout << "#------------------------ STL ------------------------#" << std::endl;
	#else
		std::cout << "#------------------------ FT  ------------------------#" << std::endl;
	#endif
		std::cout << "#######################################################" << std::endl << std::endl;
		ft::vector<std::string> vec;
		vec.push_back("Ronaldo");
		vec.push_back("Messi");
		vec.push_back("Rooney");
		vec.push_back("Reus");
		vec.push_back("Adeyemi");
		vec.insert(vec.begin() + 5, "Inserttest");
		std::cout << "Creating vector, pushing some elements and\niterating with iterator" << std::endl;
		ft::vector<std::string>::iterator it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Iterating again but this time with const iterator" << std::endl;
		std::cout << "Printing third element using begin + 2" << std::endl;
		std::cout << " - " << *(it + 2) << std::endl;
		std::cout << "Printing third element using operator[]" << std::endl;
		std::cout << " - " << it[2] << std::endl;
		std::cout << "Iterating with reverse_iterators" << std::endl;
		ft::vector<std::string>::reverse_iterator rit = vec.rbegin();
		for (; rit != vec.rend(); rit++)
			std::cout << " - " << *rit << std::endl;
		std::cout << "Comparing reverse iterator with const_reverse_iterator\n(should be different)" << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "Vector after pushing 3 new objects" << std::endl;
		vec.push_back("Pogba");
		vec.push_back("Matuidi");
		vec.push_back("Griezmann");
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "After pushing another object" << std::endl;
		vec.push_back("BVB");
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "After popping the last object" << std::endl;
		vec.pop_back();
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "After resizing to 8" << std::endl;
		vec.resize(8);
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "After resizing to 32" << std::endl;
		vec.resize(32);
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		ft::vector<std::string> v(8, "42");
		vec.assign(v.begin(), v.end());
		std::cout << "Vector after using assign to change contents" << std::endl;
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "After resizing to 4" << std::endl;
		vec.resize(4);
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "Changing first and last element of vector using operator[]" << std::endl;
		vec[0] = "PSG";
		vec[3] = "ManU";
		it = vec.begin();
		for (; it != vec.end(); it++)
			std::cout << " - " << *it << std::endl;
		std::cout << "Vector size" << std::endl;
		std::cout << " - " << vec.size() << std::endl;
		std::cout << "Vector capacity" << std::endl;
		std::cout << " - " << vec.capacity() << std::endl;
		std::cout << "Vector max_size" << std::endl;
		std::cout << " - " << vec.max_size() << std::endl;
		std::cout << "Return value of front()" << std::endl;
		std::cout << " - " << vec.front() << std::endl;
		std::cout << "Return value of back()" << std::endl;
		std::cout << " - " << vec.back() << std::endl;
		std::cout << "Capacity after using reserve(42)" << std::endl;
		vec.reserve(42);
		std::cout << " - " << vec.capacity() << std::endl;
		ft::vector<std::string> ve = vec;
		ve[0] = "Ferencvaros";
		ve[2] = "Budapest";
		std::cout << "New vector" << std::endl;
		it = ve.begin();
		for (; it != ve.end(); it++)
			std::cout << " - " << *it << std::endl;
		it = vec.begin();
		vec.swap(ve);
		std::cout << "New vector after swapping with old vector\niterated with old iterator to make sure its valid" << std::endl;
		for (; it != ve.end(); it++)
			std::cout << " - " << *it << std::endl << std::endl;
	}
	{
		std::cout << "#######################################################" << std::endl;
		std::cout << "#----------------------- STACK -----------------------#" << std::endl;
	#ifdef STD
		std::cout << "#------------------------ STL ------------------------#" << std::endl;
	#else
		std::cout << "#------------------------ FT  ------------------------#" << std::endl;
	#endif
		std::cout << "#######################################################" << std::endl << std::endl;

		ft::stack<int> vst;
		std::cout << "Is new stack empty:" << std::endl;
		std::cout << " - " << vst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << vst.size() << std::endl;
		vst.push(21);
		vst.push(123);
		vst.push(42);
		std::cout << "Top after pushing some elements:" << std::endl;
		std::cout << " - " << vst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << vst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << vst.size() << std::endl;
		vst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << vst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << vst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << vst.size() << std::endl;
		vst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << vst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << vst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << vst.size() << std::endl;
		vst.pop();
		std::cout << "Size after popping last element:" << std::endl;
		std::cout << " - " << vst.size() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << vst.empty() << std::endl << std::endl;;
		ft::stack<int, std::list<int> > lst;
		std::cout << "Stack using std::list as underlying container" << std::endl;
		std::cout << "Is new stack empty:" << std::endl;
		std::cout << " - " << lst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << lst.size() << std::endl;
		lst.push(1);
		lst.push(2);
		lst.push(3);
		std::cout << "Top after pushing some elements:" << std::endl;
		std::cout << " - " << lst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << lst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << lst.size() << std::endl;
		lst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << lst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << lst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << lst.size() << std::endl;
		lst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << lst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << lst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << lst.size() << std::endl;
		lst.pop();
		std::cout << "Size after popping last element:" << std::endl;
		std::cout << " - " << lst.size() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << lst.empty() << std::endl << std::endl;
		ft::stack<int, std::deque<int> > dst;
		std::cout << "Stack using std::deque as underlying container" << std::endl;
		std::cout << "Is new stack empty:" << std::endl;
		std::cout << " - " << dst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << dst.size() << std::endl;
		dst.push(1);
		dst.push(2);
		dst.push(3);
		std::cout << "Top after pushing some elements:" << std::endl;
		std::cout << " - " << dst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << dst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << dst.size() << std::endl;
		dst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << dst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << dst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << dst.size() << std::endl;
		dst.pop();
		std::cout << "Top after popping an element:" << std::endl;
		std::cout << " - " << dst.top() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << dst.empty() << std::endl;
		std::cout << "Stack size:" << std::endl;
		std::cout << " - " << dst.size() << std::endl;
		dst.pop();
		std::cout << "Size after popping last element:" << std::endl;
		std::cout << " - " << dst.size() << std::endl;
		std::cout << "Is stack empty:" << std::endl;
		std::cout << " - " << dst.empty() << std::endl << std::endl;
	}
}