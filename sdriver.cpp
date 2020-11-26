#include "stack.h"
#include <iostream>
#include <vector>


int main(){
    std:: string res;
    int x;
    int y;
    char c;
    stack s;
    s.push(0,9,'>');
    
    res = s.pop();
    std:: cout << res << std:: endl;
    if(res[2] != 'z'){
        x = res.at(0) - '0';
        y = res.at(1) - '0';
        c = res.at(2);
    }
    std:: cout << x << y << c << std:: endl;
    
    return 0;
}

