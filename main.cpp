//============================================================================
// Name        : LabAssigment1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Updates: Have to check file output code
// Notes: print method gives error during file output code
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class PolynomialTest;
// Coefficients should be stored in increasing order of exponents
class Polynomial {
    
    friend class PolynomialTest;
    int* data;
    int data_size;
public:
    
    Polynomial() {
        // Randomize size
        int random_size = rand() % (1000 - 0 + 1) + 0;
        (*this).data = new int[random_size];
        
        // Allocate array
        for (int i = 0; i < random_size; i++) {
            int random_coefficients = rand() % (1000 + 1000 + 1) - 1000;
            (*this).data[i] = random_coefficients;
        }
        (*this).data_size = random_size;
    }
    
    // Class constructor
    Polynomial(int A[], int size) {
        (*this).data = new int[size]();
        
        for (int i = 0; i < size; i++) {
            (*this).data[i] = A[i];
        }
        (*this).data_size = size;
    }
    
    
    
    /*Polynomial(string fileName) {
     // Open filestream to read file
     ifstream in_file;
     int size;
     in_file.open(fileName);
     
     if (!in_file) {
     cerr << "Unable to open the file";
     exit(1);
     }
     if (!in_file.fail()) {
     in_file >> size;
     }
     (*this).data = new int[size];
     
     int i, val = 0;
     string s;
     while (!in_file.eof()) {
     in_file >> val;
     (*this).data[i] = val;
     ++i;
     }
     data_size = size;
     in_file.close();
     }*/
    
    // Destructor
   /* ~Polynomial() {
        delete [] data;
    }*/
    
   Polynomial(string fileName) {
       ifstream inputFile("danny.txt");        // Input file stream object
       
       // Check if exists and then open the file.
       if (inputFile.good()) {
           // Push items into a vector
           int number = 0;
           int i = -1;
           while (inputFile >> number){
               if (i==-1) (*this).data_size= number;
               else (*this).data[i] = number;
               i++;
           }
           
           // Close the file.
           inputFile.close();
        
       } else {
           cout << "Error!";
          
       }

    }
    
    bool operator ==(const Polynomial& target){
        bool are_equal = true;
        if ((*this).data_size != target.data_size) {are_equal = false;}
        else {
            for (int i = 0; i < data_size; i++) {
                are_equal = are_equal && (*this).data[i] == target.data[i];
            }
        }
        return are_equal;
    }
 
    void print(){
        
        int count = 0;
        for (int i =0; i< (*this).data_size; i++){
            if (i +1 == (*this).data_size){
                if ((*this).data[i]!=0){
                    cout <<((*this).data[i]) << "x^" << i << " ";
                    ++count;
                }
            
                
                
            } else {
                if ((*this).data[i]!=0) {
                    cout <<((*this).data[i]) << "x^" << i << " ";
                    ++count;
                }
                if (count >0){
                    if ((*this).data[i+1]>0) cout << "+ ";
                }
                
            }
                
            
        }
    }
    
    
    
    Polynomial operator+(const Polynomial& target){
        int size_one = target.data_size;
        int size_two = (*this).data_size;
        int combined_size = size_one;
        
        if (size_one > size_two)
            combined_size = size_one;
        else if (size_two > size_one)
            combined_size = size_two;
        
        int summed_p[combined_size];
        
        if (size_one > size_two) {
            for (int i = 0; i < size_two; i++) {
                summed_p[i] = (*this).data[i] + target.data[i];
            }
            for (int i = size_two; i < combined_size; i++) {
                summed_p[i] = target.data[i];
            }
        }
        else if (size_one < size_two) {
            for (int i = 0; i < size_one; i++) {
                summed_p[i] = target.data[i] + (*this).data[i];
            }
            for (int i = size_one; i < combined_size; i++) {
                summed_p[i] = (*this).data[i];
            }
        }
        else if (size_one == size_two) {
            for (int i = 0; i < size_two; i++)
                summed_p[i] = (*this).data[i] + target.data[i];
        }
        
        Polynomial sum(summed_p, combined_size);
        return sum;
    }
    
