#ifndef MULTISTACK_HPP
# define MULTISTACK_HPP
/*

std::stack is a container adaptor
it uses another container internally (default = std::deque<T>)
it hides all operations except:
push()
pop()
top()
empty()
size()


std::stack<T> internally has:
protected:
    Container c;

If the underlying container is (by default) std::deque<T>, then:
c.begin()  
c.end() 
are valin iterators
*/

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	//OCF
	MutantStack() : std::stack<T>(){}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    MutantStack& operator=(const MutantStack& other){
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
	}
	~MutantStack(){};


	//iterators

	// These typedefs do not contain functionality — they only describe types.
	// to expose the iterator type of the underlying container 
	// (stack doesnt have ters, but its based on deque, which has them)
	typedef typename std::stack<T>::container_type::iterator iterator;


	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}
};

#endif