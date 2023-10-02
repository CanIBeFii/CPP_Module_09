#include "BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

// Constructor
BitcoinExchange::BitcoinExchange( void ) : _data( std::map<std::string, double>() ) {
	std::cout << BOLDCYAN << "BitcoinExchange: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

BitcoinExchange::BitcoinExchange( std::string& filename ) {
	std::cout << BOLDCYAN << "BitcoinExchange: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	this->addData( filename );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) {
	std::cout << BOLDCYAN << "BitcoinExchange: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	*this = copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange( void ) {
	std::cout << BOLDCYAN << "BitcoinExchange: " << RESET;
	std::cout << BOLDRED << "Destructor " << RESET;
	std::cout << "called" << std::endl;
}

// Operator
BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& copy ) {
	std::cout << BOLDCYAN << "BitcoinExchange: " << RESET;
	std::cout << BOLDYELLOW << "Assignation " << RESET;
	std::cout << "called" << std::endl;

	if ( this != &copy ) {
		this->_data = copy._data;
	}
	return ( *this );
}

// Methods
void	BitcoinExchange::addData( std::string& filename ) {
	std::ifstream	file( filename );

	if ( !file.is_open() ) {
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}

	std::string		line;
	std::getline( file, line );
	while ( std::getline( file, line ) ) {
		std::string date = line.substr( 0, line.find( ',' ) );
		std::string price = line.substr( line.find( ',' + 1 ) );

		_data.insert( std::pair<std::string, double>( date, std::stod( price ) ) );
	}
	file.close();
}

void	BitcoinExchange::readFile( std::string& filename ) {
	std::ifstream	file( filename );

	if ( !file.is_open() ) {
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}

	std::string		line;
	std::getline( file, line );
	while ( std::getline( file, line ) ) {
		std::string date = line.substr( 0, line.find( '|'))
	}
	file.close();
}

int		BitcoinExchange::checkInput( std::string& input ) {
	std::string check;

	if ( input.find( '|' ) == std::string::npos ) {
		throw std::runtime_error( "Error: bad input => " + input );
	}

	check = input.substr( 0, input.find( '|' ) );
	if ( std::stod( check.substr( 5, 2 ) ) > 12 ) {
		throw std::runtime_error( "Error: invalid input: month bigger than 12." );
	}

	check = input.substr( 8, 2 );
	if ( std::stod( check ) > 31 ) {
		throw std::runtime_error( "Error: invalid input: day bigger than 31." );
	}
}