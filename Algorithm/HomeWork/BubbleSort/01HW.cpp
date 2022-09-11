#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void swap(int* a, int* b);
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
 int numTestCases;
 int a[MAX_SIZE], b[MAX_SIZE];
 scanf("%d", &numTestCases);
 for (int i = 0; i < numTestCases; ++i)
 {
 int num;
 scanf("%d", &num);
 for (int j = 0; j < num; j++)
 scanf("%d", &b[j]);
 copyArray(a, b, num);
 bubbleSort(a, num);
 copyArray(a, b, num);
 bubbleSortImproved1(a, num);
 copyArray(a, b, num);
 bubbleSortImproved2(a, num);
 printf("\n");
 
 }
 return 0;
}
void swap(int* a, int* b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort 알고리즘 구현

 for (int pass =0; pass<n;pass++)
 {
    for(int i = 0;i<n-pass-1;i++ )
 
    {
    countCmpOps++;
    if(a[i] > a[i+1])
    {
        swap(&a[i], &a[i+1]);
        countSwaps++;
    }
    }
 }
    printf("%d %d ", countCmpOps, countSwaps);
 
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort의 개선된 알고리즘 (1) 구현
 for(int pass=0;pass<n;pass++)
 {
     bool swapped = false;
     
     for(int i=0;i<n-pass-1;i++)
     {
         countCmpOps++;
         if(a[i] > a[i+1])
         {
             swap(&a[i],&a[i+1]);
             countSwaps++;
             swapped = true;
         }
     }
     if(swapped == false) break;
 }
 
 printf("%d %d ", countCmpOps, countSwaps);
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort의 개선된 알고리즘 (2) 구현
 int lastSwapped = n;
 while(lastSwapped>0)
 {
     int swappedPos = 0;
     for(int i=0;i<lastSwapped-1;i++)
     {
         countCmpOps++;
         
         if(a[i] > a[i+1])
         {
             swap(&a[i], &a[i+1]);
             countSwaps++;
             swappedPos = i+1;
         }
         
     }
     lastSwapped = swappedPos;
    
     
 }
 printf("%d %d ", countCmpOps, countSwaps);
}
void copyArray(int a[], int b[], int n)
{
 for (int i = 0; i < n; i++)
 a[i] = b[i];
}