#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange {
	public:
		// Constructor
		BitcoinExchange( void );
		BitcoinExchange( std::string& filename );
		BitcoinExchange( const BitcoinExchange& copy );

		// Destructor
		~BitcoinExchange( void );

		// Operator
		BitcoinExchange& operator=( const BitcoinExchange& copy );

		// Methods
		void	addData( std::string& filename );
		void	readFile( std::string& filename );
		int		checkInput( std::string& input );

	private:
		std::map<std::string, double> _data;
};

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif
