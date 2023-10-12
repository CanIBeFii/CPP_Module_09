#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <list>
#include <iterator>

class PmergeMe {
	public:
		// Constructor
		PmergeMe( void );
		PmergeMe( const PmergeMe& copy );

		// Destructor
		~PmergeMe( void );

		// Operators
		PmergeMe&	operator=( const PmergeMe& copy );

		// Methods
		void		addToList( int value );
		void		addToDeque( int value );

		typedef std::list<int>::iterator listIter;
		typedef std::deque<int>::iterator dequeIter;

		void		sort( void );

		// Vector
		void		mergeInsertSortList( void );
		void		insertList( void );

		void		mergeInsertSortDeque( void );
		void		insertDeque( void );

	private:
		std::list<int>						_list;
		std::list<int>						_sortedList;
		std::list< std::pair<int, int> >	_listPair;

		std::deque<int>						_deque;
		std::deque<int>						_sortedDeque;

		clock_t								_listTime;
		clock_t								_dequeTime;	
};

template <typename T>
void	print( T& num ) {
	std::cout << num << " ";
}

#endif