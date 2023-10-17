#include "../includes/RPN.hpp"
#include <cstring>
#include <stdexcept>
#include <string>

int	main( int argc, char **argv ) {
	if ( argc != 2 ) {
		std::cout << "Error: No input given" << std::endl;
		return ( 1 );
	}

	RPN	calculator;
	std::string input( argv[1] );

	try {
		calculator.calculate( input );

	} catch( std::runtime_error& e ) {
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}