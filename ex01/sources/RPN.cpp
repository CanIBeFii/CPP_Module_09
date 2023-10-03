#include "../includes/RPN.hpp"
#include <cctype>
#include <cstddef>
#include <cstring>
#include <stdexcept>

RPN::RPN( void ) {}

RPN::RPN( const RPN& copy ) : _stack( copy._stack ) {}

RPN::~RPN( void ) {}

RPN&	RPN::operator=( const RPN& copy ) {
	if ( this != &copy ) {
		_stack = copy._stack;
	}
	return ( *this );
}

typeRPN	RPN::getTypeRPN( char c ) {
	if ( std::isdigit( c ) ) {
		return ( NUM );
	}
	else if ( c == ' ' ) {
		return ( SPACE );
	}
	else if ( c == '+' ) {
		return ( ADD );
	}
	else if ( c == '-' ) {
		return ( SUB );
	}
	else if ( c == '*' ) {
		return ( MULT );
	}
	else if ( c == '/' ) {
		return ( DIV );
	}
	return ( NONE );
}

void	RPN::doOperation( typeRPN operation ) {
	int	num1, num2;

	num2 = _stack.top();
	_stack.pop();

	num1 = _stack.top();
	_stack.pop();

	switch ( operation ) {
		case ADD:
			_stack.push( num1 + num2 );
			break;

		case SUB:
			_stack.push( num1 - num2 );
			break;
		
		case MULT:
			_stack.push( num1 * num2 );
			break;

		case DIV:
			_stack.push( num1 / num2 );
			break;

		default:
			break;
	}
}

void	RPN::calculate( std::string& input ) {
	typeRPN t;
	for ( size_t i = 0; i < input.size(); i++ ) {
		t = getTypeRPN( input[i] );
		switch ( t ) {
			case SPACE:
				break;
			
			case NUM:
				_stack.push(input[i] - '0' );
				break;

			case ADD:
				if ( _stack.size() < 2 )
					throw std::runtime_error( "Error: not enough numbers to make operation." );
				doOperation( t );
				break;

			case SUB:
				if ( _stack.size() < 2 )
					throw std::runtime_error( "Error: not enough numbers to make operation." );
				doOperation( t );
				break;

			case MULT:
				if ( _stack.size() < 2 )
					throw std::runtime_error( "Error: not enough numbers to make operation." );
				doOperation( t );
				break;

			case DIV:
				if ( _stack.size() < 2 )
					throw std::runtime_error( "Error: not enough numbers to make operation." );
				doOperation( t );
				break;

			case NONE:
				throw std::runtime_error( "Error: found unknown operator/number." );
				break;
		}
	}

	if ( _stack.size() != 1 )
		throw std::runtime_error( "Error: wrong number of operations given.");

	std::cout << _stack.top() << std::endl;
}
