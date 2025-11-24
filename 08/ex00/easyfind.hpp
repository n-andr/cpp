#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

/*
Iterators are:
- “pointer-like” objects
- sometimes actual pointers
- sometimes custom classes
- always accessed with *it, ++it, and comparisons
They allow algorithms like std::find to work with any container, even if the internal structure is completely different.
*/

template <typename T>
typename T::iterator easyfind(T &container, int findMe){
	typename T::iterator it = std::find(container.begin(), container.end(), findMe);

	if (it == container.end())	throw std::runtime_error ("Value not found");
	else return it;
}

#endif