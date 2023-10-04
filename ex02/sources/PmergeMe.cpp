#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <iterator>

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
void	PmergeMe::addVector( int value ) {
	if ( std::find( _vector.begin(), _vector.end(), value ) != _vector.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_vector.push_back( value );
}

void	PmergeMe::addList( int value ) {
	if ( std::find( _list.begin(), _list.end(), value ) != _list.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_list.push_back( value );
}

void	PmergeMe::sort( int argc ) {
	std::cout << "Before: " << std::for_each(_vector.begin(), --_vector.end(), print<int>) << std::endl;

	// Vector
	_vectorTime = clock();
	mergeInsertSortVector( 0, _vector.size() - 1,  _vector.size() );
	_vectorTime = clock() - _vectorTime;
	argc++;
	// // List
	_listTime = clock();
	// _list.sort();
	_listTime = clock() - _listTime;

	std::cout << "After: " << std::for_each(_vector.begin(), --_vector.end(), print<int>) << std::endl;

}


// Vector

void	PmergeMe::mergeInsertSortVector( int left, int right, int size ) {
	if ( right - left + 1 < size ) {
		insertSortVector( left, right );
	} else if ( left < right ) {
		int middle = left + ( right - left ) / 2;
		mergeInsertSortVector( left, middle, size );
		mergeInsertSortVector( middle + 1, right, size );
		mergeVector( left, middle, right );
	}
}

void	PmergeMe::insertSortVector( int left, int right ) {
	int i, j;

	for ( i = left + 1; i <= right; i++ ) {
		int key = _vector[i];
		for ( j = i - 1; j >= left && _vector[j] > key; j-- ) {
			_vector[j + 1] = _vector[j];
		}
		_vector[j + 1] = key;
	}
}

void	PmergeMe::mergeVector( int left, int middle, int right ) {
	int num1 = middle - left + 1;
	int num2 = right - middle;

	std::vector<int> leftVector( num1 ), rightVector( num2 );

	for ( int i = 0; i < num1; i++ ) {
		leftVector[i] = _vector[left + i];
	}

	for ( int j = 0; j < num2; j++ ) {
		rightVector[j] = _vector[middle + 1 + j];
	}

	int i = 0;
	int j = 0;
	int key = left;

	while ( i < num1 && j < num2 ) {
		if ( leftVector[i] <= rightVector[j] ) {
			_vector[key] = leftVector[i];
			i++;
		}
		else {
			_vector[key] = rightVector[j];
			j++;
		}
		key++;
	}

	while ( i < num1 ) {
		_vector[key] = leftVector[i];
		i++;
		key++;
	}

	while ( j < num2 ) {
		_vector[key] = rightVector[j];
		j++;
		key++;
	}
}