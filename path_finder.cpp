#include "stack.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

template<typename T>
void printVector(std:: vector<std:: vector<T>> &A){
    int x = A.size();
    for( int i = 0; i < x; i++){
        int y = A[i].size();
        for(int j = 0; j < y; j ++){
            std:: cout << "  "<< A[i][j];
        }
        std:: cout << std:: endl;
    }
}

std:: vector<std:: vector<int>> fillVector(std:: vector<std:: vector<int>> &V){
    int ysize = V.size()+2;
    int xsize = V[0].size()+2;
    std::vector<std:: vector<int>> A(ysize, std::vector<int> (xsize, 0));
    for(int i = 0; i < ysize; i++){
        
        for(int j=0; j < xsize; j++){
            
            if(i == 0 || i == ysize-1){
                A[i][j] = 0;
            }else if(j == 0 || j == xsize-1){
                A[i][j] = 0;
            }else{
                A[i][j] = V[i-1][j-1];
            }
            
        }
        
    }
    return A;
    
}

std:: vector<int> getMatrix(std:: string str){
    std:: vector<int> V;
    int k;
    std:: istringstream iss (str);
    while(iss >> k){
        V.push_back(k);
    }
    return V;
}

bool visited(std:: vector<std:: vector<int>> A, int y, int x){
    if(A[y][x] > 0){
        return false;
    }
    return true;
}

bool path_finder(std:: vector<std:: vector<char>>&C, std:: vector<std:: vector<int>> &A, int py, int px, int &len){
    
    int count =0;
    stack s;
    s.push(py, px);
    std:: string  str= s.peek();
    int curry = str[0] - '0';
    int currx = str[1] - '0';
    //std:: cout << str << std:: endl;
    len--;
    
    while(len >= 0 || count > 0){
        std:: cout << str << std:: endl;
/**
 * GOTTA MAKE SURE DIRECTIONS ARE CLEAR AND 
 * MAKE SURE IT'S NOT MOVING TO A SMALLER NUMBER PLS
 *
**/
        if((!visited(A,curry,currx-1)) && (A[curry][currx] <=A[curry][currx-1])){
            std:: cout << A[curry][currx] <<"moving left to " << A[curry][currx-1] << std:: endl;

            A[curry][currx] = -99;  //left
            s.push(curry, currx-1);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            std:: cout << len << std:: endl;
            //std:: cout << str << std:: endl;
if(len == 0){
                A[curry][currx] = -69;
            }
            
        }else if(!visited(A,curry-1,currx) && (A[curry][currx] <=A[curry-1][currx])){
            std:: cout << A[curry][currx] << "moving up to "<< A[curry-1][currx] << std:: endl;

            A[curry][currx] = -99;  //up
            s.push(curry-1, currx);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            std:: cout << len << std:: endl;
            //std:: cout << str<< std:: endl;
if(len == 0){
                A[curry][currx] = -69;
            }

        }else if(!visited(A,curry,currx+1) && (A[curry][currx] <= A[curry][currx+1])){
            std:: cout <<A[curry][currx] << "moving right to" << A[curry][currx+1]<< std:: endl;

            A[curry][currx] = -99;  //right
            s.push(curry, currx+1);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            std:: cout << len << std:: endl;
            //std:: cout << str << std:: endl;
            if(len == 0){
                A[curry][currx] = -69;
            }
        }else if(!visited(A,curry+1,currx) && (A[curry][currx] <=A[curry+1][currx])){
                        std:: cout << A[curry][currx] << "moving down" << A[curry+1][currx]<< std:: endl;

            A[curry][currx] = -99;  //down
            s.push(curry+1, currx);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            std:: cout << len << std:: endl;
            //std:: cout << str << std:: endl;
            if(len == 0){
                A[curry][currx] = -69;
            }
        }else{
            return false;
        }
        
    }
    if(len <= 0){
        
        C[0][0] = 'z';
        
    }
    
    // std:: cout << s.pop() << std:: endl;
    // std:: cout << s.pop() << std:: endl;
    // std:: cout << s.pop() << std:: endl;
    // std:: cout << s.pop() << std:: endl;
    
    

    return true;
    
}



int main(){
    stack s;
    std:: string filename = "matrix.txt";
    
    std:: ifstream ifs;
    ifs.open(filename);
    
    std:: vector<std:: vector<int>> V;
    std:: string str;
    
    std:: vector<std:: vector<int>> A;
    while(getline(ifs, str)) {
      V.push_back(getMatrix(str));
    }

    printVector(V);
    A = fillVector(V);
    printVector(A);
    
    int size = V.size();
    int xlen = V[0].size();
    int len = 5;
    bool done = false;
    std:: vector<std:: vector<char>> C( size , std:: vector<char> (xlen, '-')); 
    printVector(C);

    for(int i=0; (i < size); i ++){

        for(int j = 0; (j < xlen);j++){
            
            int curry = i + 1;
            int currx = j + 1;
              if(path_finder(C,A,curry, currx, len)){
                  std:: cout << "found it" << std:: endl;
                  printVector(C);
                  done = true;
                  break;
              }  
        }
        
        if(done){
            break;
        }
        
    }
    if(len <= 0){
        std:: cout << "test test test " << std:: endl;
                    printVector(A);

    }else{
        std:: cout << "Sorry no solution was found" << std:: endl; 
    }
    std:: cout << C[0][0] << std:: endl;
    
    return 0;
}