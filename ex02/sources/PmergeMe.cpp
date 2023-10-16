#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <ctime>
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
		_list = copy._list;
		_sortedList = copy._sortedList;
		_deque = copy._deque;
		_sortedDeque = copy._sortedDeque;
	}
	return ( *this );
}

// Methods
void	PmergeMe::addToList( int value ) {
	if ( std::find( _list.begin(), _list.end(), value ) != _list.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_list.push_back( value );
}

void	PmergeMe::addToDeque( int value ) {
	if ( std::find( _deque.begin(), _deque.end(), value ) != _deque.end() )
		throw std::runtime_error( "Error: given duplicate value" );
	_deque.push_back( value );
}

void	PmergeMe::sort( void ) {

	std::cout << "Before: ";
	for ( listIter iter = _list.begin() ; iter != _list.end() ; ++iter )
		std::cout << *iter << " ";
	std::cout << std::endl;

	// list 
	_listTime = clock();
	mergeInsertSortList();
	_listTime = clock() - _listTime;

	// Deque
	_dequeTime = clock();
	mergeInsertSortDeque();
	_dequeTime = clock() - _dequeTime;

	std::cout << "After: ";
	for ( listIter iter = _sortedList.begin() ; iter != _sortedList.end() ; ++iter )
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : ";
	std::cout << (double)( (double)_listTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
	std::cout << (double)( (double)_dequeTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;
}

void	PmergeMe::mergeInsertSortList( void ) {
	listIter	iter = _list.begin();

	if ( _list.size() == 1 ) {
		_sortedList.push_front( *iter );
		return ;
	}

	for ( ; iter != _list.end() ; ) {
		int	key = *iter;
		++iter;

		if ( iter != _list.end() ) {
			if ( *iter > key )
				_listPair.push_back( std::make_pair( key, *iter ) );
			else
			 	_listPair.push_back( std::make_pair( *iter, key ) );
			++iter;
		}
		else {
			_sortedList.push_back( key );
		}
	}

	insertList();
}

void	PmergeMe::insertList( void ) {
	std::list< std::pair<int, int> >::iterator	iter = _listPair.begin();

	if ( _sortedList.empty() ) {
		_sortedList.push_back( iter->first );
		_sortedList.push_back( iter->second );
		++iter;
	}

	for ( ; iter != _listPair.end() ; ++iter ) {
		listIter iter2 = _sortedList.begin();

		while ( iter2 != _sortedList.end() && *iter2 < iter->first )
			++iter2;
	
		_sortedList.insert( iter2, iter->first );

		iter2 = _sortedList.begin();
		while ( iter2 != _sortedList.end() && *iter2 < iter->second )
			++iter2;

		_sortedList.insert( iter2, iter->second );
	}
}

void	PmergeMe::mergeInsertSortDeque( void ) {
	dequeIter iter = _deque.begin();

	if ( _deque.size() == 1 ) {
		_sortedDeque.push_front( *iter );
		return ;
	}

	for ( ; iter != _deque.end() ; ) {
		int	key = *iter;
		++iter;

		if ( iter != _deque.end() ) {
			if ( *iter > key ) {
				_sortedDeque.push_back( *iter );
				_sortedDeque.push_front( key );
			}
			else {
				_sortedDeque.push_back( key );
				_sortedDeque.push_front( *iter );
			}
			++iter;
		}
		else 
			_sortedDeque.push_back( key );
	}
	_deque.clear();
	insertDeque();
}

void	PmergeMe::insertDeque( void ) {
	if ( _sortedDeque.size() % 2 != 0 ) {
		_deque.push_front( _sortedDeque.back() );
		_sortedDeque.pop_back();
	}
	else {
		_deque.push_back( _sortedDeque.back() );
		_deque.push_front( _sortedDeque.front() );
		_sortedDeque.pop_front();
		_sortedDeque.pop_back();
	}

	while ( _sortedDeque.size() > 0 ) {
		dequeIter iter = _deque.begin();

		while ( iter != _deque.end() && *iter < _sortedDeque.front() )
			++iter;

		_deque.insert( iter, _sortedDeque.front() );
		_sortedDeque.pop_front();

		while ( iter != _deque.end() && *iter < _sortedDeque.back() )
			++iter;
		
		_deque.insert( iter, _sortedDeque.back() );
		_sortedDeque.pop_back();
	}
}