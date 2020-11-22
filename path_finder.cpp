#include "stack.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

void fillVector(std:: vector<std:: vector<int>> &V, std:: vector<std:: vector<int>> &A){
    int ysize = V.size()+2;
    int xsize = V[0].size()+2;
    
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
bool checkPos(std:: vector< std:: vector<int>> A, stack&s){
    
}

bool path_finder(std:: vector<std:: vector<int>> &V, stack &s){
    int ysize = V.size()+2;
    int xsize = V[0].size()+2;
    std::vector<std:: vector<int>> A(ysize, std::vector<int> (xsize, 0));
    fillVector(V,A);
    checkPos(A,s);
    return true;
}


int main(){
    
    std:: string filename = "matrix.txt";
    
    std:: ifstream ifs;
    ifs.open(filename);
  
    std:: vector<std:: vector<int>> V;
    std:: string str;
    
    std:: vector<std:: vector<char>> A;
    while(getline(ifs, str)) {
      V.push_back(getMatrix(str));
    }
    
    printVector(V);
    
    stack s;
     
    path_finder(V, s);
    
    return 0;
}