#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main() {

//Test empty queue
printf("=====Empty Dequeue=====\n");
Deq q=deq_new();
printf("Expected: ");
char *str = deq_str(q,0);
printf("\nQueue: %s\n",str); //Expected empty string
free(str);
printf("Queue Length: %d\n", deq_len(q)); //Expected 0

deq_del(q,0);

//Test head put functionality using a,b,c
printf("\n=====Test Head Put=====\n");
Deq hp = deq_new();
deq_head_put(hp, "a");
deq_head_put(hp, "b");
deq_head_put(hp, "c");

printf("Expected: c b a\n");
str = deq_str(hp, 0);
printf("Queue: %s\n",str); //Expected c b a
free(str);
printf("Queue Length: %d\n", deq_len(hp)); //Expected 3
deq_del(hp, 0);

//Test tail put functionality using a,b,c
printf("\n=====Test Tail Put=====\n");
Deq tp = deq_new();
deq_tail_put(tp, "a");
deq_tail_put(tp, "b");
deq_tail_put(tp, "c");

printf("Expected: a b c\n");
str = deq_str(tp, 0);
printf("Queue: %s\n",str); //Expected a b c
free(str);
printf("Queue Length: %d\n", deq_len(tp)); //Expected 3
deq_del(tp, 0);

//Test get on one element queue
printf("\n=====Test Get on 1 Element Queue=====\n");
Deq one = deq_new();
deq_tail_put(one, "only");

printf("Head get: %s\n", (char *)deq_head_get(one)); //Expected "only"
printf("Queue Length: %d\n", deq_len(one)); //Expected 0
deq_del(one, 0);

//Test both head and tail put
printf("\n=====Test Head & Tail Put=====\n");
Deq htp = deq_new();
deq_tail_put(htp, "a");
deq_head_put(htp, "b");
deq_tail_put(htp, "c");
deq_head_put(htp, "d");

printf("Expected: d b a c\n");
str = deq_str(htp, 0);
printf("Queue: %s\n",str); //Expected d b a c
free(str);
printf("Queue Length: %d\n", deq_len(htp)); //Expected 4
deq_del(htp, 0);

//Testing ith for both head and tail
printf("\n=====Test Head & Tail Ith=====\n");
Deq itp = deq_new();
deq_tail_put(itp, "a");
deq_tail_put(itp, "b");
deq_tail_put(itp, "c");
deq_tail_put(itp, "d");

str = deq_str(itp, 0);
printf("Queue: %s\n",str);
free(str);
printf("Head_ith(0): %s\n", (char*)deq_head_ith(itp,0)); // expected a
printf("Head_ith(4): %s\n", (char*)deq_head_ith(itp,3)); // expected d
printf("Tail_ith(0): %s\n", (char*)deq_tail_ith(itp,0)); // expected d
printf("Tail_ith(4): %s\n", (char*)deq_tail_ith(itp,3)); // expected a
printf("Queue Length: %d\n", deq_len(itp)); //Expected 4
deq_del(itp, 0);

//Testing get for both head and tail
printf("\n=====Test Head & Tail Get=====\n");
Deq gtp = deq_new();
deq_tail_put(gtp, "a");
deq_tail_put(gtp, "b");
deq_tail_put(gtp, "c");
deq_tail_put(gtp, "d");

str = deq_str(gtp, 0);
printf("Queue: %s\n",str);
free(str);
printf("Get Head: %s\n", (char*)deq_head_get(gtp)); // expected a
printf("Get Tail: %s\n", (char*)deq_tail_get(gtp)); // expected d

str = deq_str(gtp, 0);
printf("Queue: %s\n",str); //Expected b c
free(str);
printf("Queue Length: %d\n", deq_len(gtp)); //Expected 2

deq_del(gtp, 0);

//Testing remove for both head and tail
printf("\n=====Test Head & Tail Rem=====\n");
Deq rtp = deq_new();
//Save the pointers so rem can find them again
char *a="a", *b="b", *c="c", *d="d";
deq_tail_put(rtp, a);
deq_tail_put(rtp, b);
deq_tail_put(rtp, c);
deq_tail_put(rtp, d);

str = deq_str(rtp, 0);
printf("Queue: %s\n",str);
free(str);
printf("Expected Rem Middle: b\n");
printf("Actual: %s\n", (char*)deq_tail_rem(rtp, b)); //Queue is now: a c d
printf("\nExpected Rem Head: a\n");
printf("Actual: %s\n", (char*)deq_head_rem(rtp, a)); //Queue is now: c d
printf("\nExpected Rem Tail: d\n");
printf("Actual: %s\n", (char*)deq_tail_rem(rtp, d)); //Queue is now: c

printf("\nExpected Queue: c\n");
str = deq_str(rtp, 0);
printf("Queue: %s\n",str);
free(str);
printf("Queue Length: %d\n", deq_len(rtp));

deq_del(rtp,0);

printf("\n=====Rem on One Element Queue=====\n");
Deq oneRem = deq_new();
deq_tail_put(oneRem, "only");

printf("Rem only: %s\n", (char *)deq_head_rem(oneRem, "only"));//Expected "only"
printf("Length: %d\n", deq_len(oneRem)); //Expected 0
deq_del(oneRem, 0);


//Testing edge cases (should return 0, not crash)
printf("\n=====Test Edge Cases=====\n");

//Empty deque: get should return 0
Deq ep = deq_new();

printf("Get on Empty\n");
printf("Expected: (nil)\n");
printf("Actual: %p\n", deq_head_get(ep));

printf("\nLen on Empty\n");
printf("Expected: 0\n");
printf("Actual: %d\n", deq_len(ep));

deq_tail_put(ep, "only");

printf("\nNegative Ith\n");
printf("Expected: (nil)\n");
printf("Actual: %p\n", deq_head_ith(ep, -1));

printf("\nOut of Range Ith\n");
printf("Expected: (nil)\n");
printf("Actual: %p\n", deq_head_ith(ep, 5));

//Removing something not present should return 0
printf("\nRem Empty Queue\n");
printf("Expected: (nil)\n");
printf("Actual: %p\n", deq_head_rem(ep, "not present"));

printf("\nCheck Length\n");
printf("Expected: 1\n");
printf("Actual: %d\n", deq_len(ep));

deq_del(ep,0);
}