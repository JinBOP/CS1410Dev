#include <iostream>
#include <iomanip>
#include <fstream>	// FileStream Library
using namespace std;

int main()
{
	/* File Streams:
	* Streams: the direction information is flowing in a program
	*	Input Stream: info flows into the program 
	*	Output Stream: info flows out of the program
	* Predefined Streams:
	*	cin (Standard Input)
	*	cout (Standard Output)
	*	cerr (Standard error Output)
	*	clog (Buffered version of cerr)
	* 
	* File I/O:
	*	3 Classes: ifstream (input), ofstream (output), fstream (input/output)
	*	File Types: 
	*		Text (.txt, .csv, .cpp, .java, .html, .jsv, etc) oppened with text editor
	*		Binary (.exe, .png, .zip, .mp3) everything else oppened by special programs
	*	File Access:
	*		Sequential Access: must access files in order (1, 2, 3, 4, 5)
	*		Random Access: can access files out of order (5, 3, 1, 3, 2)
	*/

	// IOS Flags
	cout.setf(ios::showpos);	// modifies cout to show positive sign
	cout.setf(ios::showpoint);	// modifies cout to show decimal point
	cout << 1234.0 << endl;

	cout.unsetf(ios::showpos);		// modifies cout to drop positive sign
	cout.unsetf(ios::showpoint);	// modifies cout to drop decimal point
	cout << 1234.0 << endl << endl;

	double a = 3.1415926534;
	double b = 2006.0;
	cout << "default:" << endl << a << endl << b << endl << endl;
	cout.precision(3);	// shows the set number of digits
	cout << "precision:" << endl << a << endl << b << endl << endl;
	cout << "fixed:" << std::fixed << endl;	// always shows the precision number of decimal points
	cout << a << endl << b << endl << endl;

	cout.setf(ios::left);
	cout << setw(6) << "DEC"	// 'setw()' assigns a certain width
		 << setw(6) << "OCT" 
		 << setw(6) << "HEX" << endl;
	for (int i = 1; i < 20; i++) {
		cout << setw(6) << dec << i
			<< setw(6) << oct << i
			<< setw(6) << hex << i << endl;
	}

	// File Output
	ofstream out;	// 'ofstream' used for writting and appending creates file called 'out'
	out.open("hello.txt", ios::out);	// '.open(file location, file function)', 'ios::out' writes and overwrites, 'ios::app' appends
	// ofstream out("hello.txt", ios::out | ios::app);	// simplified way of declaring and writing to file
	out << "Hello World!";	// writes given data to file
	out.close();	// '.close()' closes the file to prevent issues

	// Reading from File
	ifstream fin("numbers.txt", ios::in);
	int n, m;
	while (!fin.eof()) {	// 'eof()' checks if it has reached the end of the File and can be used in a while loop
		fin >> n >> m;
		if (fin.good()) {	// 'good()' checks if the Stream is free of errors
			cout << n << " + " << m << " = " << n + m << endl;
		}
	}
	fin.close();
}

