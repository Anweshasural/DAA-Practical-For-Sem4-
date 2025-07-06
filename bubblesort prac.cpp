//Bubble sort
#include<stdio.h>
#include<stdlib.h>
# define MAX 10
void bubblesort(int arr[],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
}
void insertionsort(int arr[],int size){
	int i,j,temp;
	for(i=0;i<size;i++){
		temp=arr[i];
		j=i-1;
		while((temp<arr[j])&&j>=0){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
		for(i=0;i<size;i++)
	printf("%d ",arr[i]);
}
//int smallest(int arr[],int k,int size){
//	int small=arr[k],i,pos=-1;
//	for(i=k+1;i<size;i++){
//		if(small>arr[i]){
//			small=arr[i];
//			pos=i;
//		}
//	}
//	return pos;
//}
//void selectionsort(int arr[],int size){
//	int k,pos,i,temp;
//	for(k=0;k<size;k++){
//	   pos=smallest(arr,k,size);
//	   temp=arr[k];
//	   arr[k]=arr[pos];
//	   arr[pos]=temp;
//	}
//		for(i=0;i<size;i++)
//	printf("%d ",arr[i]);
//}
int smallest(int arr[], int k, int size)
{
int pos = k, small=arr[k], i;
for(i=k+1;i<size;i++)
{
if(arr[i]< small)
{
small = arr[i];
pos = i;
}
}
return pos;
}
void selection_sort(int arr[],int size)
{
int k, pos, temp;
for(k=0;k<size;k++)
{
pos = smallest(arr, k, size);
temp = arr[k];
arr[k] = arr[pos];
arr[pos] = temp;
}
}
int main(){
	int arr[MAX],size,i;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	printf("Enter the elements");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	//bubblesort(arr,size);
	//insertionsort(arr,size);
//	selectionsort(arr,size);
selection_sort(arr,size);
for(i=0;i<size;i++)
printf(" %d\t", arr[i]);
	return 0;
}














