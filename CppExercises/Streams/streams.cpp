// NOTE: no .h extensions in C++ standard libraries
//
// iostream: contains basic io streaming operations (cin, cout, etc.)
#include <iostream>
// true string type
#include <string>
// convert strings to streams with stringstream
#include <sstream>
// write files easily as streams
#include <fstream>

namespace foo
{
    // std:: denotes the namespace of std
    // cout takes a string as a stream and prints it to stdout
    // endl is the stream form of an end-of-line character \n
    void print() { std::cout << "This is printing from foo." << std::endl; }
}

namespace bar
{
    void print() { std::cout << "This is printing from bar." << std::endl; }
}

int main()
{
    // specify that everything in the namespace std should 
    // become available in the local scope for convenience
    using namespace std;

    // demonstration that the std:: prefix is no longer needed
    cout << "This is printing in main." << endl;

    foo::print();
    bar::print();

    // specify that print from foo:: should be pulled into local scope
    using foo::print;

    // demonstration that the foo:: prefix is no longer needed
    print();

    // define true string variable to hold input
    string input;
    // define float and int types to hold parsed input
    float fnum=0;
    int   inum=0;

    // Ask for input from user as a string
    cout << "Enter a float: ";
    // get entire line until a carriage return
    getline(cin, input);
    // use streams to parse the string input as different types
    stringstream(input) >> fnum;
    stringstream(input) >> inum;
    // show result of parsed input
    cout << "Input as a float: " << fnum << endl;
    cout << "Input as an int : " << inum << endl;

    // file handle
    ofstream output;
    // open a file
    output.open("output_file.txt");
    // write to file as a stream
    output << "This is the first line of the file." << endl;
    output << "Input as a float: " << fnum << '\t';
    output << "Input as an int : " << inum << endl;
    output.close();

    return 0;
}
