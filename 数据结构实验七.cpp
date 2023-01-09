#include<stdio.h>

void InsertSort(int a[],int n){
	int j;
	int count=0;
	for (int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			a[0]=a[i];
			a[i]=a[i-1];
			count++;
			for(j=i-2;a[0]<a[j];j--){
				a[j+1]=a[j];
				count++; 
			}
			a[j+1]=a[0];
		}
	}
	printf("直接插入排序一共比较了%d次\n",count);
}
void BubbleSort(int a[],int n){
	int count=0;
	int m=n-1;
	int flag=1;
	while ((m>0)&&(flag==1)){
		flag=0;
		for(int j=1;j<=m;j++){
			if(a[j]>a[j+1]){
				flag=1;
				count++; 
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		count++;
		m--;
	}
	printf("冒泡排序一共比较了%d次\n",count);
}
void SelectSort(int a[],int n){
	int count=0;
	for(int i=1;i<=n;i++){
		int k=i;
		count++;
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[k]){
				k=j;
				count++;
			}
		}
		if(i!=k){
			count++;
			int t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
	printf("直接选择排序一共比较了%d次\n",count);
}
int main(){
	int a[]={0,23,12,1,3,8,78,99,56};
	BubbleSort(a,8);
	int b[]={0,23,12,1,3,8,78,99,56};
	InsertSort(b,8);
	int c[]={0,23,12,1,3,8,78,99,56};
	SelectSort(c,8);
	printf("排序后的结果为：");
	for(int i=1;i<8;i++){
		printf("%d ",a[i]);
	}
}