  /*  Polynomial operator-(const Polynomial& target){
        int size_one = target.data_size;
        int size_two = (*this).data_size;
        int combined_size = size_one;
        
        if (size_one > size_two)
            combined_size = size_one;
        else if (size_two > size_one)
            combined_size = size_two;
        
        int diff_p[combined_size];
        
        if (size_one > size_two) {
            for (int i = 0; i < size_two; i++) {
                diff_p[i] = (*this).data[i] - target.data[i];
            }
            for (int i = size_two; i < combined_size; i++) {
                diff_p[i] = -target.data[i];
            }
        }
        else if (size_one < size_two) {
            for (int i = 0; i < size_one; i++) {
                diff_p[i] = (*this).data[i] - target.data[i];
            }
            for (int i = size_one; i < combined_size; i++) {
                diff_p[i] = -(*this).data[i];
            }
        }
        else if (size_one == size_two) {
            for (int i = 0; i < size_two; i++)
                diff_p[i] = (*this).data[i] - target.data[i];
        }
        
        Polynomial difference(diff_p, combined_size);
        return difference;
    }*/
    
    Polynomial operator-(const Polynomial& target){
        int larger;
        int smaller;
        bool thisLarger;
        if ((*this).data_size < target.data_size)
        {
            smaller =(*this).data_size;
            larger = target.data_size;
            thisLarger = false;
        } else {
            larger = (*this).data_size;
            smaller = target.data_size;
            thisLarger = true;
            
        }
        
        Polynomial subtract;
        subtract.data_size = larger;
        
        for (int i = 0; i < smaller; i++)
        {
            subtract.data[i] = (*this).data[i] - target.data[i];
        }
        
        for (int i = smaller; i < larger; i++)
        {
            if(thisLarger) subtract.data[i] = (*this).data[i];
            else subtract.data[i] = -target.data[i];
        }
        
        return subtract;
        
        
    }
    
    Polynomial operator* (const Polynomial& target){
        Polynomial mult_p;
        //calculate largest index value
        
        mult_p.data_size = ((*this).data_size -1)+ (target.data_size);
        for (int i =0; i < mult_p.data_size; i++){
            mult_p.data[i] = 0;
        }
        for (unsigned int i = 0; i < (*this).data_size; i++) {
            for (unsigned int j = 0; j < target.data_size; j++) {
                mult_p.data[i+j] += data[i] * target.data[j];
            }
        }
        
        return mult_p;
    }
    
    
    Polynomial derivative(){
        Polynomial p;
        p.data_size = (*this).data_size -1;
        for (int i = 1; i < (*this).data_size ; i++){
            p.data[i-1] = (i) * (*this).data[i];
        }
    
        return p;
    }
};

class PolynomialTest
{
    Polynomial poly1, poly2, poly3, poly4, poly5, poly6, poly7, poly8, poly9, poly10;
    
public:
    
    bool test_constructor1() { // tests constructor with two parameters
        int A [5] = {10, 4, 7, 1, 1};
        Polynomial p1(A, 5);
        poly1 = p1;
        p1.print();
        for (int i =0; i < p1.data_size; i++) {
            if (p1.data[i]!=A[i]) return false;
        }
        return true;
    }
    
    bool test_constructor2() { //tests randomly generated constructor
        Polynomial p2;
        poly2 = p2;
        p2.print();
        return true;
    }
    
    //test reading from file
    
    
    bool test_equals() {
        poly3 = poly2;
        
        if ((poly3==poly2) && !(poly3==poly1)) return true;
        return false;
    }
    
    bool test_plus() {
        //compare the final polynomial coefficients with previously added coefficients
        int A [7] = {0,3, 5,2, 9,8,6};
        int B [3] = {4,2, 0};
        int C [4] = { 0 , 0,7 , 1};
        
        Polynomial p4(A, 7);
        Polynomial p5(B, 3);
        Polynomial p6(C, 4);
        
        //Test 1
        poly4 = p4 + p5;
        int ans4 [7] = {4, 5, 5, 2,9,8,6};
        for (int i = 0; i < poly4.data_size; i++)
        {
            if (poly4.data[i] != ans4[i]) return false;
        }
        
        //Test 2
        poly5 = p6 + p5;
        int ans5 [7] = {4, 2, 7, 1};
        for (int i = 0; i < poly5.data_size; i++)
        {
            if (poly5.data[i] != ans5[i]) return false;
        }
        
        //Test 3
        poly6 = p6 + p6;
        int ans6 [4] = {0, 0, 14, 2};
        for (int i = 0; i < poly6.data_size; i++)
        {
            if (poly6.data[i] != ans6[i]) return false;
        }
        
        return true;
            
    }
    
