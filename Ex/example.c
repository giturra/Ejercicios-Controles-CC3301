#include <stdio.h>
#include <string.h>

int priority[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int checkMajorPriority(int p) {
  for(int i = p + 1; i < 10; ++i) {
    if (priority[i] > 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
	printf("%d\n", checkMajorPriority(1));
	return 0;
}