#include <stdio.h>
#include <malloc.h>
#include <string.h>

// typedef struct{
// 	char Chuoi;
// }Chuoi;



typedef char* ElementType; 
struct Node{
  ElementType Element;
  Node* Next; 
};

typedef Node* Position; 
typedef Position List;

void MAKENULL_LIST(List& Header){
	(Header)=(Node*)malloc(sizeof(Node));
	Header->Next= NULL;
}

int EMPTY_LIST(List L){
	return (L->Next==NULL);
}

ElementType RETRIEVE(Position P,List L){
	if (P->Next!=NULL)
		return P->Next->Element;
}

void INSERT_LIST(ElementType X, Position P, List& L){
	Position T=(Node*)malloc(sizeof(Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}

void INSERT_ORDERED_LIST(ElementType X, List& L){
	Position P = L;
	while(P->Next !=NULL){
		if(strcmp(X, RETRIEVE(P,L)) <= 0)
			break;
		P = P -> Next;
	}
	INSERT_LIST(X,P,L);
}

void DELETE_LIST(Position P, List& L){
	Position T;
	if (P->Next!=NULL){
		T=P->Next; 
		P->Next=T->Next;
		free(T); 
	}
}

void DELETE_ORDERED_LIST(ElementType X, List& L){
		Position P = L;
		while(P -> Next !=NULL){
			if(strcmp(X,RETRIEVE(P,L)) == 0)
				break;
			P++;
		}
		DELETE_LIST(P,L);
}

void READ_LIST(List& L){
	int n;
	ElementType x;
	Position c = L; 
	printf(" Nhap so phan tu cua danh sach? ");
	scanf(" %d",&n);
//  	fflush(stdin);
  
	for(int i=1; i<=n; i++){
		printf(" Nhap phan tu thu %d : ",i);
		fflush(stdin);
    	char str[200];
		fgets(str, 200, stdin);
    	ElementType x = strdup(str);
		INSERT_LIST(x,c,L);
		c = c->Next;
	}
}

void READ__REV_LIST(List& L){
	int n;
	ElementType x;
	printf(" Nhap so phan tu cua danh sach? ");
	scanf(" %d",&n);
	for(int i=1; i<=n; i++){
		printf(" Nhap phan tu thu %d : ",i);
		fflush(stdin);
    	char str[200];
		fgets(str, 200, stdin);
    	ElementType x = strdup(str);
		INSERT_LIST(x,L,L);
	}
}

void PRINT_LIST(List L){
    Position p = L;
	while (p->Next !=NULL){
		printf(" %s ", RETRIEVE(p,L));
        p = p->Next; 
    }
//	printf("\n\n");
}

void SWAP (Position P, Position Q){
	ElementType t = P->Next->Element;
	P->Next->Element = Q->Next->Element;
	Q->Next->Element = t;
}

void SORT(List& L){
	Position P = L;
	while(P->Next !=NULL){
		Position Q = P->Next;
		while(Q->Next !=NULL){
			if(strcmp(P->Next->Element,RETRIEVE(Q,L)) > 0)
				SWAP(P,Q);
			Q = Q->Next ;
		}
		P = P->Next;
	}
}

int main(){
	List list;

	MAKENULL_LIST(list);
	READ_LIST(list);
	PRINT_LIST(list);
	return 0;
}










