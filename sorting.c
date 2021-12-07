#include <stdio.h>
#include<stdlib.h>
#define size 100

void bubbleSort(int a[size], int n);
void insertionSort(int a[size], int n);
void selectionSort(int a[size], int n);
void quickSort(int a[size] , int start , int end);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void copy(int a1[size],int a2[size],int n)
{
    for(int i = 0; i< n; i++)
    a1[i]=a2[i];
}
void display(int a[size],int n)
{
    for(int i = 0; i< n; i++)
    printf("%d \t ", a[i]);

}


int main()
{
    printf(" \n \t <<<<<<<< Welcome to Sorting>>>>>>>>>> \t \n ");
    int n,arr[size],arr2[size],i,ch;
    printf("\n \t Enter the Size of the array......?\n \t ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n \t Enter the array[%d]th element :- \n \t",i);
        scanf("%d",&arr2[i]);
    }
while(1)
    {
    printf("\n \n \t -------------------Menu---------------------\n \n \t ");
    printf("\n \n \t  1.Enter 1 for bubble sort \n \n \t  2.Enter 2 for insertion sort  \n \n \t  3.Enter 3 for selection sort  \n \n  \t  4. Enter 4 for Quick sort \n \n \t  5. Enter 5 for Merge sort  \n \n  \t  6.Enter 6 for displaying unsorted array  \n  \n \t  7. Enter 7 for  Exiting ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            copy(arr,arr2,n);
            bubbleSort(arr,n);
            break;
      case 2:
            copy(arr,arr2,n);
            insertionSort(arr,n);
            break;
      case 3:
            copy(arr,arr2,n);
            selectionSort(arr,n);
            break;
      case 4:
            copy(arr,arr2,n);
            quickSort(arr ,0, n-1);
            printf("\n ");
            printf("step is -: \t ");
            display(arr,n);
            printf("\n ");
            break;

      case 5:
            copy(arr,arr2,n);
            mergeSort(arr,0,n);
            printf("\n \t ");
            printf("step is -: \t ");
            display(arr,n);
            printf("\n \t  ");
            break;
      case 6:
           display(arr2,n);
           break;

      case 7:
            printf("\n --------------------Exiting---------------------- \n");
            exit(0);
            break;
        default:
            printf("@@@@@@@@@@@@@@@Invalid@@@@@@@@@@@@@@@@");
            break;

    }
    }
}
void bubbleSort(int a[], int n) {

  for (int step = 0; step < n - 1; ++step) {
    for (int i = 0; i < n - step - 1; ++i) {

      if (a[i] > a[i + 1]) {

        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        printf("   change step is -:\t ");
        display(a,n);
        printf("\n ");
      }
      else
        {
        printf("un change step is -:\t ");
        display(a,n);
        printf("\n ");
        }
    }
  }

    printf("         final Step:- \t ");
    display(a,n);
    printf("\n ");
}
void insertionSort(int a[size], int n)
{
    for(int i=0;i<n;i++){
      int temp=a[i];
      int key=i-1;
      while((temp<a[key])&&(key>=0)){
         a[key+1]=a[key];
         key=key-1;
      }
      a[key+1]=temp;
        printf("step is -: \t ");
        display(a,n);
        printf("\n ");
   }
   printf(" final Step:- \t ");
   display(a,n);
   printf("\n ");
}
void selectionSort(int a[size], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
        swap(&a[min_idx], &a[i]);
        printf("step is -: \t ");
        display(a,n);
        printf("\n ");
    }

    printf(" final Step:- \t ");
    display(a,n);
    printf("\n ");
}
void quickSort(int a[size] , int start , int end)
{
  if (start<end)
    {
    int local = partition(a,start,end);
    quickSort(a,start,local-1);
    quickSort(a,local+1,end);
    }
        printf(" sorted list -: \t ");
        display(a,end);
        printf("\n ");
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        printf("merging  -: \t ");
        for(int k=l;k<=r-1;k++)
        printf("%d \t",arr[k]);
        printf("\n ");
    }


}
