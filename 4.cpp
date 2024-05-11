#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 11
//����˼��ʵ�ְ�n���ؼ���  �� �ؼ���Ϊ��ֵ�ļ�¼���ڹؼ���Ϊ�Ǹ�ֵ�ļ�¼֮ǰ 
//ʱ�临�Ӷ�Ϊon�� 
typedef struct{
	int key;
}RecordType;

typedef struct{
	RecordType *r;
	int length;
}SqList;
void init(SqList *p){
	p->r=(RecordType *)malloc(MAX*sizeof(RecordType));
	if (p->r==NULL ) {
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	else
		printf("��ʼ���ɹ�\n");
	//�ڱ���ֵ 
	p->r[0].key=0;
	p->length=1;
}
void PrintList(SqList *l){
	for(int i=1;i<l->length;i++){
		
		printf("%d ",l->r[i].key);
	}
}
void CreateSqList(SqList *l,int arr[],int len){
	for(int i=1;i<len+1;i++){
		l->r[i].key=arr[i-1];
		l->length++;
	}
}

void SeparateInteger(SqList *l){
	int low=1,high=l->length;
	while(low<high){
		while(low<high&&l->r[high].key>=0)
			high--;
		while(low<high&&l->r[low].key<0)
			low++;
		l->r[0].key=l->r[high].key;
		l->r[high].key=l->r[low].key;
		l->r[low].key=l->r[0].key;
	}
}
int * creatArr(){
//	int a[10]={0};
//	srand((unsigned)time(NULL));
//    int aa;
//	for (int i = 0; i < 10; i++)
//	{
//		aa = rand() % 200 + 1;
//		a[i] = aa;
//	}
	int s[100],aa;
	int i;
	int count = 0;

	// ��ʱ�����²���
	srand((unsigned)time(NULL));

	for (i = 0; i < 100; i++)
	{
		if(i%2==0)
		    aa = rand()%200;
		else 
			aa= -(rand()%200);
		s[i] = aa;
	}

	return s;
}
int main(){
	SqList l;
	init(&l);
	int a[]={2,9,-4,-6,8,-5,3,13,-74,-1};
	int *arr=creatArr();
//	for(int i=0;i<10;i++){
//		printf("%d ",arr[i]);
//	}
    putchar('\n');
	int len=sizeof(a)/sizeof(a[0]);
	CreateSqList(&l,a,len);
	PrintList(&l);
	putchar('\n');
	SeparateInteger(&l);
	PrintList(&l);
	return 0;
}
