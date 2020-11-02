#include <iostream>
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
nt l=0;
void helper(int input[], int n, int output[][50], int k,int a[],int e)
{
    if(n==0)
    {
        if(k==0)
        {
            output[l][0]=e;
            for(int i=0;i<e;i++)
                output[l][i+1]=a[i];
            l++;
        }
        return;
    }
    helper(input+1,n-1,output,k,a,e);
    a[e]=input[0];
    helper(input+1,n-1,output,k-input[0],a,e+1);
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    int a[50];
    helper(input,n,output,k,a,0);
	return l;
}
