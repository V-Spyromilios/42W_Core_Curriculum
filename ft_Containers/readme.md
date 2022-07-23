# **Summary:**
_The standard C++ containers have all a specific usage.
To make sure you understand them, let’s re-implement them!_
***

# **General rules**

## _Compiling_

• Compile your code with c++ and the flags `-Wall -Wextra -Werror`

• Your code should still compile if you add the flag `-std=c++98`

## _Formatting and naming conventions_

• For each container, turn in the appropriately named class files.

## _Allowed/ Forbidden_

• You are allowed to use everything from the standard library. Thus, instead of
sticking to what you already know, it would be smart to use as much as possible
the C++-ish versions of the C functions you are used to.

• However, you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: `*printf()`, `*alloc()` and `free()`. If you use them, your grade will be 0 and
that’s it.

## _A few design requirements_

• Memory leakage occurs in C++ too. When you allocate memory, you must avoid
memory leaks.

• Any function implementation put in a header file (except for function templates)
means 0 to the exercise.

• You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0.

# **Mandatory part**
Implement the following containers and turn in the necessary `<container>.hpp` files:

## • vector
You don’t have to do the vector<bool> specialization.

## • map
## • stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.

## _You also have to implement:_
• `iterators_traits`

• `reverse_iterator`

• `enable_if`

Yes, it is C++11 but you will be able to implement it in a C++98 manner. This is asked so you can discover SFINAE.

• `is_integral`

• equal and/or lexicographical_compare

• `std::pair`

• `std::make_pair`

# **Requirements**

The namespace must be `ft`

Each inner data structure used in your containers must be logical and justified (this
means using a simple array for map is not ok).

You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function or
variable must be justified.

All the member functions, non-member functions and overloads of the standard
containers are expected.

You must follow the original naming. Take care of details.

If the container has an iterator system, you must implement it.

You must use `std::allocator`.

For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.

Of course, for the implementation of `map::value_compare`, the keyword friend is
allowed.


# **Testing**

You must also provide tests, at least a main.cpp, for your defense. You have to go
further than the main given as example!

You must produce two binaries that run the same tests: one with your containers
only, and the other one with the `STL containers`.

Compare outputs and performance / timing (your containers can be up to 20
times slower).

Test your containers with: `ft::<container>`.
