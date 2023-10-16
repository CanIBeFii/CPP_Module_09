#include "../includes/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if ( argc == 1 ) {
		std::cout << "Error: not given any number" << std::endl;
		return ( 1 );
	}

	try {
		PmergeMe	pmergeMe;

		for ( int i = 1; i < argc; i++ ) {
			pmergeMe.addToDeque( std::atoi( argv[i] ) );
			pmergeMe.addToList( std::atoi( argv[i] ) );
		}

		pmergeMe.sort();

	} catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}