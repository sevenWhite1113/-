#include<iostream>
using namespace std;
int findMax(int arr[],int left,int right){
	if(left==right){
		return arr[left];
	}
	int mid=left+(right-left)/2;
	int leftMax=findMax(arr,left,mid);
	int rightMax=findMax(arr,mid+1,right);
	return leftMax>rightMax? leftMax:rightMax;
}
int recSum(int arr[],int n){
	if(n==0) return 0;
	return arr[n-1]+recSum(arr,n-1);
}
double recAvg(int arr,int n){
	if(n==0) return 0;
	return (double)recSum(arr,n)/n;
}
int main(){
	int arr[5]={1,4,2,87,9};
	int max=findMax(arr,0,4);
	double avg=recAvg(arr,4);
	cout<<max<<" "<<avg<<endl;
	return 0;
}