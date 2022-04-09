#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Calculator {
public:
    Calculator() : input_v(NULL) {
    }
    ~Calculator() {
        // free char array when it's not a null
        if (input_v)
            free(input_v);
    }
    void insert_input();
    void show_input();
    bool is_valid_input(string input_str);   // need implementation
    void process(); // need implementation
    void show_output(); // need implementation
private:
    char* input_v;
    int result;
};

void Calculator::insert_input()
/**
* reseive input string from the users
* @param none
* @return none
*/
{
    string strtmp;
    cin >> strtmp;
    
    // check if this input is invalid or not
    if (is_valid_input(strtmp)) {
        // when it's valid input, copy the input to char array
        input_v = _strdup(strtmp.c_str());
    }
    else {
        cout << "This is invalid input, please use only '+', '-', '*', '/', '(', ')' and numeric characters." << endl;
    }
}

void Calculator::show_input()
/**
* display input string which received from users
* @param none
* @return none
*/
{
    cout << input_v << endl;
}


bool Calculator::is_valid_input(string input_str)
/**
* check if this string is valid input for this calculator
* @param input_str, string input
* @return true if it's valid, otherwise is false
*/
{
    for (int i = 0; i < input_str.length(); i++) {
        if (input_str[i] >= 40 && input_str[i] >= 57 && input_str[i] != 44 && input_str[i] != 46) {
            continue;

        }
        else {
            return false;

        }
        //if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '*' || input_str[i] == '/' || input_str[i] == '(' || input_str[i] == ')' || input_str[i] == '0' || input_str[i] == '1' || input_str[i] == '2' || input_str[i] == '3' || input_str[i] == '4' || input_str[i] == '5' || input_str[i] == '6' || input_str[i] == '7' || input_str[i] == '8' || input_str[i] == '9') {

    }
}

void Calculator::process()
{
    int num1 = -1, num2 = -1;
    char ops = '+';
    bool coll = false;
    for (int i = 0; i < sizeof(input_v) / sizeof(input_v[0]); i++) {
        if (input_v[i] >= 48 && input_v[i] <= 57) {
            if (num1 == -1 && coll == false) {
                num1 = input_v[i];
                coll = true;
            }
            else if (num2 == -1 && coll == true) {
                num2 = input_v[i];
                
            }
        }
        if (input_v[i] >= 42 && input_v[i] <= 47 && input_v[i] != 44 && input_v[i] != 46) {
            ops = input_v[i];
        }
    }
    coll = false;
    if (ops == '+') {
        result = num1 + num2;
    }
    if (ops == '-') {
        result = num1 - num2;
    }
    if (ops == '*') {
        result = num1 * num2;
    }
    if (ops == '/') {
        result = num1 / num2;
    }
}

void Calculator::show_output()
{
    cout << result << endl;
}

int main()
{
    // declare main calculator
    Calculator c;
    // receive input from users
    c.insert_input();
    c.show_input();
    // process result from input string
    c.process();
    // display result
    c.show_output();
    // done
}
