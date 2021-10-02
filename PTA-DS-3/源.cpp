#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;

struct PolyNode {
	int coef;
	int expon;
	struct PolyNode* next;
};

Polynomial Create();
void Print(Polynomial p);

Polynomial Muti2(Polynomial p1, Polynomial p2);
Polynomial Add2(Polynomial p1, Polynomial p2);
Polynomial Attach(int coef, int expon, Polynomial p, Polynomial head);

int main() {
	Polynomial p1, p2, p3, p4;
	p1 = Create();
	p2 = Create();
	//	Print(p1);
	//	Print(p2);
	//	printf("Mutiplication:\n");
	p3 = Muti2(p1, p2);
	Print(p3);
	printf("\n");
	//	printf("Addition:\n");
	p4 = Add2(p1, p2);
	Print(p4);

	return 0;
}

Polynomial Create() {
	Polynomial p, temp, head;
	head = (Polynomial)malloc(sizeof(struct PolyNode));
	head->next = NULL;
	p = head;

	int cnt;
	scanf("%d", &cnt);
	while (cnt) {
		temp = (Polynomial)malloc(sizeof(struct PolyNode));
		int coef, expon;
		scanf("%d", &coef);
		scanf("%d", &expon);
		temp->coef = coef;
		temp->expon = expon;
		temp->next = NULL;
		p->next = temp;
		p = temp;
		cnt--;
	}

	return head;
}

void Print(Polynomial p) {

	p = p->next;
	if (p == NULL)
		printf("0 0");
	//	printf("Polynomial: ");
	for (; p; p = p->next) {
		printf("%d", p->coef);
		printf(" ");
		printf("%d", p->expon);
		if (p->next == NULL)
			break;
		printf(" ");
	}
}


//v2
Polynomial Muti2(Polynomial p1, Polynomial p2) {
	Polynomial p3, head, temp, headOfP1, headOfP2;
	headOfP1 = p1;
	headOfP2 = p2;
	int coef, expon;
	head = (Polynomial)malloc(sizeof(struct PolyNode));
	head->next = NULL;
	p3 = head;
	int flag = 0;

	for (p1 = p1->next; p1; p1 = p1->next) {
		p2 = headOfP2;
		for (p2 = p2->next; p2; p2 = p2->next) {
			coef = p1->coef * p2->coef;
			expon = p1->expon + p2->expon;
			p3 = Attach(coef, expon, p3, head);
			//			printf("mul: ");
			//			Print(head);  //debug
			//			printf("\n");
		}

	}
	p1 = headOfP1;
	p2 = headOfP2;
	return head;
}

Polynomial Add2(Polynomial p1, Polynomial p2) {
	Polynomial p3, head, temp, headOfP1, headOfP2;
	headOfP1 = p1;
	headOfP2 = p2;
	int coef, expon;
	head = (Polynomial)malloc(sizeof(struct PolyNode));
	head->next = NULL;
	p3 = head;
	int flag = 0;

	for (p1 = p1->next; p1; p1 = p1->next) {
		coef = p1->coef;
		expon = p1->expon;
		p3 = Attach(coef, expon, p3, head);
		//		printf("add: ");
		//		Print(head);  //debug
		//		printf("\n");
	}

	for (p2 = p2->next; p2; p2 = p2->next) {
		coef = p2->coef;
		expon = p2->expon;
		p3 = Attach(coef, expon, p3, head);
		//		printf("add: ");
		//		Print(head);  //debug
		//		printf("\n");
	}


	p1 = headOfP1;
	p2 = headOfP2;
	return head;
}

Polynomial Attach(int coef, int expon, Polynomial p, Polynomial head) {
	Polynomial temp;

	if (coef == 0)
		return p;
	if (p == head) {
		temp = (Polynomial)malloc(sizeof(struct PolyNode));
		temp->coef = coef;
		temp->expon = expon;
		temp->next = NULL;
		p->next = temp;
		p = temp;
		return p;
	}
	if (expon < p->expon) {
		temp = (Polynomial)malloc(sizeof(struct PolyNode));
		temp->coef = coef;
		temp->expon = expon;
		temp->next = NULL;
		p->next = temp;
		p = temp;
	}
	else if (expon == p->expon) {
		p->coef += coef;
		if (p->coef == 0) {
			if (head->next->next == NULL) { //only one in chain
				temp = p;
				head->next = NULL;
				free(temp);
				p = head;
			}
			else {
				Polynomial t;
				for (t = head->next; t, t->next != p; t = t->next);
				temp = p;
				t->next = NULL;
				free(temp);
				p = t;
			}
		}
	}
	else {
		//		printf("coef= %d, expon= %d\n", coef, expon);
		Polynomial t;
		for (t = head; t->next->expon > expon; t = t->next);
		if (t->next->expon < expon) {
			temp = (Polynomial)malloc(sizeof(struct PolyNode));
			temp->coef = coef;
			temp->expon = expon;
			temp->next = t->next;
			t->next = temp;
		}
		else if (t->next->expon == expon) {
			t->next->coef += coef;
			if (t->next->coef == 0) {
				temp = t->next;
				t->next = temp->next;
				free(temp);
			}
		}
	}
	return p;
}