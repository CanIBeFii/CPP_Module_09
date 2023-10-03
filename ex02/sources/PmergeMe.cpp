#include "../includes/PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe& copy ) {
	*this = copy;
}

// Destructor
PmergeMe::~PmergeMe( void ) {}

// Operators
PmergeMe&	PmergeMe::operator=( const PmergeMe& copy ) {
	if ( this != &copy ) {
		_vector = copy._vector;
		_list = copy._list;
	}
	return ( *this );
}

// Methods
void		PmergeMe::addVector( int value ) {
	if ( std::find( _vector.begin(), _vector.end(), value ) != _vector.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_vector.push_back( value );
}

void		PmergeMe::addList( int value ) {
	if ( std::find( _list.begin(), _list.end(), value ) != _list.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_list.push_back( value );
}

void	PmergeMe::mergeInsertSort( void ) {
	
}