#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <ctime>
#include <list>
#include <vector>
#include <stdexcept>

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

		void		mergeInsertSort( void );


	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		clock_t				_vectorTime;
		clock_t				_listTime;	
};



#endif