#include <cstdio>
#include <cstdlib>

#include <sort.h>


int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 
  register int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
    A[i+1] = A[i];
    i = i - 1;
  }

      A[i+1] = key;
    }
}

/*
 * optmized insertion sort
 */
void insertion_sort_im(int** A, int n, int l, int r)
{ 
  // pre compute the length for each vector
  int * B = new int[r-l+1];
  for(int i=0; i<=r; i++){
    B[i]=ivector_length(A[i], n);
  }

  register int i;
  int* key;
  int keyB;

  for (int j = l+1; j <= r; j++)
    {
      keyB = B[j];
      key = A[j];
      i = j - 1;
      // no more length computing, only retrive length from heap
      while ((i >= l) && (B[i] > keyB))
        {
          B[i+1] = B[i];
          A[i+1] = A[i];
          i = i - 1;
        }
      B[i+1] = keyB;
      A[i+1] = key;
    }
}

/*
 * merge sort
 */
void merge_sort(int** A, int n, int l, int r)
{ 

  int * B = new int[r-l+1];
  for(int i=0; i<=r; i++){
    B[i]=ivector_length(A[i], n);
  }
  merge(A, B,n, l, r);
  

}

void merge(int** A,int* B,int n,int l,int r){
  if(l==r) return;
  int m = (l+r)/2;

  // merge left subarray
  merge(A, B, n, l, m);
  // merge right subarray
  merge(A, B, n, m+1, r);
  // after merge of each subarray, sort the current array
  sort_after_merge(A, B, n, l, m, r);
}

void sort_after_merge(int** A,int*B,int n, int l,int m,int r){
  int* tempBL = new int[m-l+1];
  int* tempBR = new int[r-m];
  /*
   * When do 
   * int** tempAL = new int[m-l+1][n];  
   * return compile err
   * "only the first dimension of an allocated array may have dynamic size"
   * so I haveto new each inside arr one by one.
   */

  int** tempAL = new int*[m-l+1];
  int** tempAR = new int*[r-m];

  for(int i=0;i<m-l+1;i++){
    tempBL[i] = B[l+i];
  }
  for(int i=0;i<r-m;i++){
    tempBR[i] = B[m+1+i];
  }

  for(int i=0;i<m-l+1;i++){
    int* foobar = new int[n];
    for(int j=0;j<n;j++){
      foobar[j]=A[l+i][j];
    }
    tempAL[i] = foobar;
  }
  for(int i=0;i<r-m;i++){
    int* foobar = new int[n];
    for(int j=0;j<n;j++){
      foobar[j]=A[m+1+i][j];
    }
    tempAR[i] = foobar;
  }

  /* i, the index of left temp subarr
   * j, the index of right temp subarr
   * k, the index of origin arr
   */
  // pick the smallest one and put it back into origin array
  int i=0,j=0,k=l;
  for(;i<m-l+1 && j<r-m;k++){
    if(tempBL[i]>tempBR[j]){
      B[k]=tempBR[j];
      A[k]=tempAR[j];
      j++;
    }else{
      B[k]=tempBL[i];
      A[k]=tempAL[i];
      i++;
    }
  }
  while(i<m-l+1){
    B[k]=tempBL[i];
    A[k]=tempAL[i];
    i++;
    k++;
  }
  while(j<r-m){
    B[k]=tempBR[j];
    A[k]=tempAR[j];
    j++;
    k++;
  }

  free(tempBL);
  free(tempBR);
  // can't not free one by one. Got runtime err. Why? Already freed?
  // for(int i=0;i<m-l+1;i++){
  //   free(tempAL[i]);
  // }
  free(tempAL);
  // for(int i=0;i<r-m;i++){
  //   free(tempAR[i]);
  // }
  free(tempAR);
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
  rg >> iv_array[i][j];
  if (small)
    iv_array[i][j] %= 100;
  else
    iv_array[i][j] %= 65536;
      }

  return iv_array;
}