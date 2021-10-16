#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

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

void INSERT_LIST(ElementType X, Position P, List& L){
	Position T=(Node*)malloc(sizeof(Node));
	T->Element=strdup(X);
	T->Next=P->Next;
	P->Next=T;
}
void DELETE_LIST (Position P, List& L){
	Position T;
	if(P->Next!=NULL){
		T=P->Next;
		P->Next=T->Next;
		free(T);
	}
}
Position LOCATE (ElementType X, List L){
	Position P=L;
	while (P->Next != NULL)
		if (strcmp(P->Next->Element, X) == 0) break;
		else P = P->Next;
	return P;
}

ElementType RETRIEVE (Position P, List L){
	if (P->Next != NULL)
		return P->Next->Element;
}


//Cau2a
void READ_LIST(List& L){
	int n;
	char x[255];
	Position  P= L;
	printf("How many words are in list: ");
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		printf("Enter the words %d: ",i);
		fflush(stdin);
		fgets(x, sizeof(x), stdin);
		INSERT_LIST(x, P, L);
		P = P->Next;
	}
}

//Cau2b
void READ_REVERSE_LIST(List& L){
	int n;
	char x[255];
	printf("How many words are in list: ");
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		printf("Enter the words %d: ",i);
		fflush(stdin);
		fgets(x, sizeof(x), stdin);
		INSERT_LIST(x, L, L);
	}
}

//Cau2c
void PRINT_LIST (List& L){
	Position P=L;
	while (P->Next != NULL){
		printf("%s ", RETRIEVE (P,L));
		P=P->Next;
	}
	printf("\n");
}

//3b
void SWAP (Position P, Position Q){
	ElementType T = strdup(P->Next->Element);
	P->Next->Element = strdup(Q->Next->Element);
	Q->Next->Element = strdup(T);
}
void SORT (List& L){
	Position P= L;
	while (P->Next!=NULL){
		Position Q = P->Next;
		while (Q->Next!=NULL){
			if (strcmp(RETRIEVE(P,L), RETRIEVE(Q,L)) > 0)
				SWAP (P,Q);
			Q=Q->Next;
		}
		P=P->Next;
	}
}

//Cau4
void INSERT_ORDERED_LIST (ElementType x, List& L){
	Position P=L;
	while (P->Next!=NULL){
		if (strcmp(P->Next->Element,x) >= 0)
			break;
		P=P->Next;
	}
	INSERT_LIST(x,P,L);
}
void INPUTNAME (ElementType X, List& L){
	char x[255];
	printf("Input the words to insert list: ");
	fflush(stdin);
	fgets(x,sizeof(x),stdin);
	INSERT_ORDERED_LIST(x,L);
	printf("After inserting %s: \n ", x);
	PRINT_LIST(L);
}

//Cau5
void DELETE_ORDERED(ElementType x, List& L){
	Position P=L;
	while (P->Next!=NULL){
		if (strcmp(P->Next->Element,x) >= 0)
			break;
		P=P->Next;
	}
	if (strcmp(P->Next->Element,x) == 0)
		DELETE_LIST(P,L);
}
void DELETENAME(ElementType X, List& L){
	char x[255];
	printf("Input the words to delete list: ");
	fflush(stdin);
	fgets(x,sizeof(x),stdin);
	DELETE_ORDERED (x, L);
	printf("After deleting %s: \n ", x);
	PRINT_LIST(L);
}

//Cau6
void READ_ORDER_LIST(List& L){
	int n;
	char x[255];
	printf("How many words are in list: ");
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		printf("Enter the words %d: ",i);
		fflush(stdin);
		fgets(x,sizeof(x),stdin);
		INSERT_ORDERED_LIST(x, L);
	}
}

//Cau7
void EXCEPT_LIST (List& L){
	Position P=L;
	while (P->Next!=NULL){
		Position Q=P->Next;
		while ((Q->Next!=NULL)&& (strcmp(RETRIEVE (Q,L), RETRIEVE (P,L)) == 0))
			DELETE_LIST (Q,L);
		P=P->Next;
	}
}

int main(){
	List L1, L2;
	ElementType X;
	Position P;
	 
	MAKENULL_LIST (L1);   //Cau2a
	READ_LIST(L1);
	printf("Words list: ");
	PRINT_LIST (L1); 
	
	MAKENULL_LIST(L2);
	READ_REVERSE_LIST(L2);   //Cau2b
	printf("Words list : ");
	PRINT_LIST(L2); //Cau2c
	
	SORT (L2);  //Cau3b
	printf("Words list after sorting:\n ");
	PRINT_LIST(L2);
	
	INPUTNAME (X,L2);   //Cau4
	DELETENAME (X,L2);   //Cau5
	
	MAKENULL_LIST(L2);    //Cau6
	READ_ORDER_LIST(L2);
	printf("Words list:\n ");
	PRINT_LIST(L2);
	
	printf("Words list after excepting:\n ");  //Cau7
	EXCEPT_LIST (L2);
	PRINT_LIST(L2);
	
	return 0;
}
