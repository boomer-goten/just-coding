#include <stdio.h>

int main () {
  int result = 0;
  int i = 1;
  int elem = 0;
  int flag;
  int num;
  int k = 1;
  scanf("%d", &num);
  int tmp = num / 10;
  while (tmp >= 1) {
      i++;
      tmp = tmp / 10;
  } 
  for (int j = 0; j < i; j++) {
  	int pst = 0;
  	k = k * 10;
    elem = (num % k);
    if (elem != 0) {
    	if ((k / elem) > 10) {
    		continue;
    	}
    }
    if (elem >= 10) {
       elem = (elem / (k / 10));
    }
    if (i == 1) {
    	result = elem;
    } else {
    	pst = elem;
    	for (int z = 2; z <= i; z++) {
    	pst = pst * elem;
    	}
    	result += pst;
    } 
  }
  if (result == num) {
    flag = 1;
  } else {
    flag = 0;
  }
  if (flag == 1) {
  	printf("good");
  } else {
  	printf("bad");
  }
  return 0;
}
