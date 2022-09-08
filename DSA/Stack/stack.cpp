//
//  stack.cpp
//  DSA
//
//  Created by BA-000277306 on 08/09/22.
//

#include "stack.hpp"
#include <iostream>
#include <stack>

using namespace::std;

bool parenthesisCheck(string s) {
    int leng = (int)s.length();
    stack<int> stack;
    if(leng%2 != 0) {
        return false;
    }
    for(int i=0;i<leng;i++) {
        if(!stack.empty() && ((s[i] == ')' && stack.top() == '(') || (s[i] == '}' && stack.top() == '{') || (s[i] == ']' && stack.top() == '['))) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    return stack.empty();
    
    /*
     Use cases:
     1. [{()}]      Works: true
     2. (]          Works: False
     3. [(])        Works: False
     4. ][          Works: False
     5. ]]          Works: False
     6. [[          Works: False
     7. [{}()]      Works: true
     */
}

