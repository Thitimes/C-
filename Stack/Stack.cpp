// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int stack[100], n = 100, top = -1;
void push(int val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        cout << "push = " << val << endl;
        stack[top] = val;
    }
}

int pop() {
    if (top <= -1) {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else {
        cout << "pop = " << stack[top] << endl;
        int data = stack[top--];
        return data;
    }
}

void display() {
    if (top >= 0) {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}
int calNum(char symb, int first, int second) {
    int temp = 0;
    if (symb == '+') {
        temp = first + second;
        cout << "temp" << temp;
    }
    else if (symb == '-') {
        temp = first - second;
    }
    else if (symb == '/') {
        temp = first / second;
    }
    else if (symb == '*') {
        temp = first * second;
    }
    else if (symb == '^') {
        temp = first;
        for (int i = 0; i < second; i++) {
            temp *= first;
        }
    }
    return temp;
}
int main()
{
    char input[100];
    char symb[50];
    int first = 0, second = 0, count = 0, scount = 0, temp = 0;
    bool result = false;
    cout << "Please Put number in a Postfix form (ABC+-)" << endl;
    cin >> input;
        while (input[count] != NULL) {
            cout << input[count] << endl;
            int num = 0;
            if (input[count] >= '0' && input[count] <= '9') {
                push(input[count] - '0');
            }
            else if (input[count] == '+' || input[count] == '-' || input[count] == '*' || input[count] == '/' || input[count] == '^') {
                symb[scount] = input[count];
                second = pop();
                first = pop();
                push(calNum(symb[scount], first, second));
                scount++;
            }
           
            count++;
        }
        display();
}


