#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
	int data;
	int order;
	struct node* next;
}linked_list;
void* temp;
int main(int argc, char* argv[]) {
	linked_list node1 = { 0x00000212,1,NULL }, node2 = { 0x000001c2,2,NULL }, node3= { 0x00000215,3,NULL }, node4= { 0x00000393,4,NULL }, node5= { 0x000003a7,5,NULL }, node6= { 0x00000200,6,NULL };
	/*linking node together*/
	node1.next = &node2;	node2.next = &node3;	node3.next = &node4;	node4.next = &node5;	node5.next = &node6;	node6.next =NULL;
	temp = &node1;
	//phase 1 :
	char input[1024];
	//readline();
	scanf("%[^\n]s", input);
	getc(stdin);
	phase_1(input);
	 //solution :I am just a renegade hockey mom.
	phase_defused();
	printf("Phase 1 defused. How about the next one?\n");
	//phase 2:
	scanf("%[^\n]s", input);
	getc(stdin);
	phase_2(input);
//solutin:six numbers ,starting from one ,each one is the half of the next. (1,2,4,8,16,32)
	phase_defused();
	printf("Thats number 2 keep going !\n");


	//Phase 3:
	scanf("%[^\n]s", input);
	phase_3(input);
	//solution :0 602  ( or any number <=5 , with its corresponding switch cumulated value)
	phase_defused();
	printf("Halfway there!\n");

	//phase 4: 
	scanf("%[^\n]s", input);
	phase_4(input);
	////solution is 3 10 :
	phase_defused();
	printf("So you got that one.\tTry this one\n");;
	
	//phase 5:
	scanf("%[^\n]s", input);
	phase_5(input);
	//solution :5 115 (if you started at 5 , and after the loop finishes , the counter must equal 15  ,and the sum is equal to 115)
	//the script to solve this phase is commented below;
	phase_defused();
	printf("Good work!\tOn to the next...\n");
	//phase 6:
	scanf("%[^\n]s", input);
	phase_6(input);
	//soluiton :5 4 3 1 6 2
	phase_defused();
	printf("Congratulations! You defused the bomb!\n");
}
void phase_defused() {

}
void bomb_exploded() {
exit(1);
}
bool strings_not_equal(char* first, char* second) {
	while (*first != '\0') {
		if (*first != *second)
			bomb_exploded();
		first++;
		second++;
	}
}
void phase_1(char *passed) {
	char buff[] = "I am just a renegade hockey mom.";
		if (strlen(buff) != strlen(passed)) {
			bomb_exploded();
		}
		if (!strings_not_equal(passed, buff)) {
			return;
		}
		else {
			bomb_exploded();
		}
}
void read_six_numebrs(char* passed, int ar[]) {
	int a = sscanf(passed, "%d %d %d %d %d %d", &ar[0], &ar[1], &ar[2], &ar[3], &ar[4], &ar[5]);
	if (a != 6)
		bomb_exploded();
}
void phase_2(char *passed) {
	int ar[6];
	read_six_numbers(passed, ar);
	if (ar[0] != 1) {
		bomb_exploded();
	}
	for (int i = 1; i < 6; i++) {
		if (ar[i - 1] >> 1 != ar[i])
			bomb_exploded();
	}
	return;
}
void phase_3(char *input) {
	int x, y;
	int c = sscanf(input, "%d %d", &x, &y);
	if (c < 2) {
		bomb_exploded();
	}
	long compare = 0x0;
	switch (x) {
	case 0:
		compare += 0x274;
	case 1:
		compare -= 0x24c;
	case 2:
		compare += 0x2b0;
	case 3:
		compare -= 0x7e;
	case 4:
		compare += 0x7e;
	case 5:
		compare -= 0x7e;
	case 6:
		compare += 0x7e;
	case 7:
		compare -= 0x7e;
	default:
		bomb_exploded();
	}
	if (x > 5) {
		bomb_exploded();
	}
	if (y != compare) {
		bomb_exploded();
}

}
void phase_4(char* input) {
	int x, y;
	int returned = sscanf(input, "%d %d", &x, &y);
	if (returned != 2)
		bomb_exploded();
	if (x < 0 || x>14)
		bomb_exploded();
	if (phase_4_recursion(a, 0, 0xe) != 0xa || y != 0xa)
		bomb_exploded();
	return;
}
int phase_4_recursion(int a, int b, int c) {
	int z;
	z = b + ((c - b) >> 1);
	if (z > a) {
		return func4(a, b, z - 1) + z;
	}
	if (z < a) {
		return func4(a, z + 1, c) + z;
	}
	else {
		return z;
	}
}
void phase_5(char* input) {
	int ar[] = { 0xa,0x2,0xe,0x7,0x8,0xc,0xf,0xb,0x0,0x4,0x01,0xd,0x3,0x9,0x6,0x5 };
	int x, y;
	if (sscanf(input, "%d %d", &x, &y) < 2)
		bomb_exploded();
	x = x & 0xf;
	int counter = 0, accumelator = 0, checker = ar[x];
	while (checker!= 0xf) {
		counter += 1;
		accumelator += ar[i];
		checker = ar[checker];
	}
	if (counter != 15 || accumelator != 115)
		bomb_exploded();
	return;
}
void phase_6(char *input) {
	int ar[6];
	read_six_numebrs(input, ar);
	for (int i = 0; i < 6; i++) {
		if (ar[i] < 1 || ar[i]>6)
			bomb_exploded();
		for (int u = i + 1; u < 6; u++)
			if (ar[u] == ar[i])
				bomb_exploded();

	}

	linked_list* ar[6],
	for (int i = 0; i < 6; i++) {
		for (int u = 1; u <= ar[i]; u++)
			temp = temp->next;
		ar[i] = temp;
	}
	for (int i = 1; i < 6; i++) {
		temp->next = ar[i];
		temp = temp->next;
	}
	ar[5]->next = NULL;
	temp = ar[0];
	for (int i = 0; i < 6; i++) {
		if (temp->data < ar[i + 1]->next->data)
			bomb_exploded();
	
	}
	return;
}
//int main() {
// //script to solve phase_5;
//	int ar[] = { 0xa, 0x2, 0xe, 0x7, 0x8, 0xc, 0xf, 0xb, 0x0, 0x4, 0x01, 0xd, 0x3, 0x9, 0x6, 0x5 };
//	int i = 0;
//	int seq[15];
//	for (int i = 0; i < 14; i++)
//	{
//		int counter = 0;
//		int  next_shift = ar[i];
//		while (counter < 15)
//		{
//			seq[counter] = next_shift;
//			next_shift = *(ar + next_shift);
//			counter++;
//		}
//		if (seq[14] == 0xf) {
//			printf("found it at %d\n", i);
//			;
//
//			for (int s = 0; s < 15; s++)
//				printf("%x ", seq[s]);
//
//			printf("\n");
//		}
//	}

//}
