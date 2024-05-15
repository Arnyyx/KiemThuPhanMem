/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <fstream>

int
main () {
	int a, b, c, match;
	char kq[50];

	std::ifstream inputFile("input.txt"); // Open the input file
	if (!inputFile.is_open()) { // Check if the file is opened successfully
		std::cerr << "Unable to open the input file!\n";
		return 1;
	}
	if (!(inputFile >> a >> b >> c)) { // Read the three integers from the file
		std::cerr << "Error reading input from file!\n";
		return 1;
	}

	std::ofstream outputFile("output.txt"); // M? file d?u ra
	if (!outputFile.is_open()) { // Ki?m tra xem file có du?c m? thành công không
		std::cerr << "Không th? m? file d?u ra!\n";
		return 1;
	}
	match = 0;
	if (a == b)
		match = match + 1;
	if (a == c)
		match = match + 2;
	if (b == c)
		match = match + 3;
	if (match == 0)
		if ((a + b) <= c)
//	  kq = "Not a Triangle";
			outputFile << "Khong phai tam giac" << std::endl;
		else if ((b + c) <= a)
			outputFile << "Khong phai tam giac" << std::endl;
		else if ((a + c) <= b)
			outputFile << "Khong phai tam giac" << std::endl;

		else
			outputFile << "La tam giac" << std::endl;

	else if (match == 1)
		if ((a + b) <= c)
			outputFile << "Khong phai tam giac" << std::endl;
		else
			outputFile << "Tam giac can" << std::endl;
	else if (match == 2)
		if ((a + c) <= b)
			outputFile << "Khong phai tam giac" << std::endl;
		else
			outputFile << "Tam giac can" << std::endl;
	else if (match == 3)
		if ((b + c) <= a)
			outputFile << "Khong phai tam giac" << std::endl;
		else
			outputFile << "Tam giac can" << std::endl;
	else
		outputFile << "Tam giac deu" << std::endl;

	inputFile.close();
	outputFile.close();
	return 0;
}

