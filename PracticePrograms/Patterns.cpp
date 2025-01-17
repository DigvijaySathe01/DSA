#include "Patterns.h"
#include <iostream>

//-----------------------------------------------------------------------------

void Patterns::Pattern1()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;
	int numCols = 0;
	std::cout << "Enter number of columns\n";
	std::cin >> numCols;

	for (int iRow = 0 ; iRow < numRows; ++iRow)
	{
		for (int iColumn= 0; iColumn< numCols; ++iColumn)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern2()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;
	int numCols = 0;
	std::cout << "Enter number of columns\n";
	std::cin >> numCols;

	for (int iRow = 1; iRow <= numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < numCols; ++iColumn)
		{
			std::cout << iRow <<" ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern3()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;
	int numCols = 0;
	std::cout << "Enter number of columns\n";
	std::cin >> numCols;

	for (int iRow = 0; iRow < numRows; ++iRow)
	{
		for (int iColumn = 1; iColumn <= numCols; ++iColumn)
		{
			std::cout << iColumn << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern4()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;
	int numCols = 0;
	std::cout << "Enter number of columns\n";
	std::cin >> numCols;

	for (int iRow = 0; iRow < numRows; ++iRow)
	{
		for (int iColumn = numCols; iColumn >= 1; --iColumn)
		{
			std::cout << iColumn << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern5()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;
	int numCols = 0;
	std::cout << "Enter number of columns\n";
	std::cin >> numCols;
	int count = 1;

	for (int iRow = 0; iRow < numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < numCols; ++iColumn)
		{
			std::cout << count++ << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern6()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;

	for (int iRow = 1; iRow <= numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < iRow; ++iColumn)
		{
			std::cout <<"*";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::Pattern7()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;

	for (int iRow = 1; iRow <= numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < iRow; ++iColumn)
		{
			std::cout << iRow;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

void Patterns::PatternXX()
{
	int numRows = 0;
	std::cout << "Enter number of rows\n";
	std::cin >> numRows;

	for (int iRow = numRows; iRow >= 1; --iRow)
	{
		for (int iColumn = 1; iColumn <= iRow; ++iColumn)
		{
			std::cout << iColumn;
		}
		for (int iColumn = iRow; iColumn < numRows; ++iColumn)
		{
			std::cout << "*";
		}
		for (int iColumn = numRows; iColumn > iRow; --iColumn)
		{
			std::cout << "*";
		}
		for (int iColumn = iRow; iColumn >= 1; --iColumn)
		{
			std::cout << iColumn;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

