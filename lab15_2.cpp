#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool x[][N]){
	for(int i=0;i<N;i+=1){
		for(int j=0;j<N;j+=1){
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void inputMatrix(double x[][N]){
	for(int i=0;i<N;i+=1){
		cout << "Row " << i+1 <<": ";
		for(int j=0;j<N;j+=1){
			cin >> x[i][j];
		}
	}
}

void findLocalMax(const double x[][N], bool y[][N]){
	for(int i=1;i<N;i+=1){
		for(int j=1;j<N;j+=1){
			if( ((x[i][j])>=(x[i+1][j])) && ((x[i][j])>=(x[i-1][j])) && ((x[i][j])>=(x[i][j-1])) && ((x[i][j])>=(x[i][j+1])) ){
				y[i][j] = 1;
			}else y[i][j] = 0;
		}
	}
	for(int q=0;q<N;q+=1){
		y[0][q]=0;
		y[N-1][q]=0;
		y[q][0]=0;
		y[q][N-1]=0;
	}
}
