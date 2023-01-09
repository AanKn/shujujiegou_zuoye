# include <stdio.h>
typedef struct{
	int key;
	int otherinfo;
}ElemType;
typedef struct{
	ElemType *R;
	int length;
}SSTable;
int Search_Seq(SSTable ST, int key){
	for(int i=ST.length;i>=1;--i){
		if(ST.R[i].key==key){
		printf("%d���±�Ϊ%d\n",key,i);
		return i;
		}
	}
	printf("�Ҳ���%d\n",key);
	return -1;	 
} 
int Search_Bin(SSTable ST,int Key){
	int low=1;
	int high=ST.length;
	while(low<=high){
		int mid=(low+high)/2;
		if(Key==ST.R[mid].key){
			printf("%d���±�Ϊ%d\n",Key,mid);
			return mid;
		}
		else if(Key<ST.R[mid].key)high=mid-1;
		else low=mid+1;
	}
	printf("�Ҳ���%d\n",Key);
	return -1;
} 
ElemType elem[5]={{1},{3},{5},{7},{9}} ;
SSTable st={elem,5};
int main(){
	printf("˳����ң�\n");
	Search_Seq(st,3);
	Search_Seq(st,6);
	printf("���ֲ��ң�\n");
	Search_Bin(st,3);
	Search_Bin(st,6);
}
