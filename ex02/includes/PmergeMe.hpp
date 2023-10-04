#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <ctime>
#include <list>
#include <vector>
#include <stdexcept>
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
		void		addVector( int value );
		void		addList( int value );

		typedef std::vector<int>::iterator vecIter;
		typedef std::list<int>::iterator listIter;

		void		sort( int argc );

		// Vector
		void		mergeInserSortVector( vecIter left, vecIter right );
		void		mergeInsertSortVector( int left, int right, int size );
		void		insertSortVector( int left, int right );
		void		mergeVector( int left, int middle, int right );


	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		clock_t				_vectorTime;
		clock_t				_listTime;	
};

template <typename T>
void	print( T& num ) {
	std::cout << num << " ";
}

#endif