//C++ file for creating a 3d array using pointers
//Array is passed through a function to come out as a modified one

#include<iostream>
#include<vector>
using namespace std;

//Initial function to assign vales to array elements
void darr(double*** a)
{
for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
        for (int k=0; k<3; k++){
            a[i][j][k]=i*j*k;
        }
    }
}
}

//Second function to assign a new set of values to array elements
void darr2(double*** a)
{
for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
        for (int k=0; k<3; k++){
           a[i][j][k]=i*j*k+1;
        }
    }
}
}

//Main function
int main()
{   
    //Creating a 3d array 
    /*---------------------------------------------*/
    double*** b;
    b=new double**[3];
    for (int i=0; i<3; i++){
        b[i]=new double*[3];
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            b[i][j]=new double[3];
            }
        }
    /*----------------------------------------------*/    
    
    //Calling first function
    darr(b);
    
    //Printing out the array elements
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                cout<<b[i][j][k]<<"\t";
                }
            cout<<"\n";
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    //Calling the second function
    darr2(b);
    //Old values of b are replaced with new values of second function 
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                cout<<b[i][j][k]<<"\t";
                }
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    //Deleting the memory
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            delete[] b[i][j];
        }
    }
    
    for (int i=0; i<3; i++){
        delete[] b[i];
    }
    
    delete[] b;
    
    return 0;
}

/*
Output:
-----------------------
Array elements after being passed through function 1:
0       0       0
0       0       0
0       0       0

0       0       0
0       1       2
0       2       4

0       0       0
0       2       4
0       4       8
------------------------
Array elements after being passed through function 2:
Note: Existing values(function 1) are overridden by function 2
1       1       1
1       1       1
1       1       1

1       1       1
1       2       3
1       3       5

1       1       1
1       3       5
1       5       9
*/
