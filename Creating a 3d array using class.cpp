#include<iostream>
using namespace std;

/*----------------------------------------*/
//Initalising 3d array
template <typename T>
class Field
{
public:
	/*constructor*/
	Field(int ni, int nj, int nk) 
	{
		//allocate memory for a 3D array
		data = new T**[ni];
		for (int i=0;i<ni;i++)
		{
			data[i] = new T*[nj];
			for (int j=0;j<nj;j++){
				data[i][j] = new T[nk];
			} 
		}		

	}
	T** operator[] (int i) {
		return data[i];
		}
protected:
	int ni,nj,nk;	//allocated dimensions
	T ***data;	/*data held by this field*/
};
/*------------------------------------------*/

//Function to update array elements
//class is used to define the type of array.
void major(Field<double> a) 
{
	int i, j, k;
	for (k=0; k<3; k++){
		for (i=0; i<3; i++){
			for (j=0; j<3; j++){
				a[i][j][k]=i*j*k+1;
			}
		}
	}
}

//Main function 
int main()
{
	//Calling a 3d array 'b' using pre-defined class
	Field<double> b(3,3,3);
	int i, j, k;
	//Updating the array elements
	major(b);
	for (k=0; k<3; k++){
		for (i=0; i<3; i++){
			for (j=0; j<3; j++){
				cout<<b[i][j][k]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}	
	
}

