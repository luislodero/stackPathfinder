#include "polish.h"
#include <iostream>

double foundSign(stack stonk, char sign){
   double d1 = stonk.pop();
   double d2 = stonk.pop();
   double d3;
   
    if(sign == '-'){
       d3= (d2-d1);
    }else if(sign == '*'){
        d3= (d2*d1);
    }else if(sign == '+'){
        d3= (d2+d1);
    }else if(sign== '/'){
        if(d1 == 0){
            std:: cerr << "Cannot divide by zero yo\n";
            exit(1);
        }
        d3= (d2/d1);
    }
    //std:: cout << d3 << std:: endl;
    return d3;
}



double calc(std:: string s){
    int i = s.length();
    int j = 0;
    stack stonk;
    
    while(j < i){
    
        double tmp;
        
        if(s[j] >= '0'){
            //std:: cout << s[j] << std:: endl;
            tmp = s[j] -'0';
            stonk.push(tmp);
            
        }else{
            char sign = s[j];            
            //std:: cout << sign << std:: endl;
            tmp = foundSign(stonk,sign);
            stonk.push(tmp);
        }
    j++;
    
    }
    
    return stonk.pop();
    
}



int main(){
    
    std:: string s;
    std:: cout << "Enter an equation" << std:: endl;
    std:: cin >> s;
    if(s[0] < '0'){
        std:: cerr << "First character must be a number byebye\n";
        exit(1);
    }
    double res = calc(s);
    std:: cout<< res << std:: endl;
    
    return 0;
}