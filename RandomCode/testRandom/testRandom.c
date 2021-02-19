#include"list.h"
#include"stdio.h"
#include"stdlib.h"

/*gcc testRandom.c list.c element.c -o main*/

list charSelect(list listA, char k1, char k2){
	
	while(!empty(listA)){
		if((head(listA))>k1 && (head(listA)<k2)){
            return cons(head(listA), charSelect(tail(listA), k1, k2));
        }else
			return charSelect(tail(listA), k1, k2);
	}

	return NULL;

}

char Last(list listA){
	
	list temp = listA;

	while(temp -> next != NULL){
		temp = tail(temp);
	}
	
	return temp->value;
}


int main(void){

	list listA = emptyList();
	list temp;
	char c;
	c = 'a';
	cons(listA, c);
	c = 'b';
	cons(listA, c);
	c = 'c';
	cons(listA, c);
	c = 'd';
	cons(listA, c);

	printf("%c \n", head(listA));
	printf("%c \n", Last(listA));

	charSelect(listA, 'b', 'c');
	
	list temp = listA;
	while(temp -> next != NULL){
		printf("%c \n", head(listA));
		temp = tail(temp);
	}

}
