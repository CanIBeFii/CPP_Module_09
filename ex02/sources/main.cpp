#include "../includes/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if ( argc == 1 ) {
		std::cout << "Error: not given any number" << std::endl;
		return ( 1 );
	}


	try {
		PmergeMe	pmergeMe;
		for ( int i = 1; i < argc; i++ ) {
			pmergeMe.addVector( std::atoi( argv[i] ) );
			pmergeMe.addList( std::atoi( argv[i] ) );
			std::cout << "Added: " << argv[i] << std::endl;
		}

		pmergeMe.sort( argc );

	} catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}