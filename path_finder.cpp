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
    len--;
    
    while(len >= 0 || count > 0){
/**
 * GOTTA MAKE SURE DIRECTIONS ARE CLEAR AND 
 * MAKE SURE IT'S NOT MOVING TO A SMALLER NUMBER BEFORE SUBMITTING
 *
**/
        if((!visited(A,curry,currx-1)) && (A[curry][currx] <=A[curry][currx-1])){

            A[curry][currx] = -59;  //left
            C[curry-1][currx-1] = '<';
            s.push(curry, currx-1);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            if(len <= 0){
                C[curry-1][currx-1] = '*';
            }
            
        }else if(!visited(A,curry-1,currx) && (A[curry][currx] <=A[curry-1][currx])){

            A[curry][currx] = -79;  //up
            C[curry-1][currx-1] = '^';
            s.push(curry-1, currx);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            if(len <= 0){
                C[curry-1][currx-1] = '*';
            }
        }else if(!visited(A,curry,currx+1) && (A[curry][currx] <= A[curry][currx+1])){
            
            A[curry][currx] = -99;  //right
            C[curry-1][currx-1] = '>';
            s.push(curry, currx+1);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            if(len <= 0){
                C[curry-1][currx-1] = '*';
            }
        }else if(!visited(A,curry+1,currx) && (A[curry][currx] <=A[curry+1][currx])){

            A[curry][currx] = -99;  //down
            C[curry][currx] = 'v';
            s.push(curry+1, currx);
            str = s.peek();
            curry = str[0] - '0';
            currx = str[1] - '0';
            len--;
            if(len <= 0){
                C[curry-1][currx-1] = '*';
            }
        }else{
            return false;
        }
        
    }
    return true;
    
}



int main(){
    
    int len;
    std:: string filename = "matrix.txt";
    
    std:: ifstream ifs;
    ifs.open(filename);
    std :: cout << " Pick a length" << std:: endl;
    std:: cin >> len;
    std:: vector<std:: vector<int>> V;
    std:: string str;
    
    std:: vector<std:: vector<int>> A;
    while(getline(ifs, str)) {
      V.push_back(getMatrix(str));
    }

    printVector(V);
    A = fillVector(V);
    
    int size = V.size();
    int xlen = V[0].size();
    bool done = false;
    std:: vector<std:: vector<char>> C( size , std:: vector<char> (xlen, '-')); 
    for(int i=0; (i < size); i ++){

        for(int j = 0; (j < xlen);j++){
            
            int curry = i + 1;
            int currx = j + 1;
             if(path_finder(C,A,curry, currx, len)){
                 std:: cout << "Found solution" << std:: endl;
                 done = true;
                 break;
             }  
        }
        
        if(done){
            break;
        }
        
    }
    if(done){
        printVector(C);
    }else{
        std:: cout << "Sorry no solution was found" << std:: endl; 
    }

    return 0;
}