#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

enum typeRPN {
	SPACE,
	NUM,
	ADD,
	SUB,
	MULT,
	DIV,
	NONE
};


class RPN {
	public:
		// Constructor
		RPN( void );
		RPN( const RPN& copy );

		// Destructor
		~RPN( void );

		// Operator
		RPN&	operator=( const RPN& copy );

		// Methods
		typeRPN	getTypeRPN( char c );
		void	doOperation( typeRPN operation );
		void	calculate( std::string& input );

	private:
		std::stack<int>	_stack;
};

#endif
