#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int GlobalVar = 1;

int main()
{
    // Single line comment
    /* multiple
    * line
    * comment
    */
    cout << "Hello World!\n" /* inline comment */ << endl;
    cout << "Goodbye" << endl;
    
    // Variables act as a "container" for data:
    // C++ is a Strictly Typed Language
    // Void     (not really a data type)
    // Short    16-bit whole number
    // Int*     32-bit whole number
    // Long     32 or 64-bit whole number
    // Float    32-bit floating point number
    // Double*  64-bit floating point number
    // Bool*    True or False
    // Char*    Single character
    // Const    used to specify a constant (variable that does not change)
    // String   (not really a built-in type)
    // *What you will use in most cases

    // Rules for Variables:
    // no length limit for variables
    // case sensitive
    // must begin with a letter or _
    // should only include letters, numbers, or underscores
    // cannot be a reserved word/library names
    // may only be defined once in scope
    // must be declared before being used
    // variable name should represent its contents

    // Terminology:
    // Declare      introduces a "symbol" such as a variable to the compiler
    // Define       allocating memory to hold the variable or function
    // Initialize   giving the variable its initial value

    int age = 20;

    cout << age << endl;

    int LocalVar = 2;

    cout << GlobalVar << endl;
    cout << LocalVar << endl;

    // Variable Scope is where your variables can be seen/accessed:
    // Global                   can be accessed within the file
    // Local                    limited by curly braces
    // Function Parameters      part of a function

    // Type Promotions
    cout << (7 / 5.0) << endl;

    // Type Casting (NOT the same as rounding)
    
    double x = 67.56;
    cout << (int)x << endl;
    cout << ((double)9 / 5) << endl;

    // String Parsing
    string coord = "96";
    cout << stoi(coord) + 10 << endl;

    // stoi     String to Integer
    // stol     String to Long
    // stof     String to Float
    // stod     String to Double

    // Basic Input
    string name;
    cout << "What is your name? ";
    cin >> name;

    cout << "Hello" + name << endl;

    int num1;
    int num2;
    char comma;

    cout << "Enter two numbers " << endl;
    cin >> num1 >> comma >> num2;
    cout << "Your numbers combined are " << num1 + num2 << endl;

    // Escape Sequences (parts of strings and go inside the quotes):
    // \n   New Line
    // \t   Tab Stop
    // \"   Display a Double Quote
    // \\   Display a Backslash

    // Formatting Output (part of the iomanip library):
    // setw()           sets the width of something
    // setprecision()   sets the number of decimal places displayed
    // fixed
    double p = 355.0 / 201;
    cout << fixed << setprecision(3) << p << endl;

    string id = "Jin";
    cout << setw(15) << id << endl;

    // Arithmetic Ops:
    // + addition
    // - subtraction
    // * multiplication
    // / division
    // % modular division (division, display the remainder)
    // () parenthesis (order of operations)
    // ++ increment (increases by 1)
    // -- decrement (decreases by 1)
    int a = 9;
    int b = 7;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    a++;
    cout << a << endl;
    a--;
    cout << a << endl;
    cout << ++a << endl;
    cout << --a << endl;

    // Compound Assignment
    a = a + 6;
    cout << a << endl;
    a += 6;
    cout << a << endl;
    a -= 6;
    cout << a << endl;
    a *= 6;
    cout << a << endl;
    a /= 6;
    cout << a << endl;

    // Math Library
    cout << sqrt(2) << endl;
    cout << sin(3.14159265 / 2) << endl;

    // Distance Formula Example
    double x1, y1, x2, y2, d;
    char c;

    cout << "Distance Formula Calculator" << endl;
    cout << "Enter the first point (x,y) " << endl;
    cin >> x1 >> c >> y1;

    cout << "Enter the second point (x,y) " << endl;
    cin >> x2 >> c >> y2;

    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance = " << fixed << setprecision(10) << d << endl;
    
    // Pseudo-Random Numbers:
    // can be used for games, test cases/simulations, calculating probabilities, art
    cout << rand() << endl;

    // Random number between 1 and 10
    cout << rand() % 10 + 1 << endl;

    // Random number between 13 and 19
    // rand() % (highestvalue - lowestvalue + 1) + lowestvalue
    cout << rand() % 7 + 13 << endl;

    system("pause");
}