    bool test_minus() {
        int A [7] = {0,3, 5,2, 9,8,6};
        int B [3] = {4,2, 0};
        int C [4] = { 0 , 0,7 , 1};
        
        Polynomial p10(A, 7);
        Polynomial p11(B, 3);
        Polynomial p12(C, 4);
        
        //Test 1
        poly10 = p10 - p11;
        int ans10 [7] = {-4, 1, 5, 2,9,8,6};
        
        for (int i = 0; i < poly10.data_size; i++)
        {
            if (poly10.data[i] != ans10[i]) return false;
        }
        
        //Test 2
        poly10 = p11 - p12;
        int ans11 [4] = {4, 2, -7, -1};
        for (int i = 0; i < poly10.data_size; i++)
        {
            if (poly10.data[i] != ans11[i]) return false;
        }
        
        //Test 3
        poly10 = p12 - p11;
        int ans12 [4] = {-4, -2, 7, 1};
        for (int i = 0; i < poly10.data_size; i++)
        {
            if (poly10.data[i] != ans12[i]) return false;
        }
        
        
        
        return true;
    }
    
    bool test_mult(){
        int A[4] = {1, 0,0,2};
        int B[5] = {0, 0, 2, 0, 1};
        int C[2] = {10, 3};
        
        Polynomial pa (A,4);
        Polynomial pb (B, 5);
        Polynomial pc (C, 2);
        
        //Test 1
        poly9= pa*pb;
        
        int ans1[8] = {0,0,2,0,1,4,0,2};
        if (poly9.data_size==8){
            for (int i = 0; i < poly9.data_size; i++){
                if (poly9.data[i]!=ans1[i]) return false;
            }
        } else return false;
        
        //Test 2
        poly9= pa*pc;
        
        int ans2[5] = {10,3,0,20,6};
        if (poly9.data_size==5){
            for (int i = 0; i < poly9.data_size; i++){
                if (poly9.data[i]!=ans2[i]) return false;
            }
        } else return false;
        
        //Test 3
        poly9= pb*pc;
        int ans3[6] = {0,0,20,6,10,3};
        if (poly9.data_size==6){
            for (int i = 0; i < poly9.data_size; i++){
                if (poly9.data[i]!=ans3[i]) return false;
            }
        } else return false;
            
        return true;
        
    }
    
    bool test_derivative(){
       
        int A[3] = {6, 16, 22};
        int B[5] = {0, 0, 2, 0, 1};
        int C[3] = {2, 10, 3};
      
        Polynomial pa (A,3);
        Polynomial pb (B, 5);
        Polynomial pc (C, 3);
        
        //Test 1
        poly7 = pa.derivative();
        int ans1[2] = {16, 44};
        for (int i = 0; i< poly7.data_size; i++ )
        {
            if (poly7.data[i] !=ans1[i]) return false;
        }
        
        //Test 2
        poly7 = pb.derivative();
        int ans2[4] = {0, 4, 0, 4};
        for (int i = 0; i< poly7.data_size; i++ )
        {
            if (poly7.data[i] !=ans2[i]) return false;
        }
        
        //Test 3
        poly7 = pc.derivative();
        int ans3[2] = {10,6 };
        for (int i = 0; i< poly7.data_size; i++ )
        {
            if (poly7.data[i] !=ans3[i]) return false;
        }
        
        return true;
    }
    
    bool test_readfile () {
        string f = "danny.txt";
        Polynomial coolio(f);
        coolio.print();
        return true;
    }
    
    void run(){
        cout << (test_constructor1() ? "Test Constructor1 Passed" : "Test Constructor1 Failed") << endl;
        cout << (test_constructor2() ? "Test Constructor2 Passed" : "Test Constructor2 Failed") << endl;
        cout << (test_equals() ? "Test == Passed" : "Test == Failed") << endl;
        cout << (test_plus() ? "Test + Passed" : "Test + Failed") << endl;
        cout << (test_minus() ? "Test - Passed" : "Test - Failed") << endl;
        cout << (test_mult()? "Test * Passed" : "Test * Failed") << endl;
        cout << (test_derivative()? "Test Derivative Passed" : "Test Derivative Failed") << endl;
       // cout << (test_readfile()? "Test ReadFile Passed" : "Test ReadFile Failed") << endl;
    }
    
    
};

int main() {
    PolynomialTest my_test;
    my_test.run();
}

