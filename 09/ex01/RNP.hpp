#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class RPN
{
private:
    // Disallow copy/assignment
	    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

public:


    // Main function
    static double calculate(const std::string& input);
};

#endif
